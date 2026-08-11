class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n=tasks.size();
        vector<long long> prefix(n+1,0);
        for(int i = 0; i < n; i++) 
            prefix[i + 1] =prefix[i] + tasks[i];

        vector<int> ans;
        long long curr=0;
        for(int shift:shifts){
            curr+= shift;
            if(curr>=prefix[n]){
                curr=0;
                ans.push_back(0);
            }
            else {
                auto it=upper_bound(prefix.begin(),prefix.end(),curr);
                int completed=distance(prefix.begin(),it)-1;
                ans.push_back(n-completed);
            }
        }
        return ans;
    }
};