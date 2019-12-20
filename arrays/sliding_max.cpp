#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

vector<int> max_sliding_window(vector<int>& a, int k) {
    int n = sz(a);
    if (n == 0) return {};
    vector<int> prefix = a;
    for (int i = 1; i < n; ++i) {
        if (i % k == 0) continue;
        prefix[i] = max(prefix[i], prefix[i - 1]);
    }
    vector<int> suffix = a;
    for (int i = n - 2; i >= 0; --i) {
        if (i % k == k - 1) continue;
        suffix[i] = max(suffix[i], suffix[i + 1]);
    }
    vector<int> ans;
    for (int i = 0; i + k <= n; ++i) {
        ans.push_back(max(suffix[i], prefix[i + k - 1]));
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int x : max_sliding_window(a, k)) cout << x << " ";
    cout << endl;
    return 0;
}