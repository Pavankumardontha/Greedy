class Solution {
public:
    string reorganizeString(string s) 
    {
        /*
        1) if frequency of any character is more than half of the length of the string
        then we will not have any solution.
        2) Place the element with the max frequency first at index starting from 0
        and then 2 and then 4. 
        3) Place the rest of the elements in the left over positions that is 1,3,5..
        */
        int n = s.length();
        int freq[26]={0}; // used to store the frequency of each character
        int k;
        char c;
        for(int i=0;i<n;i++)
        {
            k = s[i]-'a';
            freq[k]++;
            if(freq[k]>ceil(1.0*n/2))
            return "";
        }
        priority_queue<pair<int,char>> pq; // max heap sorted by frequency
        for(int i=0;i<26;i++)
        {
            if(freq[i] != 0)
            {
                char c = 'a'+i;
                pq.push(make_pair(freq[i],c));
            }
        }
        string ans = s; // we will initial the ans with s but we will change ans string
        int ind=-2;
        while(!pq.empty())
        {
            pair<int,char> temp = pq.top();
            pq.pop();
            for(int i=0;i<temp.first;i++)
            {
                if(ind+2<n)
                ind = ind+2;
                else
                ind = 1;
                ans[ind] = temp.second; 
            }
        }
        return ans;
    }
};
