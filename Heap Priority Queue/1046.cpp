class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;
        for(int i = 0;i < stones.size();i++){
            pq.push(stones[i]);
        }
        while(true){
            if(pq.size()<=1){
                break;
            }
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x > y){
                pq.push(x-y);
            }else if(x < y){
                pq.push(y-x);
            }else{
            }
        }
        if(pq.empty()){
            return 0;
        }
        return pq.top();
    }
};