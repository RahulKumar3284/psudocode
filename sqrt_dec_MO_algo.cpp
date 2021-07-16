                                                        SQRT Decompostion
// GIVEAWAY Spoj : point update(i,c): a[i]=c     range query(l,r,c) : number of elements from l to r :  >=c
//vector v: input array
// B- Block size
// p[i]-stores elements in ith block
//0-Indexing


int  B=ceil(sqrt(n));
vector<vector<int> >p(B);

//inserting each elements into its corresponding block
for(int i=0;i<n;i++) p[i/B].pb(v[i]);
//sorting each block
for(int i=0;i<B;i++) sort(p[i].begin(),p[i].end());


int query(int l,int r,int c){
    int cl=l/B, cr=r/B, res=0;
    if(cl==cr){
        for(int i=l;i<=r;i++) if(v[i]>=c) res++;
    }
    else{
        for(int i=l;i<(cl+1)*B;i++)  // proceesing leftmost block
                if(v[i]>=c) res++;
        for(int i=(cr)*len;i<=r;i++) // proceesing righmost block
                if(v[i]>=c) res++;
        for(int i=cl+1;i<cr;i++){ // procing middle block
                res+=lower_bound(p[i].begin(),p[i].end(),c)-p[i].begin();
        }
    }
    return res;
}

// v[idx]=newVal;
void update(int idx, int newVal){
    int prev=v[idx];
    int cl=l/len;
    int idxInP=lower_bound(p[cl].begin(),p[cl].end(),prev)-p[cl].begin();
    p[cl][idxInP]=newVal; v[idx]=newVal;  // updation
    sort(p[cl].begin(),p[cl].end());
}




//     SUM QuERY
vector<int>p(B);
for (int i=0; i<n; ++i) p[i /B] += v[i];
//sum from [l,r]
int query(int l,int r){
    int cl=l/B, cr=r/B, res=0;
    if(cl==cr){
        for(int i=l;i<=r;i++) res+=v[i];
    }
    else{
        for(int i=l;i<(cl+1)*B;i++)  // proceesing leftmost block
                res+=v[i];
        for(int i=(cr)*len;i<=r;i++) // proceesing righmost block
            res+=v[i];
        for(int i=cl+1;i<cr;i++){ // procing middle block
            res+=p[i];
        }
    }
    return res;
}


/*##########################################################################################################################################################################*/
                                                            MO's Algorithm
//0-Indexing, (l,r) left and right boundary of idxTH query

struct node{
    int l,r,idx;
} q[Q];
 
// function to sort queries on the basis of increasing value of (l i.e left block number) ,incase of tie on the basis of valur of r
bool cmp(node a, node b){
   if((a.l/B) == (b.l/B) )
       return a.r < b.r;
    return (a.l/B)<(b.l/B);
}
 
//sort(q,q+Q,cmp);

// This is base on Dquery, finding number of distinct elements in range query

//this will add current elements into our querry range (cl,cr)
// res is a global variable which stores our answer
int res=0;
void add(int pos){
  cnt[a[pos]]++;
  if(cnt[a[pos]]==1) res++;
}
 
//this will add current elements into our querry range (cl,cr)
void remove(int pos) {
    cnt[a[pos]]--;
    if(cnt[a[pos]]==0) res--;
}
 

//while(cl>q[i].l) need to move left and add elements to our answer       while(cr<q[i].r) need to move right and add elements to our answer
//while(cl<q[i].l) need to move right and Remove elements to our answer    while(cr>q[i].r) need to move left and Remove elements to our answer
void moAlgo(){
    int cl=0,cr=-1;
    for(int i=0;i<Q;i++){
        while(cl>q[i].l){
            cl--; add(cl);
        }
        while(cr<q[i].r){
            cr++; add(cr);
        }
        while(cl<q[i].l){
            remove(cl); cl++;
        }
        while(cr>q[i].r){
            remove(cr); cr--;
        }
        ans[q[i].idx]=res;
      }
    //print our answer
    for(int i=0;i<Q;i++) cout<<ans[i]<<" ";
    cout<<endl;
    
}

