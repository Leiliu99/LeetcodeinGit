class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> A(n);
        for (int i = 0; i < n; ++i)
            A[i] = i * 2 - n + 1;//find the rule (arithmetic sequence)
            //start->the actual number minus one(negative of this)
            //end->the actual number minus one
//            Actually, this rule could be derived from constructing an arithmetic sequence.
//
//(Note that any arithmetic sequence must have unique values if the common delta is non-zero)
//
//We need the sequence sum, so that
//
//(a[0] + a[n-1]) * n / 2 = 0, which means a[0] + a[n-1] = 0.
//
//Note that a[n-1] - a[0] = (n-1) * delta, which is -2 * a[0],
//so we simply set delta = 2, a[0] = 1 - n
        return A;
    }
};
//class Solution {
//public:
//    vector<int> sumZero(int n) {
//        vector<int> res;
//        if(n == 1){
//            res.push_back(0);
//            return res;
//        }
//        if(n % 2 == 0){
//            int element = n / 2;
//            while(element != 0){
//               res.push_back(element);
//               res.push_back((-1) * element);
//               element--;
//            }
//            return res;
//        }else{
//            int element = n / 2;
//            while(element != 0){
//               res.push_back(element);
//               res.push_back((-1) * element);
//               element--;
//            }
//            res.push_back(0);
//            return res;
//        }
//
//    }
//};


