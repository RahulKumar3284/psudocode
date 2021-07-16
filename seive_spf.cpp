//can find  prime factorization in log(n) time till N;
//Preprocess : O(N);
const int N=1e6+5;
int spf[N];
void spf_cal(){
	for(int i=1;i<N;i++) spf[i]=i;
	for(int i=4;i<N;i+=2) spf[i]=2;
	for(int i=3;i*i<N;i+=2){
		if(spf[i]!=i) continue;
		for(int j=i*i;j<N;j+=2*i) 
			spf[j]=i;
	}
}


//(faactor, power) -> O(log(n))
vector<pair<int,int> > factorization(ll a){
    vector<pair<int,int> >fact;
    while(a>1){
        int cnt=0;
        int j=spf[a];
        while(a%j==0){
            cnt++; a/=j;
        }
        fact.pb({j,cnt});
    }
    return fact;
}

//(faactor, power) -> O(sqrt(N))
vector<pair<int,int> > factorization(ll a){
    vector<pair<int,int> >fact;
    int cnt=0;
    while(a%2==0){ cnt++; a/=2;}
    if(cnt) fact.pb({2,cnt});
    for(int j=3;j*j<=a;j+=2){
        int cnt=0;
        while(a%j==0){ cnt++; a/=j;}
        if(cnt) fact.pb({j,cnt});
    }
    if(a>1) fact.pb({a,1});
    return fact;
}

