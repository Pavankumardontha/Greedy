class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        /*
        sort the array. Start to pick one element from the start (smaller) and one element from the end (larger)
        example : [3,2,2,1] limit=3
        after sorting : [1,2,2,3]
        1)l=0 and r=n-1=3
        here a[l] + a[r] > limit so take the larger element and move forward => r--
        2)l=0 and r=2
        a[l]+a[r]<=limit => take both elements and move forward => l++,r--
        3) l=1 and r=1
        a[l]+a[r]<=limit => take both and move forward 
        4) l=2,r=0 => loop exists
        */
        int ans = 0;
        int l = 0;
        int n = people.size();
        int r = n-1;
        sort(people.begin(),people.end());
        while(l<=r)
        {
            if(people[l] + people[r] <= limit)
            {
                l++;
                r--;
            }
            else
            r--;
            ans++;
        }
        return ans;
    }
};
