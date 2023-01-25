class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int, double>> cars;
        
        int result = 0;
        
        for(int i = 0;i < position.size();i++){
            double timeToDes = (double) (target - position[i]) / speed[i];
            cars.push_back({position[i], timeToDes});
        }
        
        sort(cars.begin(), cars.end());
        
        double maxTime = 0.0;

        for(int i = position.size()-1;i >= 0;i--){
            if(cars[i].second > maxTime){
                maxTime = cars[i].second;
                result++;
            }
        }        
        return result;   
    }
};