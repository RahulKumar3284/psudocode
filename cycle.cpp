vector<vector<int> >g;
int st=-1,end=-1;
int vis[N];
int pae[N];
// undirected graph 
bool dfs(int i){
	vis[i]=1;
	for(int j=0;j<g[i].size();j++){
			int c=g[i][j];
			if(c==par[i]) continue; // removed in case of directed  
			if(vis[c]==0){
				par[c]=i;
				if(dfs(i))
					return true;
			}
			else if(vis[c]) // in case of directed it should be vis[c]==1
			{
				end=c;
				st=i;
				return true;
			}
	}
	vis[i]=2;
	return false;
}

void cyle(){
	for(int i=0;i<n;i++){
		if(vis[i]==0 && dfs(v)
			break;
		}
	if(st==-1)
		cout<<"-1"<<endl;
		else{
			vector<int>cy;
			cy.pb(st);
			for(int v=end; v!=st;v=par[v])
				cy.pb(v);
			cy.pb(st);
			revese(cy.begin(),cy.end());
			
