#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// http://e-maxx.ru/algo/mst_prim

const int inf = numeric_limits<int>::max(); 

int prim(const vector<vector<pair<int, int>>>& g) {
    int ans = 0;
    int n = g.size();
    vector<int> d(n, inf);
    d[0] = 0;
    set<pair<int, int>> q;
    q.insert(mp(d[0], 0));
    while (!q.empty()) {
        int v = q.begin()->second;
        ans += q.begin()->first;
        q.erase(q.begin());
        for (auto [to, len] : g[v]) {
            if (len < d[to]) {
                q.erase(mp(d[to], to));
                d[to] = len;
                q.insert(mp(d[to], to));
            }
        }
    }
    return ans;
}


int main() {

    return 0;
}
