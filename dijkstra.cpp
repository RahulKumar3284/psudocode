// dijkstra
vector<int>d(n+1,1e6);
d[src]=0;
set<pair<int,int> >s; s.in(mp(0,src));
while(!s.empty()){
    pair<int,int>p=*s.begin(); s.erase(s.begin());
    if(p.ss==des) break;
    for(int j: g[p.ss]){
        if(wt.find({p.ss,j})!=wt.end() && d[j]>d[p.ss]+wt[{p.ss,j}] ){
            if(d[j]!=1e6)s.erase(s.find(mp(d[j],j)));
            d[j]=d[p.ss]+wt[{p.ss,j}];
            s.in({d[j],j});
        }
    }
}


// To find all shortest path store parents in 2d vector
//SPOJ:SAMER08A
//shotest paths are des->its parent-------
vector<vector<int> >par(n+1);
s.in(mp(0,src));
while(!s.empty()){
    pair<int,int>p=*s.begin(); s.erase(s.begin());
    if(p.ss==des) break;
    for(int j: g[p.ss]){
        if( wt.find({p.ss,j})!=wt.end() && d[j]>d[p.ss]+wt[{p.ss,j}]){
            if(d[j]!=1e6){
                s.erase(s.find(mp(d[j],j)));
            }
            par[j].clear();
            d[j]=d[p.ss]+wt[{p.ss,j}];
            par[j].pb(p.ss);
            s.in({d[j],j});
        }
        else if(wt.find({p.ss,j})!=wt.end() &&  d[j]==d[p.ss]+wt[{p.ss,j}] && d[j]!=1e6){
            par[j].pb(p.ss);
        }
    }
}

