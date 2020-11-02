/*

the concept is presented here:

https://sites.cs.ucsb.edu/~neeraj/theory-meetup/uploads/linear-time-cp.pdf

could be used for a line as well (but could also be done a bit simpler)

*/

#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

namespace std {
  template <>
  struct hash<pair<int, int>>
  {
    size_t operator()(const pair<int, int>& p) const
    {
      return (3 * p.first) ^ p.second;
    }
  };
}

double sqr(double x) {
    return x * x;
}

double dist(const pair<double, double>& p1, const pair<double, double>& p2) {
    return sqr(p2.first - p1.first) + sqr(p2.second - p1.second);
}

pair<int, int> hashp(const pair<double, double>& p, double r) {
    return {floor(p.first / r), floor(p.second / r)};
}

double closest_pair(vector<pair<double, double>> p) {
    
    // the crucial part
    random_shuffle(begin(p), end(p));

    // assert n >= 2
    int n = p.size();
    unordered_map<pair<int, int>, vector<pair<double, double>>> g;
    
    // init with first two points
    double r = dist(p[0], p[1]);
    g[hashp(p[0], r)].push_back(p[0]);
    g[hashp(p[1], r)].push_back(p[1]);
    // iterate over points
    for (int i = 2; i < n; ++i) {
        vector<pair<double, double>> cands;
        auto new_hash = hashp(p[i], r);
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int x = new_hash.first + dx;
                int y = new_hash.second + dy;
                if (g.count({x, y})) {
                    for (auto point : g[{x, y}]) {
                        cands.push_back(point);
                    }
                }
            }
        }
        double new_r = r;
        for (auto point : cands) {
            new_r = min(new_r, dist(p[i], point));
        }
        if (new_r < r) {
            g.clear();
            r = new_r;
            for (int j = 0; j <= i; ++j) {
                g[hashp(p[j], r)].push_back(p[j]);
            }
        } else {
            g[new_hash].push_back(p[i]);
        }
    }
    return sqrt(r);
}

void solve_urionlinejudge() {
     while (true) {
        int n;
        cin >> n;
        if (n == 0) return;
        vector<pair<double, double>> p;
        for (int i = 0; i < n; ++i) {
            double x;
            cin >> x;
            double y;
            cin >> y;
            p.emplace_back(x, y);
        }
        if (n == 1) {
            cout << "INFINITY" << endl;
            continue;
        }
        double r = closest_pair(p); 
        if (r < 10000) {
            printf("%.4f\n", r);
        } else {
            cout << "INFINITY" << endl;
        }
    }
}

// for debug and benchmarking

double closest_pair_bf(const vector<pair<double, double>>& p) {
    int n = p.size();
    double ans = dist(p[0], p[1]);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans = min(ans, dist(p[i], p[j]));
        }
    }
    return sqrt(ans);
}

void stress_test() {
    for (int test = 0; test < 10; ++test) {
        int n = rand() % 1000;
        vector<pair<double, double>> p; 
        for (int i = 0; i < n; ++i) {
            p.emplace_back(rand() % 10000, rand() % 10000);
        }
        cout << closest_pair(p) << " " << closest_pair_bf(p) << endl;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<pair<double, double>> p;
    for (int i = 0; i < n; ++i) {
        double x;
        cin >> x;
        double y;
        cin >> y;
        p.emplace_back(x, y);
    }
    
    double r = closest_pair(p); 
    cout << r << endl;
}

int main() {
    //stress_test();
    //solve_urionlinejudge();

    solve();
    
    return 0;
}
