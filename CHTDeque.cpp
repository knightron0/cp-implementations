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

struct ln {
    int m, c;
    ln(int m, int c): m(m), c(c) {}
    int val(int x){
    	return m*x + c;
    }
};

pair<int, int> intersect(ln a, ln b){
	int x = (b.c-a.c + a.m-b.m -1)/(a.m-b.m);
	int y = a.val(x);
	return {x, y};
}

deque<pair<ln, int>> dq;

void insert(int m, int c) {
    ln a(m,c);
    while(!dq.empty() && dq.back().sc >= intersect(a, dq.back().fr).fr) dq.pop_back();
    if(dq.empty()){
        dq.pb({a, 0});
        return;
    }
    dq.pb({a, intersect(a, dq.back().fr).fr});
}

int query(int x) {
    while(dq.size() > 1){
        if(dq[1].sc <= x) dq.pop_front();
        else break;
    }
    return dq[0].sc.val(x);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    
    return 0;
}



