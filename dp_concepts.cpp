1. #Top downn (memoization):
	int fib(int n){
		if(n<2) return n;
		if(dp[n]!=-1) return dp[n];
		int ans=fun(n-1)+fun(n-2);
		return dp[n]=ans;
	}

2. #Bottom-up
	for(int i=2;i<=n;i++)
	 fib[i]=fib[i-1]+fib[i-2];

3. #push_dp
	fib[i]=fib[i-1]+fib[i-2];
	i.e ith contribute to i+1
	i.e ith contribute to i+2

	for(int i=1;i<=n-2;i++){
		fib[i+1]=fib[i];
		fib[i+2]=fib[i];
	}
