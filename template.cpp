#include<bits/stdc++.h>
using namespace std;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) { cerr << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args&&... args) {
    const char *comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#define pi 3.14159265358979323846
#define MOD 1000000007
#define MOD1 998244353
#define to() int tt; cin>>tt; while(tt--)
#define pb push_back
#define in insert
#define mp make_pair
#define ff first
#define ss second
#define fori(it,v) for(it=v.begin();it!=v.end(); it++)
#define for1(i,low,high) for(int i=low;i<high;i++)
#define all(x) x.begin(), x.end()
#define fil(x,i) memset(x,i,sizeof(x));
#define setbits(x) __builtin_popcount(x)
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
void i_o() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ; freopen("output.txt", "w", stdout); //freopen("error.txt", "w", stderr);
#endif
}

int main()
{
	boost; i_o();
	

	return 0;
}
