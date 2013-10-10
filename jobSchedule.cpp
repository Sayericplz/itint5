typedef int JobID;

/*
 * deps[id]表示任务id所依赖的任务
 * 如果存在合法的任务完成序列，返回true，否则返回false
 * 合法的任务序列请存放在参数result中（已经分配空间，不需要push_back）
 */
bool jobSchedule(const map<JobID, vector<JobID> > &deps, int n,
                                   vector<JobID> &result) {
    int start = 0,end = 0;
    int *flag = new int[n+1]; 
    for(int i = 1;i <= n;i++) flag[i] = 0;
    map<JobID, vector<JobID> > newdeps;
    for(map<JobID, vector<JobID> >::const_iterator it = deps.begin();it != deps.end();it++)
    {
    	const vector<int> &tmp = it->second;
    	for(int i = 0; i < tmp.size();i++)
    	{
	    	if(newdeps.find(tmp[i]) == newdeps.end()) newdeps[tmp[i]] = vector<int>();
	    	newdeps[tmp[i]].push_back(it->first);
	    	flag[it->first]++;
    	}
    }
    for(int i = 1;i <= n;i++)
    {
    	if(!flag[i])
    		result[end++] = i;
    }
    while(end < n)
    {
    	int newend = end;
    	for(int i = start; i < end;i++)
    	{
    		if(newdeps.find(result[i]) != newdeps.end())
    		{
    			for(int j = 0;j < newdeps[result[i]].size();j++)
    			{
    				int tmp = newdeps[result[i]][j];
    				if(--flag[tmp] == 0) result[newend++] = tmp;
    			}
    		}
    	}
    	if(newend == end) return false;
    	start = end;
    	end = newend;
    }
    return true;
}