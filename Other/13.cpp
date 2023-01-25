class Solution {
public:
    int romanToInt(string s) {
        
        int result = 0;
        
        for(int i = 0;i < s.size();i++){
            
            char c = s[i];
            cout<<"char is "<<c<<endl;
            
            switch(c){
                case 'I':
                    if(s[i+1] == 'V'){
                        result += 4;
                        i++;
                    }
                    else if(s[i+1] == 'X'){
                        result += 9;
                        i++;
                    }
                    else if(s[i+1] == 'I'){
                        if(s[i+2] == 'I'){
                            result += 3;
                            i++;
                            i++;
                        }
                        else{
                            result += 2;
                            i++;
                        }
                    }   
                    else{
                        result += 1;
                    }
                    break;
                    
                case 'V':
                    result += 5;
                    cout<<"5 is added"<<endl;    
                    break;
                    
                case 'X':
                    if(s[i+1] == 'L'){
                        result += 40;
                        i++;
                    }
                    else if(s[i+1] == 'C'){
                        result += 90;
                        i++;
                    }
                    else if(s[i+1] == 'X'){
                        if(s[i+2] == 'X'){
                            result += 30;
                            i++;
                            i++;
                        }
                        else{
                            result += 20;
                            i++;
                        }
                    }  
                    else{
                        result += 10;
                        cout<<"10 is added"<<endl; 
                    }
                    break;
                    
                case 'L':
                    result += 50;
                    cout<<"50 is added"<<endl;
                    break;
                    
                case 'C':
                    if(s[i+1] == 'D'){
                        result += 400;
                        i++;
                    }
                    else if(s[i+1] == 'M'){
                        result += 900;
                        i++;
                    }
                    else if(s[i+1] == 'C'){
                        if(s[i+2] == 'C'){
                            result += 300;
                            i++;
                            i++;
                        }
                        else{
                            result += 200;
                            i++;
                        }
                    }
                    else{
                        result += 100;
                        cout<<"100 is added"<<endl;
                    }
                    break;
                    
                case 'D':
                    result += 500;
                    cout<<"500 is added"<<endl;
                    break;

                case 'M':
                    if(s[i+1] == 'M'){
                        if(s[i+2] == 'M'){
                            result += 3000;
                            i++;
                            i++;
                        }
                        else{
                            result += 2000;
                            i++;
                        }
                    }      
                    else{
                        result += 1000;
                        cout<<"1000 is added"<<endl;
                    }
                    break;
                    
                default:
                    break;
            
            }
            
        }
        return result;
        
    }
};