#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

struct Interval
{
	int start, end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
	{
		int size = intervals.size();
		if (size == 0)
			return vector<Interval>(1, newInterval);

		int s = newInterval.start;
		int e = newInterval.end;
		int p1 = search(intervals, s);
		int p2 = search(intervals, e);

		if (p1 >= 0 && intervals[p1].end >= s)
			newInterval.start = intervals[p1].start;
		else
			p1++;

		if (p2 >= 0 && intervals[p2].end > e)
			newInterval.end = intervals[p2].end;

		int n = p1 + size - p2;

		vector<Interval> ret(n);
		vector<Interval>::iterator it = ret.begin();
		copy(ret, intervals, 0, 0, p1);
		ret[p1] = newInterval;
		copy(ret, intervals, p1+1, p2+1, n);
		return ret;
	}

private:
	int search(vector<Interval> &intervals, int target)
	{
		int low = 0, high = intervals.size() - 1;
		int mid;

		while (low <= high)
		{
			mid = (low + high) >> 1;
			if (intervals[mid].start == target)
				return mid;
			else if (intervals[mid].start > target)
				high = mid - 1;
			else
				low = mid + 1;
		}

		if (intervals[mid].start > target)
			mid--;

		return mid;
	}

	void copy(vector<Interval> &dst, vector<Interval> &src, int i, int j, int end)
	{
		for (; i < end; i++, j++)
			dst[i] = src[j];
	}
};

#endif