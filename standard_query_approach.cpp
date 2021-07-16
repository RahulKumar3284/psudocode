1.//finding number of distinct charcter in a range query and point update:
//use set for position of each character, and lower and upper_bound for range query
(1234D)
// str[p]=ch;
void point_update{
	int p;char ch; cin>>p>>ch;
	pos[str[p-1]-'a'].erase(p);
	str[p-1]=ch;
	pos[str[p-1]-'a'].in(p);
}
// number of unique charcter b/w str[l]....str[r]
void range_query{
	int l,r; cin>>l>>r;
	int ans=0;
	for1(i,0,26){
		ans+=(pos[i].lower_bound(l)!=pos[i].upper_bound(r));
	}
	cout<<ans<<endl;
}

//using SegTREE use bitmask to count number of distinct charchters
void build(int v,int tl,int tr){
	if(tl==tr){
		t[v]=1<<(str[tl]-'a'); return;
	}
	int tm=(tl+tr)/2; build(2*v,tl,tm); build(2*v+1,tm+1,tr);
	t[v]=t[2*v]|t[2*v+1];
}
int query(int v,int tl,int tr,int l,int r){
	if(l>r) return 0;
	if(l== tl && r== tr) return t[v];
	int tm=(tl+tr)/2; int left=query(2*v,tl,tm,l,min(r,tm)); int right=query(2*v+1,tm+1,tr,max(l,tm+1),r);
	return (left|right);
}  
void update(int v,int tl,int tr,int pos,char ch){
	if(tl==tr){	
		t[v]=1<<(ch-'a'); return;
	}
	int tm=(tl+tr)/2;
	if(pos<=tm)  update(v*2,tl,tm,pos,ch);
	else update(v*2+1,tm+1,tr,pos,ch); 
	t[v]=t[2*v]|t[2*v+1];
} 

#############################################################################################################################################

2. (474F) finding the gcd of all numbers b/w [l,r] and cnt of this gcd in this range
//(i) segmet tree + unordered_map<int,vector<int> >um ( um[a]=stores index of its occurance) 
// segemt tree to find gcd,  map to  find count using binary search on it

//(ii) only using segment tree
//t->to store gcd,  cnt->cont of gcd
void build(int idx,int tl,int tr){
	if(tl==tr){
		t[idx]=a[tl]; cnt[idx]=1; return;
	}
	int tm=(tl+tr)/2;
	build(lson,tl,tm); build(rson,tm+1,tr);
	t[idx]=gcd(t[lson],t[rson]);
	cnt[idx]=(t[idx]==t[lson])*cnt[lson]; cnt[idx]+=(t[idx]==t[rson])*cnt[rson];
}
pair<ll,ll> query(int idx,int tl,int tr,int l,int r){   //(gcd,cnt)
	if(l>r) return {0LL,0LL};
	if(l== tl && r== tr) return {t[idx],cnt[idx]};
	int tm=(tl+tr)/2;
	pair<ll,ll>left=query(lson,tl,tm,l,min(r,tm)); pair<ll,ll>right=query(rson,tm+1,tr,max(l,tm+1),r);
	pair<ll,ll>ans; ans.ff=gcd(left.ff,right.ff); ans.ss=0;
	if(ans.ff==left.ff) ans.ss+=left.ss; if(ans.ff==right.ff) ans.ss+=right.ss;
	return ans;
}  

#############################################################################################################################################

// 914 D
//finding whather a range's GCD is X or not .....(we can leave atmost one element in that range)
// Approch:
// traverse in segmet tree , if gcd is
// i) divisible by X then return
// ii) else   count number of elements in that range which is not divisible by X, if( it is greater than 2) return false;
int cnt=0;
bool query(int idx,int tl,int tr,int l,int r,ll x){
    if(l>r) return true;
    if(cnt>1) return false;
    if(l== tl && r== tr){
        if(t[idx]%x==0){ return true;}
        else{
                if(tl==tr){
                    if(t[idx]%x!=0){
                        cnt++; return (cnt<2);
                    }
                    else return true;
                }
                else{
                    int tm=(tl+tr)/2;
                    bool p=query(lson,tl,tm,l,min(r,tm),x);
                    bool q=query(rson,tm+1,tr,max(l,tm+1),r,x);
                    return (cnt<2);
                }
        }
    }
    int tm=(tl+tr)/2;
    bool p=query(lson,tl,tm,l,min(r,tm),x);
    bool q=query(rson,tm+1,tr,max(l,tm+1),r,x);
    return (cnt<2);
}

#############################################################################################################################################
