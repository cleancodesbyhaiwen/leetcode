class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
     
        priority_queue<pair<double, vector<int>>> pq;
        for(int i = 0;i < points.size();i++){
            int distance = pow(points[i][0],2) + pow(points[i][1],2);
            pq.push({distance, points[i]});
        }
        
        vector<vector<int>> result;
        for(int i = 0;i < points.size()-k;i++){
            pq.pop();
        }
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};