// coordinate compession 
// BYTESE2 
//n<=100 && a[i],b[i]<1e8

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	int n; cin>>n;
	map<int,int>m;
	vector<int>v;
	vector<int>a(n);
	vector<int>b(n);
	for(int i=0;i<n;i++){ cin>>a[i]>>b[i]; if(m[a[i]]==0){ m[a[i]]=1; v.pb(a[i]);} if(m[b[i]]==0){m[b[i]]=1; v.pb(b[i]);} }
	sort(v.begin(),v.end());
	m.clear();
	for(int i=0;i<v.size();i++){
			m[v[i]]=i;
			//cout<<v[i]<<" "<<m[v[i]]<<endl;
		}
	vector<int>pre(v.size(),0);
	for(int i=0;i<n;i++){
			pre[m[a[i]]]++;
			pre[m[b[i]]]--;
	}
	for(int i=1;i<v.size();i++)
		pre[i]+=pre[i-1];
		int maxi=-1e9;
	for(int i=0;i<v.size();i++){
		maxi=max(maxi,pre[i]);
	}
	cout<<maxi<<endl;
	}
return 0;
}
