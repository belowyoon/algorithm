#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> res = {0, 10000001};
vector<vector<pair<int,int>>> map;

vector<int> getPaths(int start, vector<int> cost) {
    //cout << start  << '\n';
    int maxIntensity = 10000001;
    priority_queue<pair<int,int>> q;
    q.push({0, start});
    while(!q.empty()) {
        int node = q.top().second;
        int intensity = -q.top().first;
        q.pop();
        if(cost[node] <= intensity) {
            continue;
        }
        //cout << node << " " << intensity << '\n';
        cost[node] = intensity;
        for (int i = 0; i < map[node].size(); i++) {
            int nxtNode = map[node][i].first;
            int nxtIntensity = max(intensity, map[node][i].second);
            if (nxtIntensity < cost[nxtNode])
                q.push({-nxtIntensity, nxtNode});
        }
    }
    return cost;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    map.assign(n + 1, vector<pair<int,int>>());
    for (int i = 0; i < paths.size(); i++) {
        bool flag[2] = {false,false};
        for (int j = 0; j < gates.size(); j++) {
            if (paths[i][0] == gates[j]) {
                map[paths[i][0]].push_back({paths[i][1], paths[i][2]});
                flag[0] = true;
            }
            if (paths[i][1] == gates[j]) {
                map[paths[i][1]].push_back({paths[i][0], paths[i][2]});
                flag[1] = true;
            }
        }
        for (int j = 0; j < summits.size(); j++) {
            if (paths[i][0] == summits[j] && !flag[1]) {
                map[paths[i][1]].push_back({paths[i][0], paths[i][2]});
                flag[1] = true;
            }
            if (paths[i][1] == summits[j] && !flag[0]) {
                map[paths[i][0]].push_back({paths[i][1], paths[i][2]});
                flag[0] = true;
            }
        }
        if (!flag[0] && !flag[1]) {
            map[paths[i][0]].push_back({paths[i][1], paths[i][2]});
            map[paths[i][1]].push_back({paths[i][0], paths[i][2]});
        }
    }
    vector<int> cost;
    cost.assign(n + 1, 10000001);
    // for (int i = 0; i < map.size(); i++) {
    //     cout << i << ": ";
    //     for (int j = 0; j < map[i].size(); j++) {
    //         cout << map[i][j].first << " ";
    //     }
    //     cout << "\n";
    // }
    for (int i = 0; i < gates.size(); i++) {
        cost = getPaths(gates[i], cost);
        //cout << '\n';
        for (int j = 0; j < summits.size(); j++) {
            //cout << summits[j] << " " << cost[summits[j]] << '\n';
            if (cost[summits[j]] < res[1]) {
                res[1] = cost[summits[j]];
                res[0] = summits[j];
            } else if (cost[summits[j]] == res[1] && res[0] > summits[j]){
                res[0] = summits[j];
            }
        }
        //cout << "res: " << res[0] << " " << res[1] << '\n';
    }
    return res;
}