class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> taskCount(26);
        
        int maxCount = 0;
        int numMax = 0; // Number of tasks with max count
        
        for(int i = 0;i < tasks.size();i++){
            taskCount[tasks[i]-'A']++;
            int currCount = taskCount[tasks[i]-'A'];
            if(currCount > maxCount){
                maxCount = currCount;
                numMax = 1;
            }
            else if(currCount == maxCount){
                numMax++;
            }
        }

        int numEmpty = n*maxCount - (numMax-1)*maxCount - (n-(numMax-1)); // Number of empty slots after filling all maxCount tasks
        int taskLeft = tasks.size() - (maxCount*numMax);
        int idels = max(0, numEmpty-taskLeft);
        return idels + tasks.size();
        
    }
};