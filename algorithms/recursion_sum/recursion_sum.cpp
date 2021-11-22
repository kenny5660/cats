#include <iostream>
#include <cmath>
#include <string>
#include <vector>
 

std::vector<int> str;
void generateSum(int sum, int last) {
	if (sum == 0) {
		for (auto elem : str) {
			std::cout << elem << " ";
		}
		std::cout << "\n";
	}
	else {
		for (int i = 1; i <= std::min(last,sum); i++) {
			str.push_back(i);
			generateSum(sum - i, i);
			str.pop_back();
		}
	}
}
int main() {
	int n;
	std::cin >> n;
	generateSum(n, n);
	return 0;
}