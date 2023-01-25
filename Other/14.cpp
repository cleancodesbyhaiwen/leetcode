class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int minLen = 200;
        for(int i = 0;i < strs.size();i++){
            if(strs[i].length() < minLen){
                minLen = strs[i].length();
            }
        }
        cout<<"min len is "<<minLen<<endl;
        
        for(int i = 0;i < minLen+1;i++){
            char c = strs[0][i];
            cout<<i<<". "<<c<<endl;
            for(int j = 0;j < strs.size();j++){
                if(strs[j][i] != c){
                    cout<<"The "<<i+1<<" character of "<<j+1<<"th element is different."<<endl;
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
};