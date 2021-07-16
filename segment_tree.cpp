#define lson idx<<1
#define rson idx<<1|1
const int N=1e5;
int t[4*N];
int a[N];
//1 based indexing 
// sum queury

1.range query and point update


void build(int idx,int tl,int tr){
	if(tl==tr){
		t[idx]=a[tl]; return;
	}
	int tm=(tl+tr)/2;
	build(lson,tl,tm); build(rson,tm+1,tr);
	t[idx]=t[lson]+t[rson];
}

int query(int idx,int tl,int tr,int l,int r){
	if(l>r) return 0;
	if(l== tl && r== tr) return t[idx];
	int tm=(tl+tr)/2;
	int left=query(lson,tl,tm,l,min(r,tm));
	int right=query(rson,tm+1,tr,max(l,tm+1),r);
	return left+right;
}  

// point update
void update(int idx,int tl,int tr,int pos,int val){
	if(tl==tr){	
		t[idx]=val; return;
	}
	int tm=(tl+tr)/2;
	if(pos<=tm)  update(lson,tl,tm,pos,val);
    else update(rson,tm+1,tr,pos,val);
    t[idx] = t[lson] + t[rson];
} 




2.// range update and point query
// same build function
// update replace all element in a range by val (no need to store previous val)
// query sum
 
int mark[4*N]; // initially filled with 0
void push(int idx){
	if(mark[idx]){
		t[lson]=t[rson]=t[idx];
		mark[lson]=mark[rson]=1;
		mark[idx]=0;
	}
}

void update(int idx,int tl,int tr,int l,int r,int val){
	if(l>r) return ;
	if(l==tl && r==tr){
		t[idx]=val; mark[idx]=1; return;
	}
	push(idx);
	int tm=(tl+tr)/2;
	update(lson,tl,tm,l,min(tm,r),val);  update(rson,tm+1,tr,max(l,tm+1),r,val);
}

// point sum query 
int query(int idx,int tl,int tr,int pos){
	if(tl==tr)
		return t[idx];
	push(idx);
	int tm=(tl+tr)/2;
	if(pos<=tm)
		return query(lson,tl,tm,pos);
		else
			return query(rson,tm+1,tr,pos);
}

// range sum query
int query(int idx,int tl,int tr,int l,int r)
{
	if(l>r) return 0;
	if(l<=tl && tr<=r)
		return t[idx];
	push(idx);
	int tm=(tl+tr)/2;
	int left=query(lson,tl,tm,l,min(r,tm))
	int right=query(rson,tm+1,tr,max(l,tm+1),r);
	return left+right;
}

3.//range query and range update
// same build function
// range update adding val to all element in the interval (when previous value is needed to get current value)
int lazy[4*N];

void push(int idx){
	t[lson]+=lazy[idx];
	lazy[lson]+=lazy[idx];
	t[rson]+=lazy[idx];
	lazy[rson]+=lazy[idx];
	lazy[idx]=0;
}
	
// reange update(adding)
void upadte(int idx,int tl,int tr,int l,int r, int val){
	if(l>r) return;
	if(l==tl && tr===r){
		t[idx]+=val;
		lazy[idx]+=val;
		return;
	}
	push(idx);
	int tm=(tl+tr)/2;
	update(lson,tl,tm,l,min(tm,r),val);
	update(rson,tm+1,tr,max(l,tm+1),r,val);
	t[v]=t[lson]+t[rson];
}


//query same as second case
