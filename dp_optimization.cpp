
1.O(n*n) -> O(nlogn)
//629D
/*
i) for each j:1 to i-1 
ii) v[j]<v[i];
    dp[i]=max(v[i], dp[j]+v[i]); 

for(int i=1;i<n;i++){
	dp[i]=v[i];
	for(int j=0;j<i;j++){
		if(v[i]>v[j]) dp[i]=max(dp[i],dp[j]+v[i]);
	}
}

Optimization: 

Method 1: using map and lowerboud:
map<value,dp(maximum value obtained till this value) >um;
i)for each a[i] find position of element just smaller than a[i] (i.e. lowerbound-1) let be idx.
ii) now curdp=a[i]+um[idx];
iii) erase all values,greater or eqaul that a[i] and having dp value less than curdp;
*/
	map<ll,ll>um;
	um[0]=0;
	for1(i,0,n){
		cin>>a;
		auto prev=um.lower_bound(v), nxt=prev--;
		ll curdp=a+(*prev).second;
		while(nxt!=um.end() && (*nxt).ss <curdp){
			um.erase(nxt++);    //since we delete cur elemnt from array,
			//so nxt pointer must be initially assigned before deletion. hence donot use um.erase(nxt); nxt++;
		}
		um[v]=curdp;
	}
	ll ans=0;
	for(auto i: um) ans=max(ans,i.ss);





Method2: 
/*
sorting + segment tree(max )
 i) postion each elemnt according to increaing value of v[i] (no sorting of elements,just used to update its index)
 ii) for v[i], find max of segment [1,b) such that b is the position of v[i] in sorted order
 iii) let the maximum value be x, then update  bth position by (x+a[i]);
 iv) final answer: max of segment 1 to n;

 */

ll query(int idx,int tl,int tr,int l,int r){
	if(l>r) return 0LL;
	if(l== tl && r== tr) return t[idx];
	int tm=(tl+tr)/2;
	ll left=query(lson,tl,tm,l,min(r,tm));
	ll right=query(rson,tm+1,tr,max(l,tm+1),r);
	return max(left,right);
}


void update(int idx,int tl,int tr,int pos,ll val){
	if(tl==tr){	
		t[idx]=val; return;
	}
	int tm=(tl+tr)/2;
	if(pos<=tm)  update(lson,tl,tm,pos,val);
    else update(rson,tm+1,tr,pos,val);
    t[idx] = max(t[lson],t[rson]);
} 


idx-> postion of v[i] in sorted order
for1(i,0,n){
	int pos=idx[v[i].ff];
	ll dp=query(1,1,m,1,pos-1);
	dp+=v[i].ff;
	update(1,1,m,pos,dp);
 }

 ################################################################################################################


O(n*n)=> o(n*c)  where C is some upper & lower_bound of possible steps and offset to store the dp
/*
#505C

cur=30000
given postion 'cur', and length 'd', now from cur we can jum to
i)len=d-1, i.e cur+d-1
ii)len=d, i.e. cur+d
iii) len=d+1, i.e. cur+d+1
and collect the values at that position
*/

// Space and time complexity both are out of bound , if use map,unormap,2d array 
//O(n*n)-> fails
const int N=30002;
int dp[N][N];
int a[N];
int fun(int cur, int l){
	if(cur>=N) return 0;
	if(dp[cur][l]!=-1) return dp[cur][l];
	int ans=0;
	if(cur+l-1<N && l-1!=0)
	ans=max(ans,fun(cur+l-1,l-1)+a[cur+l-1]);
	if(cur+l<N && l!=0)
	ans=max(ans,fun(cur+l,l)+a[cur+l]);
	if(cur+l+1<N && l+1!=0)
	ans=max(ans,fun(cur+l+1,l+1)+a[cur+l+1]);
	dp[cur][l]=ans;
	return ans;
}

//Optimization (O(n*C)): here C=sqrt(2*N)
// check for maximum increase len d+k:
/*
{
	last_pos=d+(d+1)+(d+2)+(d+3).....<=N  ( let k be maximum increase)
			=k*d+(1+2+3...k)= (k*k+1)/2 assum k*k=2*N =>k=245
}
similarly for minimum also:
  hence increase or decrease can be b/w range d-245, d-244....d....d+244,d+245
now we use same 2D array bt len= len-offset;
 */
int n,d;
const int N=30002;
int dp[N][500];
int a[N];
// here offset=250
int fun(int cur, int l){
	if(cur>=N) return 0;
	if(dp[cur][l]!=-1) return dp[cur][l];
	int ans=0;
	int l1=d+l-250;
	if(cur+l1-1<N && l1-1!=0 && l1-d>=-250 && l1-d<=250)
	ans=max(ans,fun(cur+l1-1,l1-1-d+250)+a[cur+l1-1]);
	if(cur+l1<N && l1!=0 && l1-d>=-250 && l1-d<=250)
	ans=max(ans,fun(cur+l1,l1-d+250)+a[cur+l1]);
	if(cur+l1+1<N && l1+1!=0 && l1-d>=-250 && l1-d<=250)
	ans=max(ans,fun(cur+l1+1,l1+1-d+250)+a[cur+l1+1]);
	dp[cur][l]=ans;
	return ans;
}


 ################################################################################################################


