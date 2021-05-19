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

vector<int> adj[MAXN];
int par[MAXN], sz[MAXN];
bool rm[MAXN];

int dfs(int u, int p){
	sz[u] = 1;
	for(auto v: adj[u]){
		if(v != p && !rm[v]){
			sz[u] += dfs(v, u);
		}
	}
	return sz[u];
}

int centroid(int u, int p, int n){
	for(auto v: adj[u]){
		if(v != p && !rm[v]){
			if(sz[v]*2 > n){
				return centroid(v, u, n);
			}
		}
	}
	return u;
}

void decompose(int u, int p){
	int n = dfs(u, p);
	int c = centroid(u, p, n);
	par[c] = p;
	rm[c] = 1;
	for(auto v: adj[c]){
		if(!rm[v]){
			decompose(v, c);
		}		
	}
}

void init(){
	clr(rm, 0);
	clr(sz, 1);	
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
	int n, q;
	cin>>n>>q;
	for(int i=0;i<n-1;i++){
		int u, v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	init();
	decompose(1, 0);
    return 0;
}
