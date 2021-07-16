// ADA and salesman
#include<bits/stdc++.h>
using namespace std;
#define pb push_back

typedef long long ll;
void i_o() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
}

vector<ll>a;
vector<vector<int> >g;
ll in[100005],out[100005];

void in_dfs(int cur,int par){
	ll maxi=0;
	for(int j:g[cur]){
		if(j==par) continue;
		in_dfs(j,cur);
		maxi=max(maxi,max(0LL,a[j]-a[cur])+in[j]);
	}
	in[cur]=maxi;
}

void out_dfs(int cur,int par){
	ll mx1=-1,mx2=-1;
	for(int j:g[cur]){
		if(j==par) continue;
		ll wt=max(0LL,a[j]-a[cur]);
		if(mx1<=in[j]+wt){
			mx2=mx1; mx1=in[j]+wt;
		}
		else if(mx2<in[j]+wt) mx2=in[j]+wt;
	}
	for(int j:g[cur]){
		if(j==par) continue;
		ll largest=mx1;
		ll wt=max(0LL,a[j]-a[cur]);
		if(wt+in[j]==largest) largest=mx2; 
		out[j]=max(max(0LL,a[cur]-a[j])+out[cur],max(0LL,a[cur]-a[j])+largest);
		out_dfs(j,cur);
	}
}

int main()
{
	boost; i_o();
	int n, q; cin>>n>>q;
	a.resize(n);	g.resize(n);
	for(int i=0;i<n;i++)  cin>>a[i];
	for(int i=0;i<n-1;i++){
		int x,y; cin>>x>>y;
		g[x].pb(y); g[y].pb(x);
	}
	in_dfs(0,-1); out[0]=0;
	out_dfs(0,-1);
	while(q--){
		int r; cin>>r;
		ll ans=max(in[r],out[r]);
		cout<<ans<<endl;
	}
	return 0;
}
