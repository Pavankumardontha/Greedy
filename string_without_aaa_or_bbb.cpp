class Solution {
public:
    string strWithout3a3b(int a, int b) 
    {
         /*
        At each step we will have 2 possible situations
        1) if the last character is 'a' 
            a) if the last character is taken twice -> we need to take 'b'
            b) if the last character is not taken twice -> we can either take 'a' or 'b'. If the count of 'a' is more take 'a' if not 'b'
        2) if the last character is 'b'
            a) if the last character is taken twice -> we need to take 'a'
            b) if the last character is not taken twice -> we can either take 'a' or 'b'. if the count of 'a' is more taken 'a' if not 'b'
        */
        string ans="";
        int c1 = a; // count of 'a'
        int c2 = b; // count of 'b'
        char last_char='X';
        bool is_last_char_taken_twice=false;
        if(c1>c2)
        {
            last_char = 'a';
            c1--;
            ans=ans+'a';
        }
        else
        {
            last_char='b';
            c2--;
            ans=ans+'b';
        }
        while(c1>0 or c2>0)
        {
            if(last_char=='a')
            {
                if(is_last_char_taken_twice == true)
                {
                    ans = ans + 'b';
                    c2--;
                    last_char = 'b';
                    is_last_char_taken_twice = false;
                }
                else
                {
                    // we can either take a or b. 
                    if(c1>c2)
                    {
                        ans = ans + 'a';
                        c1--;
                        last_char = 'a';
                        is_last_char_taken_twice = true;
                    }
                    else
                    {
                        // take 1 'b'
                        ans = ans + 'b';
                        c2--;
                        last_char='b';
                        is_last_char_taken_twice = false;
                    }
                }
            }
            else
            {
                // last character is 'b' here
                if(is_last_char_taken_twice == true)
                {
                    // we need to take 'a' here no choice
                    ans = ans + 'a';
                    c1--;
                    last_char='a';
                    is_last_char_taken_twice=false;
                }
                else
                {
                    // we can either take 'b' or 'a'
                    if(c2>c1)
                    {
                        // take b
                        ans = ans + 'b';
                        c2--;
                        last_char='b';
                        is_last_char_taken_twice=true;
                    }
                    else
                    {
                        // take a
                        ans = ans + 'a';
                        c1--;
                        last_char='a';
                        is_last_char_taken_twice=false;
                    }
                }
            }
        }
        return ans;
    }
};
