class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        /*
        1) find the last occurance of each character.
        2) initially we will at index 0. find the last occurance index of the character
        at index 0, let it be j.
        3) if j==n-1 , then we cannot devide the string as per the given conditions.
        4) we need to take all the characters from range [0,j] for sure. So if any 
        character present in the range [0,j] has the last index greater than j, say k,
        then we need to take the characters from [0,k]. So the range keeps on increasing
        if the characters in the range has a last occurrance index much greater than the
        bound of the range.
        */
        int n = s.length();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        mp[s[i]]=i;
        
        int start=0; // starting index from which we take the elements
        int end; // ending index till which we take the characters and break the string
        int l=0; // count of characters in the range [start,end]
        while(start<n)
        {
            l=0;
            end = mp[s[start]];
            for(int i=start;i<=end;i++)
            {
                end = max(end,mp[s[i]]);
                l++;
            }
            ans.push_back(l); // length of the string from start to end
            start=end+1;
        }
        return ans;
    }
};
