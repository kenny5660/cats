#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

std::vector<int> a;
int64_t solve(int n){
	int64_t dp[n+1];

	dp[0] = a[1] - a[0];
	dp[1] = a[2] - a[0];
	for (int i = 2; i <n-1;++i){
		dp[i] = std::min(dp[i-1],dp[i-2])+ std::abs(a[i]- a[i+1]) ;
	}
	return dp[n-2];
}

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i < n; ++i){
		int t;
		std::cin >> t;
		a.push_back(t);
	}
	std::sort(a.begin(),a.end());
	std::cout << solve(n);
	return 0;
}