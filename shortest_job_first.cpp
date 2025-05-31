class Solution {
  public:
    long long solve(vector<int>& bt) 
    {
        int n = bt.size();
        sort(bt.begin(),bt.end());
        long long int total_waiting_time = 0;
        long long int current_waiting_time = 0;
        long long int sum = 0; // sum of all elements till i
        for(int i=0;i<n;i++)
        {
            current_waiting_time = sum;
            total_waiting_time += current_waiting_time;
            sum = sum + bt[i];
        }
        long long int average_waiting_time = total_waiting_time/n;
        return average_waiting_time;
    }
};
