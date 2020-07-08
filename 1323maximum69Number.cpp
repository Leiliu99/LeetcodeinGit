//string s_num = to_string(num);
//        for (auto &c : s_num) {
//            if (c == '6') {
//                c = '9';
//                break;
//            }
//        }
//        return stoi(s_num);
int maximum69Number (int num) {
        int countRes = -1;
        int count = 0;
        int testNum = num;
        while(testNum != 0){
            if(testNum % 10 == 6){
                countRes = count;
            }
            testNum = testNum / 10;
             count++;
        }
        if(countRes == -1){
            return num;
        }else{
            //cout<< "countRes is: "<<countRes<<endl;
            int changedNum = 9 *  pow(10, countRes);
            //cout<< "changedNum is: "<<changedNum<<endl;
            int numBefore = num  / pow(10, (countRes + 1));
            //cout<<pow(10, (countRes + 1))<<endl;
            //cout<< "numBefore is: "<<numBefore<<endl;
            numBefore = numBefore * pow(10, (countRes + 1));
            //cout<< "numBefore is: "<<numBefore<<endl;
            int numAfter = num % int(pow(10, (countRes)));
            //cout<< "numAfter is: "<<numAfter<<endl;
            int result = numBefore + changedNum + numAfter;
            return result;
        }
}

