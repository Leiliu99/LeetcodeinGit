class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(begin(stones), end(stones));//push the whole vector into a priority queue, so all the elements will line up
        while (q.size() > 1) {
            auto w1 = q.top(); q.pop();
            auto w2 = q.top(); q.pop();
            if (w1 - w2 > 0) q.push(w1 - w2);
         }
        return q.empty() ? 0 : q.top();
    }
};