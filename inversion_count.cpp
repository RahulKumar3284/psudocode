 // Count Number of inversion in array A using merge sort; T: O(nlog(n))
//eg problem : 1430E
 int merge(vector<int>&A,vector<int>&B,int l,int r){
      if(l==r) return 0;
      int mid=(l+r)/2;
      int ans=merge(A,B,l,mid);
      ans+=merge(A,B,mid+1,r);
      int i1=l,i2=mid+1,k=i1;
      while(i1<=mid && i2<=r){
        if(A[i1]<=A[i2]){
          B[k++]=A[i1++];
        }else{
          ans+=(mid-i1+1);
          B[k++]=A[i2++];
        }
      }
      while(i1<=mid){
        B[k++]=A[i1++];
      }
      while(i2<=r){
        B[k++]=A[i2++];
      }
      for(int i=l;i<=r;i++) A[i]=B[i];
      return ans;
    }



//using BIT TREE 
 
//here we travese from back  
//eg array is 0 2 6 3 1
/* then we start our loop from i=5 
 1. find the total number of frequecy already visited which have value less than v[i=5].e.g 1 here freq=0; add this to our answer
 2. then update the frequecy add(idx=a[i],1);
 repeate this process till i=0; */

const int N=2e5+5;
ll bit[N];

void add(int idx,ll val){
  for(;idx<N;idx+=idx&-idx) bit[idx]+=val;
}

ll sum(int idx){
  ll res=0;
  for(;idx>0;idx-=idx&-idx)
      res+=bit[idx];
  return res;
}

main(){
  ll ans=0;
  for(int i=n-1;i>=0;i--){
    ans+=sum(a[i]);
    add(a[i]+1,1);
  }
  cout<<ans<<endl;
}