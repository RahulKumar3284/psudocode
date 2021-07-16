https://www.quora.com/How-do-I-find-the-diameter-of-a-tree
// problem 456E civilisation
int farthest=0,maxx=0; // farthest is fat=rthest node, maxx is maximum diametre

// x is current node , p is its parent , tot in current depth

int dfs(int x,int p,int tot){
	if(tot>maxx) farthest=x,maxx=tot;
	for(int i=0;i<g[x].size();i++){
		if(g[x][i]==p) continue;
		dfs(g[x][i],x,tot+1);
	}
}


// do a travesal from a random x to find farthst node from it
// now, find the maximum depth( farthest node's distance from it is our ans
int dia(int x){
	farthest=x;
	maxx=0;dfs(x,0,0); x=farthest,farthest=0; 
	maxx=0;dfs(x,0,0);
	return maxx;
}
		
//By chenyewei_1234, contest: Codeforces Round #260 (Div. 1), problem: (C) Civilization, Accepted, #, Copy

//using bfs
main function
{
bfs(1);
farthest=farthest();
bfs(farthest);
farthest=farthes();
}

int farthest(){
	int ans=1;
	for(int i=1;i<=n;i++)
	if(dis[i]>dis[ans) ans=i;
return ans;	
}
