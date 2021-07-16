//properties of gcd , gcd(a,b)= gcd(a-b,b)= gcd (a+b,b);
// A even number can always be expressed as sum of two prime number

inline ll gcd(ll a, ll b){
    if (a == 0)    return b;
    return gcd(b % a, a);
}

inline ll power(ll a, ll n, ll m){
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

// Finding the modular inverse for every number modulo m
void allinv(int m){
    inv[1] = 1;
    for(int i = 2; i < m; ++i)
        inv[i] = m - (m/i) * inv[m%i] % m;
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
