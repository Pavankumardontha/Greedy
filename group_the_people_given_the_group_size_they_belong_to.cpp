class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
        int n = groupSizes.size();
        unordered_map<int,vector<int>> mp;
        vector<vector<int>> ans;
        int size;
        for(int i=0;i<n;i++)
        {
            size = groupSizes[i];
            mp[size].push_back(i);
            if(mp[size].size() == size)
            {
                ans.push_back(mp[size]);
                mp[size].clear();
            }
        }
        return ans;
    }
};
