class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) 
    {
        /*
        1 cheese -> 4 tomato
        n cheese -> 4n tomatoes
        so if no. of tamatoes > 4 * no. of cheeseSlices -> answer not possible
        1) if tamatoSlices is odd , then also answer is not possible
        2) if there are more cheeseSlices than tomatoSlices
        */
        vector<int> ans;
        // edge case
        if(tomatoSlices==0 and cheeseSlices==0)
        {
            ans.push_back(0);
            ans.push_back(0);
            return ans;
        }
        if(tomatoSlices > 4*cheeseSlices or tomatoSlices%2==1 or cheeseSlices>=tomatoSlices)
        return ans;
        else
        {
            /* we need to check if the answer is possible or not
            1) We need to create jumbo burgers if the available tomatoSlices/CheeseSlices ratio is greater than 2 to decrease the ratio to 2.
            2) Once the ratio reaches 2 , we need to make all small burgers.
            In this way, we optimally use all the available resources as much as possible.
            */
            double f; 
            int small_burger_count = 0;
            int jumbo_burger_count = 0;
            while(tomatoSlices>0 and cheeseSlices>0)
            {
                f = (double)tomatoSlices/cheeseSlices;
                if(f>2)
                {
                    // make jumbo burger in this case
                    tomatoSlices = tomatoSlices - 4;
                    cheeseSlices = cheeseSlices - 1;
                    jumbo_burger_count++;
                }
                else
                {
                    // make small burger in this case
                    tomatoSlices = tomatoSlices - 2;
                    cheeseSlices = cheeseSlices - 1;
                    small_burger_count++;
                }
            }
            if(tomatoSlices==0 and cheeseSlices==0)
            {
                ans.push_back(jumbo_burger_count);
                ans.push_back(small_burger_count);
            }
            return ans;
        }
    }
};
