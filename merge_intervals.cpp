class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        int i=0;
        // sort based on the starting values
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int j; // used to iterate on overlapping intervals
        int maximum,minimum;
        while(i<n)
        {
            /*
            1) In each case we will check the number of overlapping intervals in the range [i+1,n] overlapping with interval i
            2) Once we find the overlapped intervals, push the minimum and maximum into ans
            */
            minimum = intervals[i][0];
            maximum = intervals[i][1];
            for(j=i+1;j<n;j++)
            {
                if(intervals[j][0]<=maximum)
                maximum = max(maximum,intervals[j][1]);
                else
                break;
            }
            i=j;
            vector<int> temp;
            temp.push_back(minimum);
            temp.push_back(maximum);
            ans.push_back(temp);
        }
        return ans;
    }
};
