// Reference: https://cp-algorithms.com/graph/bridge-searching.html
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
bool vis[MAXN];
int timer = 0;
int tin[MAXN], low[MAXN];

void dfs(int u, int p){
	vis[u] = true;
	timer++;
	tin[u] = low[u] = timer;
	for(int v: adj[u]){
		if(v == p) continue;
		if(vis[v]){
			low[u] = min(low[u], tin[v]);
		} else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > tin[u]) {
				cout<<u<<' '<<v<<endl;
			}
		}
	}
}
 
void init(){
    timer = 0;
    clr(low, -1);
    clr(tin, -1);
    clr(vis, 0);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int n, m;
    cin>>n>>m;
    for(int i= 0;i<m;i++){
    	int t1, t2;
    	cin>>t1>>t2;
    	adj[t1].pb(t2);
    	adj[t2].pb(t1);
    }
    init();
    for(int i= 1;i<=n;i++){
        if(!vis[i]){
            dfs(i, -1);
        }
    }
    return 0;
}



