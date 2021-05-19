// Reference: https://cp-algorithms.com/geometry/grahams-scan-convex-hull.html
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fr first
#define sc second
#define clr(a, x) memset(a, x, sizeof(a))
#define dbg(x) cout<<"("<<#x<<"): "<<x<<endl;
#define printvector(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout<<*it<<" "; cout<<endl;
#define all(v) v.begin(), v.end()
#define lcm(a, b) (a * b)/__gcd(a, b)
#define int long long int
#define printvecpairs(vec) for(auto it: vec) cout<<it.fr<<' '<<it.sc<<endl;
#define endl '\n'
#define float long double

const int MOD = 1e9 + 7;
const int INF = 2e15;
const int MAXN = 1e5 + 5;

struct point {
    long double x, y;
};

bool cmp(point a, point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(point a, point b, point c) {
    return ((a.x * (b.y-c.y)) + (b.x * (c.y-a.y)) + (c.x * (a.y-b.y))) < 0;
}

bool ccw(point a, point b, point c) {
    return ((a.x * (b.y - c.y)) + (b.x * (c.y - a.y)) + (c.x * (a.y - b.y))) > 0;
}

void convex_hull(vector<point>& v) {
    if(a.size() == 1) {
        return;
    }
    sort(all(v), &cmp);
    point p1 = v[0], p2 = v.back();
    vector<point> up, down;
    up.pb(p1);
    down.pb(p1);
    for(int i = 1;i<v.size();i++){
        if(i == (int)v.size()- 1 || cw(p1, v[i], p2)){
            while(up.size() >= 2 && cw(up[up.size()-2], up[up.size()-1], v[i]) == false){
                up.pop_back();
            }
            up.pb(a[i]);
        }
        if(i == (int)a.size() - 1 || ccw(p1, v[i], p2)){
            while(down.size() >= 2 && ccw(down[down.size()-2], down[down.size()-1], v[i]) == false){
                down.pop_back();
            }
            down.pb(a[i]);
        }
    }
    v.clear();
    for(int i = 0;i<(int)up.size();i++) v.pb(up[i]);
    for(int i = down.size()-2;i>0;i--) v.pb(down[i]);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    
    return 0;
}



