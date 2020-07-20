class Solution {
public:
    int maxNumberOfBalloons(string text) {
       unordered_map<char, int> mm;
        for (char i : text) mm[i] += 1;
        return min ( { mm['b'] , mm['a'] , mm['l']/2 , mm['o']/2 ,mm['n'] } ) ;

    }
};
//
//vector<char> ballonVec = {'b', 'a','l','o','n'};
//        vector<double> numberVec(5, 0.0);
//        for(int i = 0; i < text.size(); i++){
//            auto it = find(ballonVec.begin(), ballonVec.end(), text[i]);
//            if(it !=  ballonVec.end()){
//                if(text[i] == 'b'){
//                    numberVec[0]++;
//                }else if(text[i] == 'a'){
//                    numberVec[1]++;
//                }else if(text[i] == 'l'){
//                    numberVec[2]+= 0.5;
//                }else if(text[i] == 'o'){
//                    numberVec[3]+= 0.5;
//                }else{
//                     numberVec[4]++;
//                }
//            }
//        }
//        int minNumber = numberVec[0];
//        //cout<<minNumber<<endl;
//        for(int k = 1; k < numberVec.size(); k++){
//            //cout<<numberVec[k]<<endl;
//            //cout<<int(numberVec[k])<<endl;
//            if(int(numberVec[k]) < minNumber){
//                //cout<<k<<": "<<int(numberVec[k])<<endl;
//                minNumber = int(numberVec[k]);
//            }
//        }
//        return minNumber;