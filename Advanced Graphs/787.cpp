class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<int>> adj_matrix(n, vector<int>(n));
        for(int i = 0;i < flights.size();i++){
            adj_matrix[flights[i][0]][flights[i][1]] = flights[i][2];
        }
        
        vector<int> cost(n, INT_MAX);
        vector<int> stops(n, INT_MAX);
        cost[src] = 0;
        stops[src] = 0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({0, src, 0});
        
        while(!pq.empty()){
            int currCost = pq.top()[0];
            int currStops = pq.top()[2];
            int curr = pq.top()[1];
            pq.pop();
            
            if(curr == dst){
                return currCost;
            }
            if(currStops == k + 1){
                continue;
            }
            
            for(int i = 0;i < n;i++){
                if(adj_matrix[curr][i] > 0){
                    int newCost = currCost + adj_matrix[curr][i];
                    if(newCost < cost[i] || currStops + 1 < stops[i]){
                        pq.push({newCost, i, currStops+1});
                        cost[i] = newCost;
                        stops[i] = currStops + 1;
                    }
                }
            }
        }
        if(cost[dst] == INT_MAX){
            return -1;
        }
        return cost[dst];
    }
};