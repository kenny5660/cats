#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>


int64_t solve(int64_t n){
	int64_t dp[n+1];
	int64_t ans[n+1];

	dp[0] = 0;
	dp[1] = 0;

	if(n == 1){
		std::cout << "0" << std::endl;
		std::cout << "1" << std::endl;
		return 0;
	}

	for (int64_t i = 2; i <=n;++i){
		int64_t t;
		t= dp[i-1] + 1;
		if (i%2 == 0){
			t = std::min(t, dp[i/2]+1);
		}
		if (i%3 == 0){
			t = std::min(t, dp[i/3]+1);
		}
		dp[i] = t;
	}
	std::cout << dp[n] << std::endl;

	
	int64_t i = n;
	int64_t k = dp[n]-1;
	ans[k+1] = n;
	while (i > 1){
		if (dp[i] == (dp[i-1]+1)){
			ans[k] = i - 1;
			i -= 1;
			k--;
			continue;
		}
		if (i%2 == 0 && dp[i] == dp[i/2]+1){
			ans[k] = i / 2;
			i = i / 2;
			k--;
			continue;
		}
		ans[k] = i /3;
		i = i /3;
		k--;
	}
	for (int64_t i = 0; i<= dp[n]; ++i){
		std::cout << ans[i] << " ";
	}
	return 0;
}

int main() {
	int n;
	std::cin >> n;
	solve(n);
	
	return 0;
}