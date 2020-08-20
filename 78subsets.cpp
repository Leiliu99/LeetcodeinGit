class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;
    }
    // nums 给定的集合
    // i 下次添加到集合中的元素位置索引
    // sub 临时结果集合(每次需要复制保存)
    // subs 最终结果
    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        //把临时结果append到最终结果里

        subs.push_back(sub);
        // cout<<i<<endl;
        // for(int i = 0; i < subs.size(); i++){
        //     cout<<"[ ";
        //     for(int k = 0; k < subs[i].size(); k++){
        //         cout<<subs[i][k]<<", ";
        //     }
        //     cout<<"] ";
        // }
        // cout<<endl;
        for (int j = i; j < nums.size(); j++) {
            //以nums[j]为开头的
            sub.push_back(nums[j]);
            //所有可能 全部append
            subsets(nums, j + 1, sub, subs);
            //撤销这个开头
            sub.pop_back();
        }
    }

};