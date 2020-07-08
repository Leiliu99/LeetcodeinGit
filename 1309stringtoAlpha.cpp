class Solution {
public:
    string freqAlphabets(string s) {
        string hg="";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!='#'){
                char b = 96 + s[i] - '0';
                hg=b+hg;
            }else{
                char b = 96 + s[i-1]-'0' + (s[i-2] - '0')*10;
                hg=b+hg;
                i=i-2;
            }
        }
        return hg;
    }
};
/*
 * string freqAlphabets(string s) {
        int i = 0;
        string resStr;
        while(i < s.length()){
            if(s[i] == '#'){
                i++;
                continue;
            }
            string subContent;
            if(((i + 2) < s.length()) && s[i + 2] == '#'){
                while(s[i] != '#'){
                    subContent = subContent + s[i];
                    i++;
                }
            }else{
                subContent = s[i];
                i++;
            }
            //cout<<subContent<<endl;
            char subChar = stoi(subContent) + 96;
            resStr = resStr + subChar;
        }
        return resStr;
    }
 */