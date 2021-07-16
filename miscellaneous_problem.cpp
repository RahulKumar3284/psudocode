#################################################################################
maximum value of minimum value”:

//Zone2021_c:
N->candidate
each candidate: five parameters: power(A), speed(B), technique(C), knowledge(D), and inventiveness(E)
team:3 candidate
team's power : the maximum of the members' powers. The team's speed, technique, knowledge, and inventiveness are defined similarly.
team's total strength as the minimum of the team's power, speed, technique, knowledge, and inventiveness.
maximum possible value of your team's total strength.

Solution:

1. binary search
Problems of the form of “maximum value of minimum value” can sometimes be solved easily by boiling it down to a yes-no problem of “can the answer be more than x ?” and do binary search for the answer.
Now we will consider the yes-no problem.

We are only interested in whether or not each parameter is more than x, so we can compress each parameter to 1 or 0 depending on whether it exceeds x or not.
Then, there are at most 2^5=32 kinds of tuples of parameters, so one can check exhaustively for all possible choices of three members out of the deduplicated members.

complexity:O((NM+2^(M*k))*logX) where M denotes the number of kinds of parameters, K the number of teammates elected, and X– the upper bound of the binary search.

int n;
vector<vector<ll> >v;
bool isPossible(ll r){
	set<int>s;
	for(int i=0;i<n;i++){
		int bit=0;
		for(int j=0;j<5;j++){
			bit|=(1<<j)*(v[i][j]>=r);
		}
		s.in(bit);
	}
	for(auto i: s) for(auto j:s) for(auto k:s){
		if((i|j|k)==31) return true;
	}
	return false;
}
int main(){
    boost; i_o();
    cin>>n;
    v.resize(n,vector<ll>(5));
    for1(i,0,n) for1(j,0,5) cin>>v[i][j];
    ll lo=0,hi=1000000005;
    ll ans=0;
    while(lo<=hi){
    	ll mid=(lo+hi)/2LL;
    	if(isPossible(mid)){
    		ans=mid; lo=mid+1;
    	}
    	else hi=mid-1;
    }
    cout<<ans<<endl;
}



#########################################################################################################
