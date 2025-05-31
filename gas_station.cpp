class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        /*
        1) starting can only be at points where gas[i]-cost[i]>=0. The most optimal is the ith index which has gas[i]-cost[i] has the highest
        2) if sum(gas) < sum(cost) then we can no longer have a solution to this.
        Lets say we start at 0th index. We keep on adding the value (gas[i]-cost[i]) at each index to some variable say x.
        The moment x becomes negative at some index j, then it means we can no longer start from any indexes in the range [0,j]
        THe next option to start is j+1.

        Think of how this is possible. Lets take an example
        gas = [1,2,3,4,5] cost = [3,4,5,1,2]
        Initially val = 0
        1st iteration: val = val + g[i] - cost[i] = 0+(1-3)
        here val is negative so we cannot start from 0th index so we assume the next index to start is i+1 = 0+1 = 1 index

        2md iteration val = val + g[i]-cost[i] = 0 + 2-4 = -2 not possible to start here too.
        3rd iteration val = val + g[i]-cost[i] = 3-4=-1 not possible to start
        4th iteration val = val + g[i]-cost[i] = 4-1 = 3 possible
        5th iteration val = val + g[i]-cost[i] = 3 + (5-2) = 6 
        So answer=4
        */
        int n = gas.size();
        int gas_sum = 0;
        int cost_sum = 0;
        int optimal_start_point = 0; // index from where if we start will be able to traverse all the points without any gas issue
        int val = 0; // summation of g[i]-cost[i]
        for(int i=0;i<n;i++)
        {
            gas_sum = gas_sum + gas[i];
            cost_sum = cost_sum + cost[i];
            val = val + gas[i]-cost[i];
            if(val<0)
            {
                val = 0;
                optimal_start_point=i+1;
            }
        }
        if(cost_sum > gas_sum)
        return -1;
        return optimal_start_point;
    }
};
