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
#define fil(x,i) memset(x,i,sizeof(x))
#define fori(it,v) for(it=v.begin();it!=v.end(); it++)
#define for1(low,high,k) for(int i=low;i<high;i+=k)
#define for11(low,high,k) for(int j=low;j<high;j+=k)
#define for2(low,high,k) for(int i=low;i<=high;i+=k)
#define rev(high,low,k)  for(int i=high;i>=low ;i-=k)
#define all(x) x.begin(), x.end()
#define setbits(x) __builtin_popcount(x)
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define deb1(s) cout<<"s= "<<s<<endl;
#define deb2(s) cout<<"s= "<<s<<" ";
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
inline ll gcd(ll a, ll b)
{
	if (a == 0)	return b;
	return gcd(b % a, a);
}

inline ll power(ll a, ll n, ll m)
{
	if (n == 0) return 1;
	ll p = power(a, n / 2, m);
	p = (p * p) % m;
	if (n % 2) return (p * a) % m;
	else return p;
}

//works when m is prime
inline ll modInverse(ll n, ll m){
    return power(n, m-2, m);
}

//works when a and m are coprime  i.e. inverse exist
ll modInverse(ll a, ll m){
    if(m==1) return 0;
    ll temp=m, y=0, x=1;
    while (a > 1) {
        ll q=a/m,t=m;
        m=a%m; a=t;
        t=y; y=x-q*y; x=t;
    }
    if(x<0) x+=temp;
    return x;
}

//first calculate factorial
/*
 fact[0]=1LL;
    for(ll i=1;i<N;i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
*/

//nCr with modulus
ll nCr(ll n, ll r, ll m){
    if(n<r) return 0;
    if(r==0) return 1;
    return (fact[n]*modInverse(fact[r],m)%m * modInverse(fact[n-r],m)%m)%m;
}

//nCr without modulus
ll nCr(int n, int r){
    ll p=1,k=1;
    if(n-r<r) r=n-r;
    if(r!=0) {
        while(r){
            p*=n; k*=r;
            ll m =gcd(p, k);
            p/=m; k/=m;
            n--; r--;
        }
    }
      return p;
}

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
