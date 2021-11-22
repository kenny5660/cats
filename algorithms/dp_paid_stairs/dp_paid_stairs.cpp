#include <iostream>
#include <cmath>
#include <string>
#include <vector>

std::vector<int> a;
int64_t solve(int n){
	int64_t dp[n+1];

	dp[0] = 0;
	dp[1] = a[0];
	for (int i = 2; i <=n;++i){
		dp[i] = std::min(dp[i-1],dp[i-2])+ a[i-1];
	}
	return dp[n];
}

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i < n; ++i){
		int t;
		std::cin >> t;
		a.push_back(t);
	}
	std::cout << solve(n);
	return 0;
}