
// finding all prime numbers from 1 to N  in O(nlog(logn));
const int N=100000001;
bool isPrime[N];
vector<int>prime;

void sieve(){
	fil(isPrime,1);
	isPrime[0]=isPrime[1]=false;
	for(int i=4;i<N;i+=2) isPrime[i]=false;
	for(int i=3;i*i<N;i+=2){
		if(isPrime[i]){
			for(int j=i*i;j<N;j+=2*i) isPrime[j]=false;
		}
	}
	prime.pb(2);
	for(int i=3;i<N;i+=2){
		if(isPrime[i]) prime.pb(i);
	}
}

