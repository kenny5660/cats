#include <iostream>
#include <cmath>
#include <string>
#include <vector>

int64_t solve(int n){
	int64_t dp[n+1];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 2; i <=n;++i){
		int k = i/2;
		if(i%2 == 0){
			dp[i] = dp[k] + 1 ;
		}else{
			dp[i] = dp[2*k] - dp[k-1];
		}
	}
	return dp[n];
}
void print(int64_t x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main() {
	int n;
	std::cin >> n;
	print(solve(n));
	return 0;
}