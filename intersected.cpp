/*
struct Interval {
    int start;   //区间左端点
    int end;   //区间右端点
};
*/

// intervals包含n个区间
// 结果存放到isIntersected中(已分配空间,不需要push_back)
// isIntersected[i]表示第i个区间是否与其它区间相交

struct compare_int {
    bool operator() (Interval* p1, Interval* p2) {
        if (p1->start == p2->start) {
            return (p1->end < p2->end);
        }
        else
            return (p1->start < p2->start);
    }
} my_compare;

void intersected(vector<Interval> &intervals, vector<bool> &isIntersected) {
	int beg = 0, n = intervals.size();
	vector<Interval*> index(n,(Interval*)NULL);
	Interval *p = &(intervals[0]);
	for(int i = 0;i < n;i++) index[i] = &(intervals[i]);
	sort(index.begin(),index.end(),my_compare);
	while(beg < n)
	{
		int pos = beg + 1,maxend = index[beg]->end;
		while(pos < n && index[pos]->start <= maxend)
		{
			isIntersected[index[beg] - p] = true;
			isIntersected[index[pos] - p] = true;
			if(maxend < index[pos]->end) maxend = index[pos]->end;
			pos++;
		}
		beg = pos;
	}
}