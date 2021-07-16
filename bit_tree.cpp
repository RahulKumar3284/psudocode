// applicable for reversible function;sum , sub,
//preprocess: O(Nlog(N)), query: O(logN)
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

ll val(int idx){
	if(idx==1) return sum(1);
	else return (sum(idx)-sum(idx-1));
}

// binary lifting in BIT tree
//int n; maximum size;

// this funtion will return the index of lowest position whose presum is >= required sum;
int findidx(int reqsum){
    int cur=0, cursum=0;
    for(int i=log2(n);i>=0;i--){
        if(bit[cur+(1<<i)]+cursum<reqsum){
            cur+=(1<<i);
            cursum+=bit[cur];
        }
    }
    return cur+1;
}



//using binary search

int findidx(int reqsum){
    int lo=1,hi=N;
    while(lo<hi){
        int mid=(lo+hi)/2;
        int cursum=sum(mid);
        if(cursum>=reqsum) hi=mid;
        else lo=mid+1;
    }
    return lo;
}

//for point point update .i.e a[i]=y
// a[i]=y-a[i];
//update add(i,a[i]);

// if deals with xor a[i]=a[i]^y;
//then
//a[i]=a[i]^val and
//add(i,val)


//if we want to update a[i]=val in xor query
//add(i,a[i]^val);  a[i]for eleminating previous a[i] values
//a[i]=val;


//NOTE: if we wanna perform a range update to add a value val to all from l to r:
// then in this case value at index is given by its prefix A[i]=sum[1:i] i.e. sum(i)  /i.e. range update and point query
//whereas in case of point query sum(i) gives A[1]+A[2]+..A[i];

// add val to all elements between l to r
void rangeadd(int l,int r,ll val){
	add(l,val); add(r+1,-val);
}

//value at ith index in range query
ll point_query(int idx) {
    ll ret = 0;
    for (++idx; idx > 0; idx-=idx&-idx) ret+=bit[idx];
    return ret;
}


//for two dimensional array
//sum[i,j] gives the sum of the rectangle whose ends points are (0,0) ,(0,j) ,(i,0) ,(i,j);

ll sum(int x, int y) {
    ll ret = 0;
    for(int i=x;i>0;i-=i&-i) for (int j=y; j>0; j-=j&-j) ret += bit[i][j];
    return ret;
}

// sum of rectangle [x1,y1] to [x2,y2]
ll rect_sum(int x1, int y1, int x2 ,int y2){
    ll ans=sum(x2,y2)-sum(x2,y1-1)-sum(x1-1,y2)+sum(x1-1,y1-1);
    return ans;
}
// this will add value to rectangle [x,y] to [N,M]
void add(int x, int y, int val) {
        for (int i=x;i<N; i+=i&-i)
            for (int j=y;j<M; j+=j&-j)
                bit[i][j] += val;
}
// this will update [i,j]th element by val i.e. a[i][j]=val
void point_update
 (int x,int y,ll val){
    ll res=rect_sum(x,y);
    add(x,y,val-res);
}
void rect_add(int x1, int y1, int x2, int y2, int val){
    add(x1,y1,val); add(x1,y2+1,-val); add(x2+1,y1,-val); add(x2+1,y2+1,val);
}
