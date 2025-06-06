class Solution {
public:
    int minSetSize(vector<int>& a) 
    {
        /* remove the elements with higher frequency first */
        int n = a.size();
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++)
        mp[a[i]]++;
        pair<int,int> temp;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            // we will keep frequency as the first element in the priority queue since it will be sort by that
            temp.first = it->second;
            temp.second = it->first;
            pq.push(temp);
        }
        int element;
        int freq;
        int removed_elements = 0;
        int final_size;
        int ans=0;
        while(!pq.empty())
        {
            temp = pq.top();
            pq.pop();
            removed_elements = removed_elements + temp.first;
            final_size = n-removed_elements;
            ans++;
            if(final_size<=n/2)
            break; 
        }
        return ans;
    }
};
