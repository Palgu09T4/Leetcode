class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> result;
        vector<int> state(n, 0); // 0 = unvisited, 1 = visiting, 2 = safe
        
        function<bool(int)> dfs = [&](int node) {
            if (state[node] != 0) return state[node] == 2;
            state[node] = 1; // mark node as visiting
            for (int nei : graph[node]) {
                if (state[nei] == 1 || !dfs(nei)) {
                    return false;
                }
            }
            state[node] = 2; // mark node as safe
            return true;
        };
        
        for (int i = 0; i < n; ++i) {
            if (dfs(i)) result.push_back(i);
        }
        
        return result;
    }
};