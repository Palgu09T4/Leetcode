class Solution {
public:
    string frequencySort(string s) {
        auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
                        return a.second < b.second;
                                };
                                        
                                                priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
                                                        
                                                                unordered_map<char, int> hm;
                                                                        
                                                                                for (char c : s) {
                                                                                            hm[c]++;
                                                                                                    }
                                                                                                            
                                                                                                                    for (const auto& entry : hm) {
                                                                                                                                pq.push(make_pair(entry.first, entry.second));
                                                                                                                                        }
                                                                                                                                                
                                                                                                                                                        string result = "";
                                                                                                                                                                while (!pq.empty()) {
                                                                                                                                                                            pair<char, int> p = pq.top();
                                                                                                                                                                                        pq.pop();
                                                                                                                                                                                                    result.append(p.second, p.first);
                                                                                                                                                                                                            }
                                                                                                                                                                                                                    
                                                                                                                                                                                                                            return result;
        }
    
};