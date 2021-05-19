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

int tree[4*MAXN], a[MAXN];

int query(int curr, int start, int end, int l, int r){
	if(r < start or end < l) return 0;
	if(l <= start and end <= r) return tree[curr];
	int mid = (start+end)/2;
	int p1 = query(2*curr, start, mid, l, r);
	int p2 = query(2*curr +1, mid+1, end, l, r);
	return p1+ p2;
}

void build(int curr, int start, int end){
	if(start == end) {
		tree[curr] = a[start];
	} else {
		int mid = (start+end)/2;
		build(2*curr, start, mid);
		build(2*curr+1, mid+1, end);
		tree[curr] = tree[2*curr] +  tree[2*curr+1];
	}
}

void update(int curr, int start, int end, int idx, int val){
    if(start == end){
        a[idx] += val;
        tree[curr] += val;
    } else {
        int mid = (start + end)/2;
        if(start <= idx and idx <= mid) update(2*curr, start, mid, idx, val);
        else update(2*curr+1, mid+1, end, idx, val);
        tree[curr] = tree[2*curr] + tree[2*curr+1];
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

