class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int n = bills.size();
        int c5=0; // count of 5 denominations
        int c10=0; // count of 10 denominations
        // we do not require count of 20 denominations any way since we have no use of it

        for(int i=0;i<n;i++)
        {
            if(bills[i]==5)
            c5++; // we do not require to return any change if the bill is 5
            else if(bills[i]==10)
            {
                // we need to return a 5 denomination
                if(c5==0)
                return false;
                c10++;
                c5--;
            }
            else 
            {
                /*
                for 20 we need to return 3 five denominations of (one 10 + one 5 denomination)
                */
                if(c10>0 and c5>0)
                {
                    // its better to eliminate the 10's first than 5's
                    c10--;
                    c5--;
                }
                else if(c5>=3)
                {
                    c5 = c5-3;
                }
                else
                return false;
            }
        }
        return true;
    }
};
