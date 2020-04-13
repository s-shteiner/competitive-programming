#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;
    
void threeWayPartition(const vector<int>& a, int mid) {
    int n = a.size();
    int i = 0;
    int j = 0;
    int k = n;
    while (j < k) {
      if (a[j] < mid) {
            swap(a[i], a[j]);
            ++i;
            ++j;
        } else if (a[j] > mid) {
            --k;
            swap(a[j], a[k]);
        } else {
            ++j;
        }
    }
}
    
int main() {

    return 0;
}