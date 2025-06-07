class Solution {
public:
    string smallestSubsequence(string s) 
    {
        int n = s.length();
        unordered_map<char,int> last_index; 
        bool is_already_pushed[26]={false};
        for(int i=0;i<n;i++)
        last_index[s[i]]=i;
        stack<char> st;
        int k;
        char temp;
        for(int i=0;i<n;i++)
        {
            k = s[i]-'a';
            if(is_already_pushed[k])
            continue;
            else
            {
                while(!st.empty())
                {
                    temp = st.top();
                    if(s[i]<temp and last_index[temp]>i)
                    {
                        k = temp - 'a';
                        st.pop();
                        is_already_pushed[k]=false;
                    }
                    else
                    break;
                }
                st.push(s[i]);
                k = s[i]-'a';
                is_already_pushed[k]=true;
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans = ans + st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
