class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
                sort(people.begin(), people.end());

        int j  = people.size()-1;
        int i  = 0 ;
        int cnt = 0 ;

        while(i<=j)
        {
            int sum= people[i]+people[j];
            if(sum <=limit){
                cnt++;
            i++;
            j--;}
            else {
                cnt++;
                j--;

            }

        }

        return cnt;
    }
};