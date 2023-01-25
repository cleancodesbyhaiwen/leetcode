class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        
        vector<vector<int>> adj_list(edges.size()+1);
        vector<bool> visited(edges.size()+1);
        
        for(auto& edge : edges){
            fill(visited.begin(), visited.end(),false);
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
            if(dfs(adj_list, visited, edge[0], -1)){
                return edge;
            }
        }
        return {};
    }
    
    bool dfs(vector<vector<int>>& adj_list, vector<bool>& visited, int curr, int last){
        
        if(visited[curr] == true){
            return true;
        }
        
        visited[curr] = true;
        
        for(auto& e : adj_list[curr]){
            if(e != last && dfs(adj_list, visited, e, curr)){
                return true;
            }
        }
        return false;
    }
};