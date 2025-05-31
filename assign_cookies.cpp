class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        /*
        we will assign the closest element in size array which is greater than or equal to the greed of a child.
        sort both the arrays and assign accordingly
        */
        int n1 = g.size();
        int n2 = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i = 0;
        int j = 0;
        int ans = 0;
        while(i<n1 and j<n2)
        {
            if(s[j]>=g[i])
            {
                i++;
                j++;
                ans++;
                // ith child with greedy g[i] is assigned a cookie with size s[j] which is greater than or equal to g[i]
            }
            else
            j++;
        }
        return ans;
    }
};
