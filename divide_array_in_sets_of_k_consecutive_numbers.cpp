class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) 
    {
        /*
        1) We form a map storing the frequency of each element. Note that we use normal map
        here and not underordered map since the normal map stores keys in the sorted order
        2) At each time, the starting key in the map will always be the minimum. So we will try to find the next k elements
        starting from this key. While traversing we decrement the frequency of the key and if at any case , a key is not found then 
        we return false. We return true when all the keys are found and the map becomes empty.
        */
        int n = nums.size();
        if(n%k != 0)
        return false;
        map<int,int> mp;
        for(int i=0;i<n;i++)
        mp[nums[i]]++;

        auto it=mp.begin();
        int temp;
        while(mp.size()!=0)
        {
            // try to find the first k element starting from the least element stored at the beginning of the map.
            it = mp.begin();
            temp = it->first;
            for(int i=0;i<k;i++)
            {
                if(mp.find(temp)!=mp.end())
                {
                    mp[temp]--;
                    if(mp[temp] == 0)
                    mp.erase(temp);
                    temp = temp+1;
                }
                else
                return false;
            }
        }
        return true;
    }
};
