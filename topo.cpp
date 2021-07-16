vector<int>o;
void topo(int cur){
	vis[cur]=1;
	for(int j:g[cur]){
		if(vis[j]) continue;
		topo(j);
	}
	o.pb(cur);
}

