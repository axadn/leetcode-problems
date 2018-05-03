/** This problem is basically a search for a path from the right side of the query to the left side
** We can do a depth-first search
*/
struct stackFrame{
    string numerator;
    int map<string, double>::iterator considering;
    float value;
};
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> results;
        unordered_map<string, map<string, double>> map;
        const int size = equations.size();
        for(int i =  0; i < size; ++i){
            if(map.count(equations[i].first) == 0){
                map[equations[i].first] = unordered_map<string, double>();
            }
            if(map.count(equations[i].second) == 0){
                map[equations[i].second] = unordered_map<string, double>();
            }
            map[equations[i].first][equations[i].second] = 1 / values[i];
            map[equations[i].second][equations[i].first] = values[i];
        }
        for(int i = 0; i < queries.size(); ++i){   
            results.push_back(calc(map, values, queries[i]));
        }
        return results;
        
    }
    double calc(unordered_map<string, map<string, double>> map, const vector<double>& values, pair<string, string> query){
        stack<stackFrame> s;
        unordered_set<int> visited;
        stackFrame frame;
        if(map.count(query.second) == 0){
            return -1;
        }
        ordered_map<string, double> paths = map[query.second];
        pair<string, double> path;
        s.push(stackFrame {query.second, 0, 1});
        while(!s.empty()){
            frame = s.top();
            if(frame.numerator == query.first){
                return frame.value;
            }
            else{
                paths = map[frame.numerator];
                if(frame.considering == 0){
                    if(paths.count(query.first) != 0){
                        return frame.value * paths[query.first].second;
                    }
                }
                while(stack.top().considering != paths.end()){
                    path = *stack.top().considering;
                    if(visited.count(path.first) == 0){
                        visited.insert(path.first);
                        ++stack.top().considering;
                        s.push(stackFrame{path.first, 0, frame.value * path.second});
                        break;
                    }
                    ++stack.top().considering;
                }
                if(stack.top().considering == paths.end()){
                    visited.erase(frame.numerator);
                    s.pop();
                }
            }
        }
        return -1;
    }
};