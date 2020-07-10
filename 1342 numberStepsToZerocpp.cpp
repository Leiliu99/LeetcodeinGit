class Solution {
public:
    int numberOfSteps (int num) {
        return num == 0 ? 0 : log2(num) + __builtin_popcount(num);
        //log2(num) is total number of bits minus one
        //bitset<32>(num).count() is number of 1's totally
        //also __builtin_popcount(num) is number of 1's totally
    }
};
//class Solution {
//public:
//    int numberOfSteps (int num) {
//        int step = 0;
//        while(num != 0){
//            if(num % 2 == 0){
//                num = num / 2;
//
//            }else{
//                num = num - 1;
//            }
//            step ++;
//        }
//        return step;
//    }
//};
