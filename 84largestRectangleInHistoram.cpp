class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0) return 0;
        int max = 0;
        stack<int> positionStack;
        for(int i = 0; i <= heights.size(); i++){
            int curr;
            if(i == heights.size()){
                curr = 0;
            }else{
                curr = heights[i];
            }
            while(!positionStack.empty() && curr <= heights[positionStack.top()]){
                int h = heights[positionStack.top()];
                positionStack.pop();

                int width = i;
                if(!positionStack.empty()){
                    int peek = positionStack.top();
                    width = i - peek - 1;
                }
                if(i == heights.size()){
                    cout<<width<<endl;
                    cout<<h<<endl;
                }
                if(h * width > max){
                    max = h * width;
                }

            }
            positionStack.push(i);
        }
        return max;

    }
};