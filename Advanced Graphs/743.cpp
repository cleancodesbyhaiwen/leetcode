// Dijkstra's algorithm

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
       vector<pair<int, int>> adj_list[n+1];
        for(int i = 0;i < times.size();i++){
            int src = times[i][0];
            int dst = times[i][1];
            int cost = times[i][2];
            adj_list[src].push_back({dst,cost});
        }
        
        vector<int> receiveTime(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        
        pq.push({0,k});
        receiveTime[k] = 0;
        
        while(!pq.empty()){
            int currNode = pq.top().second;
            int currNodeCost = pq.top().first;
            pq.pop();
            
            if(currNodeCost > receiveTime[currNode]){
                continue;
            }
            
            for(int i = 0;i < adj_list[currNode].size();i++){
                pair<int, int> edge = adj_list[currNode][i];
                int node = edge.first;
                int cost = edge.second;
                if(receiveTime[node] > currNodeCost + cost){
                    receiveTime[node] = currNodeCost + cost;
                    pq.push({currNodeCost+cost, node});
                }
            }
        }
        
        int result = INT_MIN;
        for(int i = 1;i < n+1;i++){
            
            result = max(result, receiveTime[i]);
        }
        if(result == INT_MAX){
            return -1;
        }
        return result;
        
    }
};