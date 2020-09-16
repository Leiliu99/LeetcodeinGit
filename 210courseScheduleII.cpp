class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {//previous BFS method
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> adjacent(numCourses, vector<int>(numCourses, 0));
        vector<int> couseOrder;
        //corner case: no requirements on any course
         if(prerequisites.size() == 0){
            for(int i=0;i<numCourses;i++){ //if no prerequisites, then courses can be in an order
                couseOrder.push_back(i);
            }
            return couseOrder;
        }


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
            totalVertices--;
            couseOrder.push_back(targetVertice);
            for(int i = 0; i < adjacent[targetVertice].size(); i++){
                if(adjacent[targetVertice][i] == 1){
                    indegrees[i]--;
                    if(indegrees[i] == 0){
                        travelQueue.push(i);
                    }
                }
            }
        }
        if(totalVertices == 0){
            return couseOrder;
        }else{
            vector<int> emptyArray;
            return emptyArray;
        }
    }
};




class Solution {
public:
   bool dfsCycle(vector<vector<int>>& graph, vector<int>& visited, vector<int>& onPath , int c, stack<int>& st)
    {
        if(visited[c] )
        {
            return false;
        }

        visited[c] = 1;
        onPath[c] = 1;

        for(int neigh : graph[c])
        {
            if(onPath[neigh] || dfsCycle(graph , visited , onPath , neigh, st))
            {
                return true;
            }
        }

        onPath[c] = false;
        st.push(c);
        return false;
    }




    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        int n = prerequisites.size();

        vector<vector<int>> graph(numCourses , vector<int>(0,0));

        for(int i = 0 ; i < n ; i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> visited(numCourses , 0 );
        vector<int> onPath(numCourses , 0 );

        stack<int> st;
        vector<int> order;

        for(int i = 0 ; i < numCourses ; i++)
        {
           if(!visited[i] && dfsCycle(graph ,visited, onPath , i , st))
            {
                return {};
            }
        }


        while(!st.empty())
        {
            order.push_back(st.top());
            st.pop();
        }

        return order;
    }
};