#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

struct Box {
    int strength = 0;
    int weight = 0;
     
    Box(int strength, int weight)
        : strength(strength)
        , weight(weigth)
    {
    }
    
    Box() = default;
};

bool canRearrange(const vector<Box>& boxes) {
    int n = boxes.size();
    sort(boxes.begin(), boxes.end());
    long long totalWeight = 0;
    for (int i = 0; i < n; ++i) {
        if (totalWeight > boxes[i].strength) return false;
        totalWeight += boxes[i].weight;
    }
    return true;
}
    
    
int main() {
    int n;
    cin >> n;
    vector<Boxes> box(n);
    for (int i = 0; i < n; ++i) {
        int strength;
        int weight;
        cin >> strength >> weight;
        box[i] = Box(strength, weight); 
    }
    cout << canRearrange(boxes) << endl;
    return 0;
}