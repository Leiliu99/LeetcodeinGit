#include <string>
using namespace std;

int isPrefixOfWord(string sentence, string searchWord);
int prefixNumber(string word, string searchWord);
int main(){
    string sentence = "i use triple pillow";
    string searchWord = "pill";
    return isPrefixOfWord(sentence, searchWord);

}
int isPrefixOfWord(string sentence, string searchWord) {
    int PrefixIndex = 1;
    bool hasPrefixIndex = false;
    string word = "";
    for(auto x: sentence){
        if(x == ' '){
            //do something here
            if(prefixNumber(word, searchWord) != 0){
                hasPrefixIndex = true;
                break;
            }else{
                PrefixIndex++;
                word = "";
            }

        }else{
            word = word + x;
        }

    }
    if(hasPrefixIndex){
        return PrefixIndex;
    }else{
        return -1;
    }

}
int prefixNumber(string word, string searchWord){
    int compareLength;
    int prefixNumber = 0;
    if(word.length() < searchWord.length()){
        compareLength = word.length();
    }else{
        compareLength = searchWord.length();
    }
    for(int i = 0; i < compareLength; i++){
        if(word[i] == searchWord[i]){
            prefixNumber++;
        }else{
            break;
        }
    }
    return prefixNumber;
}
