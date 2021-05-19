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

int tree[4*MAXN], a[MAXN], lazy[4*MAXN];

void push(int v, int l, int r){
    int m = (l+r)/2;
    lazy[2*v] += lazy[v];
    lazy[2*v + 1] += lazy[v];
    tree[2*v] += lazy[v]*(m-l+1);
    tree[(2*v)+1] += lazy[v] * (r-(m+1)+1);
    lazy[v] = 0;
}

int query(int curr, int start, int end, int l, int r){
    if(r < start or end < l) return 0;
    if(l <= start and end <= r) return tree[curr];
    push(curr, start, end);
    int mid = (start+end)/2;
    int p1 = query(2*curr, start, mid, l, r);
    int p2 = query(2*curr +1, mid+1, end, l, r);
    return p1+ p2;
}

void build(int curr, int start, int end){
    lazy[curr]= 0;
    if(start == end) {
        tree[curr] = a[start];
    } else {
        int mid = (start+end)/2;
        build(2*curr, start, mid);
        build(2*curr+1, mid+1, end);
        tree[curr] = tree[2*curr] +  tree[2*curr+1];
    }
}

void update(int curr, int start, int end, int lx, int rx, int v){
    if(start > rx || end < lx) return;
    if(lx <= start && end <= rx){
        tree[curr] += v*(end-start+1);
        lazy[curr] += v;
        return;
    }
    push(curr, start, end);
    int mid = (start+end)/2;
    update(curr*2, start, mid, lx, rx, v);
    update(curr*2+1, mid+1, end, lx, rx, v);
    tree[curr] = tree[2*curr] + tree[2*curr+1];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    return 0;
}

