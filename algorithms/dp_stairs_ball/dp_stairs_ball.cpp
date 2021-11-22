#include <iostream>
#include <cmath>
#include <string>
#include <vector>

int64_t solve(int n){
	int64_t dp[n+1];
	n--;
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;
	for (int i = 3; i <=n;++i){
		dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]);
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