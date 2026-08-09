class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        
        int m=parent.size();
        vector<vector<int>> adj(m);
        for(int i=1;i<m;i++)
            adj[parent[i]].push_back(i);
        
        vector<int>depth(m,0);
        int h=0;

        queue<int> q;
        q.push(0);
        depth[0]=1;

        while(!q.empty()){
            int u=q.front();
            q.pop();
            h=max(h,depth[u]);

            for(int v:adj[u]){
                depth[v]=depth[u]+1;
                q.push(v);
            }
        }

        long long weight=0;
        for(int i=0;i<m;i++)
                weight+=1LL*nums[i]*(h-depth[i]+1);
        
        return weight;
    }
};