// Minimum Spanning Tree, Prim's Algorithm

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        vector<bool> visited(n);
        vector<int> minDist(n, INT_MAX);
        
        int result = 0;
        
        minDist[0] = 0;
        int edgeAdded = 0;
        
        
        while(edgeAdded < n){
            
            int currNode;
            int currDist = INT_MAX;
            for(int i = 0;i < n;i++){
                if(!visited[i] && minDist[i] < currDist){
                    currNode = i;
                    currDist = minDist[i];
                }
            }
            
            
            edgeAdded++;
            visited[currNode] = true;
            result += currDist;
            
            for(int i = 0;i < n;i++){
                int cost = abs(points[currNode][0]-points[i][0]) +
                    abs(points[currNode][1]-points[i][1]);
                if(!visited[i] && cost < minDist[i]){
                    minDist[i] = cost;
                }
            }
        }
        return result;
    }
};