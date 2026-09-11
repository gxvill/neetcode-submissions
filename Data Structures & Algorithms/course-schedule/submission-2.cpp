class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {


        // index is the course
        // value is incoming degrees
        vector<int> deg(numCourses, 0);

        // index is the prereq
        // values are the courses
        vector<vector<int>> adj(numCourses);

        // process all courses
        for(auto& v : prerequisites){
            int course = v[0]; 
            int pre = v[1];
            deg[course]++;
            adj[pre].push_back(course);
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i ++){
            if(deg[i] == 0) q.push(i);
        }

        int sorted = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            sorted++;
            for(int next : adj[cur]){
                if(--deg[next] == 0) q.push(next);
            }
        }


        return sorted == numCourses;
    }
};
