class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> res(N);
        vector<vector<int>> g(N);
      for (auto p : paths) {
        g[p[0] - 1].push_back(p[1] - 1);//store all the paths
        g[p[1] - 1].push_back(p[0] - 1);//since it's bidirectional,also need to recorded it on the other direction
      }
      for (auto i = 0; i < N; ++i) {
        bool used[5] = {};
        for (auto j : g[i]) used[res[j]] = true;//if not set before this is always used[0], didnot affect
        //for the purpose to know which colour has the adjcent node has used
        for (auto fl = 1; fl <= 4; ++fl) {
          if (!used[fl]){
              res[i] = fl;//first unused colour in this node
              break;
          }
        }
      }
      return res;


    }
};