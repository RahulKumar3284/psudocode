https://codeforces.com/gym/102694/problem/D
#include<bits/stdc++.h>
using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args&&... args) {
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#define pi 3.141592653589
#define MOD 1000000007
#define to() int t; cin>>t; while(t--)
#define pb push_back
#define in insert
#define mp make_pair
#define ff first
#define ss second
#define si(s) s.size()
#define fori(it,v) for(it=v.begin();it!=v.end(); it++) 
#define for1(low,high,k) for(int i=low;i<high;i+=k)
#define for11(low,high,k) for(int j=low;j<high;j+=k)
#define for2(low,high,k) for(int i=low;i<=high;i+=k)
#define rev(high,low,k)  for(int i=high;i>=low ;i-=k)
#define all(x) x.begin(), x.end()
#define fil(x,i) memset(x,i,sizeof(x));
#define setbits(x) __builtin_popcount(x)
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout) 
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
const int N=3e5+5;
int n,m;
vector<vector<pair<int,int> > >g;
int up[N][21];
int mini[N][21];
int tin[N],tout[N],h[N];
int cnt=0;
void dfs(int i, int par,int wt,int ht){
	tin[i]=cnt++;
	up[i][0]=par;
	h[i]=ht;
	mini[i][0]=wt;
	for(int j=1;j<=20;j++){
		up[i][j]=up[up[i][j-1]][j-1];
		mini[i][j]=min(mini[i][j-1], mini[up[i][j-1]][j-1]);
	}
	
	for(pair<int,int>p :g[i]){
		if(p.ff==par)continue;
		dfs(p.ff,i,p.ss,ht+1);
	}
	tout[i]=cnt++;
}

bool ancestor(int a,int b){
	if(tin[a]<=tin[b] && tout[a]>=tout[b]) return true;
	return false;
}
 
int lca(int a, int b){
	if(ancestor(a,b)) return a;
	if(ancestor(b,a)) return b;
	for(int i=20;i>=0;i--){
		if(!ancestor(up[a][i],b))
			a=up[a][i];
	}
	return up[a][0];
}	

int mina2b(int a,int c){
	int mins=1e9+5;//cur=0;
	for(int i=20;i>=0;i--){
		int b=up[a][i];
		//trace(a,b,c,h[b],h[c]);
		if(h[b]<h[c]) continue;
		mins=min(mins,mini[a][i]);
		a=up[a][i];
	}
	return mins;
}

int main()
{
	boost;
	cin>>n>>m;
	g.resize(n+1);
	for1(0,m,1){ 
		 int a,b,w; cin>>a>>b>>w;
		 g[a].pb(mp(b,w));
		 g[b].pb(mp(a,w));
	}
	for(int i=0;i<N;i++) for(int j=0;j<=20;j++){ mini[i][j]=1e9+5; up[i][j]=1;}
	dfs(1,1,1e9+5,0);
	int q; cin>>q; 
	while(q--){
		int a,b; cin>>a>>b;
		int c=lca(a,b);
	//	trace(a,b,c);
		int ans=1e9+5;
		if(a!=c) ans=min(ans,mina2b(a,c));
		if(b!=c) ans=min(ans,mina2b(b,c));
		cout<<ans<<endl;
	}
return 0;
}
