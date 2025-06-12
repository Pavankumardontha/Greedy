class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) 
    {
        /*
        1) sort nums1.
        2) store the index of each element in nums2 and then sort nums2 in ascending order. We need a map of (int,queue) because we can have 
        repeated elements. So we store the indices of the same element in a queue.
        3) sort nums2 
        4) Start finding the first element in nums1 which is greater than nums2 for each element in nums2.
        */

        int n = nums1.size();
        sort(nums1.begin(),nums1.end());
        // before sorting store the indices of elements in nums2
        unordered_map<int,queue<int>> mp;
        for(int i=0;i<nums2.size();i++)
        mp[nums2[i]].push(i);

        sort(nums2.begin(),nums2.end());
        queue<int> unused_numbers; // ununsed numbers in nums1
        int i=0;
        int j=0;
        int ind;
        vector<int> ans(n,-1);
        while(i<n and j<n)
        {
            if(nums1[i]>nums2[j])
            {
                // take out the actual index of nums2[j]
                ind = mp[nums2[j]].front();
                mp[nums2[j]].pop();
                ans[ind] = nums1[i];
                i++;
                j++;
            }
            else
            {
                // the nums1[i] will be unused and not be mapped to any element in nums2
                unused_numbers.push(nums1[i]);
                i++;
            }
        }

        // assign unused integers in nums1 to the rest of numbers in nums2
        while(j<n)
        {
            ind = mp[nums2[j]].front();
            mp[nums2[j]].pop();
            ans[ind] = unused_numbers.front();
            unused_numbers.pop();
            j++;
        }
        return ans;
    }
};
