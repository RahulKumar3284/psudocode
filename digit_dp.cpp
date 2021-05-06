// number of element b/w [a,b] : having digit d at all even place 
// ansd resulting number is divisible by m  

#include<bits/stdc++.h>
using namespace std;
int M=1e9+7;
int m,d;
int n;
int dp[2002][2002][2];
int fun(int pos,int rem,int f,string &a){
	if(pos==n){
		if(rem==0)
			return 1;
		return 0;
	}
	if(dp[pos][rem][f]!=-1) return dp[pos][rem][f];
	int ans=0;
	int lmt;
	int nrem,nf=f;
	if(f==0)
		lmt=a[pos]-'0';
		else
		 lmt=9;
	if(pos%2){
		if(d<=lmt){
			if(d<lmt) nf=f|1;
			nrem=(10*rem+d)%m;
			ans+=fun(pos+1,nrem,nf,a);
			ans=ans%M;
		}
	}
	else{
			for(int i=0;i<=lmt;i++){
				nf=f;
				if(i==d)continue;
				nrem=(10*rem+i)%m;
				if(i<lmt) nf=f|1;
				ans+=fun(pos+1,nrem,nf,a);
				ans=ans%M;
			}
		}
		ans=ans%M;
		return dp[pos][rem][f]=ans;
}
	
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>m>>d;
	string a,b;
	cin>>a>>b;
	n=a.size();
	memset(dp,-1,sizeof(dp));
	int ans=fun(0,0,0,b);
	memset(dp,-1,sizeof(dp));
	ans-=fun(0,0,0,a);
	int rem=0;
	int flag=0;
	for(int i=0;i<n;i++)
		if( (i%2 && a[i]-'0'!=d) || (i%2==0 && a[i]-'0'==d)){ flag=1; break; }
		else{
			rem=(rem*10+a[i]-'0')%m;
		}
	if(flag==0 && rem==0)
		ans++;
	ans=(ans+M)%M;
	cout<<ans<<endl;
return 0;
}
