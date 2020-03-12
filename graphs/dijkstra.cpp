#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

const int inf = numeric_limits<int>::max(); 

vector<int> dijkstra_set(int s, const vector<vector<pair<int, int>>>& g) {
    int n = g.size();
    vector<int> d(n, inf);
    d[s] = 0;
    set<pair<int, int>> q;
    q.insert(mp(d[s], s));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto [to, len] : g[v]) {
            if (d[v] + len < d[to]) {
                q.erase(mp(d[to], to));
                d[to] = d[v] + len;
                q.insert(mp(d[to], to));
            }
        }
    }
    return d;
}

vector<int> dijkstra_heap(int s, const vector<vector<pair<int, int>>>& g) {
    int n = sz(g);
    vector<int> d(n, inf);
    d[s] = 0;
    priority_queue<pair<int, int>> q;
    q.push(mp(-d[s], s));
    while (!q.empty()) {
        int v = q.top().second;
        int cur_d = -q.top().first;
        q.pop();
        if (cur_d > d[v]) continue;
        for (auto [to, len] : g[v]) {
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                q.push(mp(-d[to], to));
            }
        }
    }
    return d;
}


int main() {

    return 0;
}