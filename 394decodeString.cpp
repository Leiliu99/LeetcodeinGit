class Solution {
public:
    string decodeString(string s) {
        if(s.empty()) return s;
        string res;
        stack<string> charStack;
        int i = 0;
        while(i < s.size()){
            string target;
            target += s[i];
            if(target == "]"){
                string repeatContent;
                while(charStack.top() != "["){
                    repeatContent = charStack.top() + repeatContent;
                    charStack.pop();
                }
                charStack.pop();//pop the ']'
                int repeatCount = stoi(charStack.top());
                //cout<<repeatCount<<endl;
                charStack.pop();
                string patrialRes;
                for(int j = 0; j < repeatCount; j++){
                    patrialRes = patrialRes + repeatContent;
                }
                charStack.push(patrialRes);
                i++;
            }else{
                // cout<<(s[i] - 48)<<endl;
                if((s[i] - 48) >= 0 && (s[i] - 48) <= 9){
                    while((i+1) < s.size() && ((s[i+1] - 48) >= 0 && (s[i+1] - 48) <= 9)){
                        target = target + s[i+1];
                        i++;
                    }
                    //cout<<target<<endl;
                    charStack.push(target);
                    i++;
                }else{
                    //cout<<target<<endl;
                    charStack.push(target);
                    i++;
                }


            }
        }
        while(!charStack.empty()){
            res = charStack.top() + res;
            charStack.pop();
        }
        return res;
    }
};