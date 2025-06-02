class Solution {
public:
    int minCostToMoveChips(vector<int>& position) 
    {
        /*
        The possible positions to move all the chips to one place can be the positions where the chips already
        exist. So we try out each position and find the cost to move all the chips to that position. We then take
        the minimum cost. 
        */
        int n = position.size();
        int minimum_cost = INT_MAX;
        for(int i=0;i<n;i++)
        {
            int final_position= position[i]; // we want to move all the chips to this position
            int total_cost = 0; // total cost to move all the elements to final_position
            for(int j=0;j<n;j++)
            {
                int k = abs(position[j] - final_position);
                total_cost = total_cost + k%2;
            }
            minimum_cost = min(minimum_cost,total_cost);
        }
        return minimum_cost;
    }
};
