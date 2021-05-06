#graph
n=|V| , m=|E|


//vector<vector<int> >g; 
//O(n+m)
void bfs(int i){
	d[i]=0;
	queue<int>q;
	q.push(i);
	vis[i]=1;
	while(!q.empty()){
		int i=q.front();
		q.pop();
		for(int j=0;j<g[i].size();j++){
			 int c=g[i][j];
			 if(vis[c]==0){
				vis[c]=1;
				d[c]=d[i]+1;
				q.push(c);	
		}
	}
}

// multisource bfs
Concept : 
You push all the cells/nodes/vertices which are the so called "Source"/ Starting Vertices in a queue.
In these types of problems you generally have to find the shortest Distance/Cost of reaching all the vertices.
After pushing all the source vertices into the queue(priority queue/set)
and performing the usual Djikstra you get your desired answer.




//vector<vector<pair<int,int> > >g;  //ff=vertex, ss=wt
//O(m)
void bfs01(int i){
	d[i]=0;
	set<pair<int,int> >s; // (wt,vertex)
	s.in(mp(0,i);
	while(!s.empty()){
		int i=(*s.begin()).ss;
		s.erase(*s.begin());
		for(int j=0;j<g[i].size();j++){
			int c=g[i][j].ff;
			int w=g[i][j].ss;
			
			if(d[i]+w<d[c]){
					s.erase(mp(d[c],c));
					d[c]=d[i]+w;
					s.in(mp(d[c],w));
			}
		}
	}	
}


//O(n+m)
void dfs( int i){
	vis[i]=1;
	for(int j=0;j<g[i].size();j++){
			int c=g[i][j];
			if(!vis[c])
				dfs(c);
		}
}



vector<vector<pair<int,int> > >g;  // (vertex,wt)
int d[10008] ///filed with INF(M);
//O((n+m)logn)

int dij(int i){
set<pair<int,int> >s;  //(wt,vert)
d[i]=0;
s.in(mp(0,i));
while(!s.empty()){
	pair<int,int>p=*s.begin();
	s.erase(s.begin());
	int j=p.ss;
    if(j==des)
      return d[des];
	for(int k=0;k<g[j].size();k++){
			if(d[j]+g[j][k].ss <d[g[j][k].ff]){
				if(d[g[j][k].ff]!=M)
					s.erase(mp(d[g[j][k].ff],g[j][k].ff));
				d[g[j][k].f]=d[j]+g[j][k].s;
				s.in(mp(d[g[j][k].f],g[j][k].f));
			}
	}
}
return d[des];
}


//O((n+m)*logn)  // src=1;
int prims( ){   
	 d[1]=0; //other with INF
	 set<pair<int,int> >s;
	 s.insert(mp(0,1));
	 int ans=0; 
	 while(!s.empty()){
	 	pair<int ,int>p=*s.begin();
	 	s.erase(s.begin());
	 	int cost=p.ff;
	 	int i=p.ss;
	 	vis[i]=1;
	 	if(cost==1e12) break;
	 	ans+=cost;
	 	for(int j=0;j<g[i].size();j++){
	 		int k=g[i][j].first;
	 		int cost=g[i][j].second;
	 		if(!vis[k] && (d[k]>cost)){
	 		  	  if(d[k]==1e12){
						d[k]=cost;
						s.insert(mp(d[k],k));
				   }
				   else{
						s.erase(mp(d[k],k));
						d[k]=cost;
						s.insert(mp(d[k],k));
				   }
	 		  	
			}	
		}
	}
	return ans;	
}



vector<int> par,siz;

void make_set(int v) {
    par[v] = v;	siz[v] = 1;
}

int find_set(int v) {
if(v==par[v]) return v;
return par[v]=find_set(par[v]);
}

void union_sets(int a, int b) {
a=find_set(a);
b=find_set(b);
    if(a!=b) {
        if (siz[a]<siz[b]) swap(a,b);
		par[b]=a;
		siz[a]+=siz[b];
    }
}

struct Edge {
    int u, v, wt;
    bool operator<(Edge const& other) {
        return wt < other.wt;
    }
};
//vector<Edge>g;
int krus( ){
	
int cost = 0;
for(int i = 0; i < n; i++)
    make_set(i);
sort(all(g));

for(int i=0;i<n;i++) {
    if (find_set(g[i].u) != find_set(g[i].v)) {
        cost+=g[i].wt;
        union_sets(g[i].u,g[i].v);
    }
   }
   return cost;
}


//ssc
g->graph 
g1->transpose graph
void dfs1(ll i){
	vis[i]=true;
	for(ll j=0;j<g1[i].size();j++)
	   if(!vis[g1[i][j]]) dfs1(g1[i][j]); 
	   order.push_back(i);
}
 
void dfs2(ll i, ll c){
	vis[i]=false;
	grp[i]=c;
	for(ll j=0;j<g[i].size();j++)
	      if(vis[g[i][j]])
	        dfs2(g[i][j],c);	
}
 
int scc(){
	memset(vis,0,sizeof(vis));
        for (int i=0;i<n;i++)
            if(!vis[i]) dfs1 (i);
         int compo=0;
        for (int i=0;i<n;++i) {
            int v=order[n-1-i];
            if (!vis[v]) {
                dfs2 (v);
                compo++;
            }
        }
        return compo;	
}

