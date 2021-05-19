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

int parent[MAXN], n;

void init(){
    for(int i= 1;i<=n;i++) parent[i] = i;
}

int find_set(int s){
    if(s == parent[s]) return s;
    return parent[s] = find_set(parent[s]);
}

bool merge_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        parent[b] = a;
        return true;
    } else {
        return false;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    return 0;
}
