struct edge{
int a,b,wt;
};
//n->vertices, m->edges
vector<edge>v;
vector<int>d(n,INF);

void bellman(int sr){
	d[sr]=0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m;j++){
			if(d[e[j].a]<INF)
				d[e[j].b]=min(d[e[j].b],d[e[j].a]+e[j].wt);
		}
	}
}



void floyed_warshal(){
for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
}
}


			
