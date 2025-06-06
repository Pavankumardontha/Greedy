class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        /*
        We need an array to store the number of people that start at a point and no. of people that end at a point.
        Given that from , to are also less than 1000. we take an array a of size 1000
        for the trips = [[2,1,5],[3,3,7]]
        intially, a[1] = 2 , a[5]=-2
        a[3]=3, a[7]=-3
        and rest all indexes of a will be 0. At each point , we add the value of a[i] if its negative or positive. 
        If at any point the current_capacity becomes greater than the maximum allowed capacity, we return false.
        */
        int current_capacity=0;
        vector<int> a(1001,0); 
        int n = trips.size();
        for(int i=0;i<n;i++)
        {
            int c = trips[i][0]; // capacity of the ith element
            int s = trips[i][1]; // start point of the ith element
            int e = trips[i][2]; // end point of the ith element
            a[s] = a[s] + c; // adding capacity to the start point index
            a[e] = a[e] - c; // removing capacity from the end point index
        }
        for(int i=0;i<=1000;i++)
        {
            current_capacity = current_capacity + a[i];
            if(current_capacity > capacity)
            return false;
        }
        return true;
    }
};
