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
#define MOD2 998244353
#define to() int tt; cin>>tt; while(tt--)
#define pb push_back
#define in insert
#define mp make_pair
#define ff first
#define ss second
#define si(s) s.size()
#define fori(it,v) for(it=v.begin();it!=v.end(); it++)
#define for1(i,low,high) for(int i=low;i<high;i++)
#define for2(i,low,high) for(int i=low;i<=high;i++)
#define rev(i,high,low)  for(int i=high;i>=low ;i--)
#define all(x) x.begin(), x.end()
#define fil(x,i) memset(x,i,sizeof(x));
#define setbits(x) __builtin_popcount(x)
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define d4 [(1,0),(0,1),(-1,0),(0,-1)]
#define d8 [(1,0),(1,1),(0,1),(-1,1),(-1,0),(-1,-1),(0,-1),(1,-1)]
#define d6 [(2,0),(1,1),(-1,1),(-2,0),(-1,-1),(1,-1)]
// # hexagonal layout
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
void i_o() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	freopen("output.txt", "w", stdout) ;
#endif
}

int main()
{
	boost; i_o();

	return 0;
}
