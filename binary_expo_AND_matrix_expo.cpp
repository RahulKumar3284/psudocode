
ll binary_expo(int a,int n){
	ll res=1;
	while(n){
			if(n%2==1) res*=a;
			a=a*a;
			n=n/2;
	}
	return res;
}

vector<vector<ll> > mult(vector<vector<ll> >&a, vector<vector<ll> >&b ){
	vector<vector<ll> >pro(a.size(),vector<ll>(b[0].size(),0));
	for(int i=0;i<a.size();i++)
		for(int j=0;j<b[0].size();j++)
			for(int k=0;k<a[0].size();k++){
				pro[i][j]+=a[i][k]*b[k][j];
				pro[i][j]%=MOD;
			}
	return pro;
}

//	identity matrix which satisfy base condition
//res[0][0]=1,res[1][1]=1;
vector<vector<ll> >  mat_expo(vector<vector<ll> >&a, ll n){
	vector<vector<ll> >res(a.size(),vector<ll>(a.size(),0));
	for(int i=0;i<a.size();i++) res[i][i]=1; 
	while(n){
		if(n%2)res=mult(res,a);
		a=mult(a,a);
		n=n/2;
	}
	return res;
}
 
struct matrix{
	int a[2][2];
	matrix operator * ( matrix other){
			matrix b={0};
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					for(int k=0;k<2;k++)
						b.a[i][j]+=a[i][k]*other.a[k][j];
			return b;
		}
};

matrix mat_expo(matrix a,int n){
		matrix res={}; 
		while(n>0){
				if(n%2)	res=res*a;
				a=a*a;
				n=n/2;
			}
	return res;
}

