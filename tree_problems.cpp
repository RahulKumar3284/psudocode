//Range-Query on a tree

//proble:383C: add val to cur node and its grandchild and grandchild's grandchild.. so on 
// and add -val to its child and its child's grand child .. so on

//1. method split nodes having even ht and odd  ht
//2. add +val to all nodes in its subtree having same parity as given node
//3. add -val to all nodes in its subtree having opposite parity

//Code:

//bit[0][N]-> perform query on 0 parity nodes
//bit[1][N]-> perform query on 1 parity nodes
ll bit[2][N];
void add(int idx,ll val,int p){
    for(;idx<N;idx+=idx&-idx) bit[p][idx]+=val;
}
void rangeadd(int l,int r,ll val,int p){
    add(l,val, p); add(r+1,-val,p);
}
ll point_query(int idx,int p) {
    ll ret = 0;
    for (; idx > 0; idx-=idx&-idx) ret+=bit[p][idx];
    return ret;
}

int h[N];
int tin[N],tout[N];
int t=0;
void dfs(int cur, int par1,int ht){
    tin[cur]=++t;
    h[cur]=ht;
    for(int j: g[cur]){
        if(par1!=j) dfs(j, cur,ht+1);
    }
    tout[cur]=t;
}

    dfs(1,0,0);
    for1(i,1,n+1){
        rangeadd(tin[i],tin[i],a[i],h[i]%2);  // updating/adding initial vaule(a[i]) of each node
    }
    while(m--){
        int typ; cin>>typ;
        if(typ==1){
            int x,val; cin>>x>>val;
            rangeadd(tin[x],tout[x],val,h[x]%2);   // range update on same parity childs and given node
            rangeadd(tin[x],tout[x],-val,(h[x]%2==0)?1:0);   // range update on opposite parity childs and given node
        }
        else{
            int x; cin>>x;
            ll ans=point_query(tin[x],h[x]%2);  // value of that node
            cout<<ans<<endl;
        }
    }



//###################################################################################################