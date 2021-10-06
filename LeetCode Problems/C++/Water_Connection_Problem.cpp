pair< int,int>dfs(unordered_map<int, pair<int, int>> &g, int u){
        
        if(g.find(u) == g.end())
            return{u,INT_MAX};
            
        auto p = dfs(g,g[u].first);
        int minimum = min(g[u].second, p.second);
        
        return {p.first,minimum};
    }
    

    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        unordered_set<int>t;
        unordered_map<int, pair<int,int>>g;
        vector<vector<int>>ans;
        
        for(int i = 0; i < p; i++){
            t.insert(b[i]);
        }
        
        for(int i = 0; i < p; i++){
            g[a[i]] = {b[i], d[i]};
        }
        
        for(int i = 0; i<=n; i++){
            
            if(g.find(i) != g.end() && t.find(i) == t.end()){
                
                auto p = dfs(g,i);
                ans.push_back({i,p.first,p.second});
                
            }
        }
        
        return ans;