class Solution {
public:
    bool isValid(string s) {
       stack<char> stack;

        if(s.length() == 0){
            return true;
        }
        if(s.length() == 1){
            return false;
        }
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            switch(c){
                    case('('):
                    case('{'):
                    case('['):
                        stack.push(c);
                        break;

                    case(')'):
                    if(stack.empty() || stack.top() != '(') return false;
                    else stack.pop();
                    break;
                case('}'):
                    if(stack.empty() || stack.top() != '{') return false;
                    else stack.pop();
                    break;
                case(']'):
                    if(stack.empty() || stack.top() != '[') return false;
                    else stack.pop();
                    break;
                default:
                    return false;

            }
        }
        return stack.empty();
    }


};