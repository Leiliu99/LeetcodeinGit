class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
      vector<int> A(arr);
      sort(A.begin(), A.end());
      unordered_map<int, int> rank;
      for (int& a : A)
          rank.emplace(a, rank.size() + 1);//the current size + 1 is the actual rank for this element
      for (int &a: arr)
          a = rank[a];
      return arr;
    }
};