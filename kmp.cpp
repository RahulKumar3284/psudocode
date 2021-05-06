#include<bits/stdc++.h>
using namespace std;

//KMP
// implementation 1:
//π[i] is the length of the longest proper prefix of the substring s[0…i]
//which is also a suffix of this substring.
vector<int>prefix(string &s){
	vector<int>pi(s.size()+1,-1);
	for(int i=-1,pos=0;pos<s.size();pi[++pos]=++i)
			while(i>=0 and s[i]!=s[j])i=pi[i];
	return pi;
}

where 
for(x=pos;x>-1 and s[x]!=ch; x=pi[x]);
this return the index  of charter having suffix equal or less than ending at ch
// probblem 1163d

// implementation 2:
//π[i] is the length of the longest proper prefix of the substring s[0…i]
//which is also a suffix of this substring.
vector<int> prefix_function(string &s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}


//raahraah
imp2= 0 0 0 0 1 2 3 4 
imp1= -1 0 0 0 0 1 2 3 4 

sssss
imp1= 0 1 2 3 4 
imp2= -1 0 1 2 3 4 





int main(){
	string s;
	cin>>s;
	vector<int>v1=prefix_function(s);
	vector<int>v2=prefix(s);
	for(int i=0;i<v1.size();i++)
		cout<<v1[i]<<" ";
	cout<<endl;
	for(int j=0;j<v2.size();j++)
		cout<<v2[j]<<" ";
	cout<<endl;
return 0;
}
