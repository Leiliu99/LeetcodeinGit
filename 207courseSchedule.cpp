class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> adjacent(numCourses, vector<int>(numCourses, 0));
        for(int i = 0; i < prerequisites.size(); i++){//initialize the indegrees and adjacent
            indegrees[prerequisites[i][0]] ++;
            adjacent[prerequisites[i][1]][prerequisites[i][0]] = 1;
        }
        queue<int> travelQueue;
        for(int j = 0; j < numCourses; j++){
            if(indegrees[j] == 0) travelQueue.push(j);//push all the nodes that do not have a parent into our travel queue
        }
        int totalVertices = numCourses;
        while(!travelQueue.empty() && totalVertices != 0){
            int targetVertice = travelQueue.front();
            travelQueue.pop();
            totalVertices--;a
            for(int i = 0; i < adjacent[targetVertice].size(); i++){
                if(adjacent[targetVertice][i] == 1){
                    indegrees[i]--;
                    if(indegrees[i] == 0){
                        travelQueue.push(i);//push to the queue if we have traveled all the parents of this node
                        //ready to analyze a new level of the node
                    }
                }
            }
        }
        return (totalVertices == 0);
    }
};