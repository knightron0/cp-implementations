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
const int LOGN = 21;

vector<int> adj[MAXN];
int timer = 0, tout[MAXN], tin[MAXN], up[MAXN][LOGN+2], n;

void dfs(int v, int p){
	timer++;
	tin[v] = timer;
	up[v][0] = p;
	for(int i=1;i<=LOGN;i++){
		up[v][i] = up[up[v][i-1]][i-1];
	}
	for(int u: adj[v]){
		if(u != p){
			dfs(u, v);
		}
	}
	timer++;
	tout[v] = timer;
}

bool isanc(int u, int v){
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
	if(isanc(u, v)) return u;
	if(isanc(v, u)) return v;
    for(int i=LOGN;i>=0;i--){
        if(!isanc(up[u][i], v)){
            u = up[u][i];
        }
    }
    return up[u][0];
}

void init(){
    timer = 0;
    clr(tout, 0);
    clr(tin, 0);
    clr(up, 0);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    cin>>n;
    for(int i= 0;i<n-1;i++){
    	int t1, t2;
    	cin>>t1>>t2;
    	adj[t1].pb(t2);
    	adj[t2].pb(t1);
    }
    init();
    dfs(1, 1);
    return 0;
}

