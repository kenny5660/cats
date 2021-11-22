#include <iostream>
#include <cmath>
#include <string>
#include <vector>
 
std::vector<int> str;
void generateStr(int n, int maxelm) {
	if (n == 0) {
		for (auto elem : str) {
			std::cout << elem;
		}
		std::cout << std::endl;
	}
	else {
		for (int i = maxelm; i >=0; i--) {
			str.push_back(i);
			generateStr(n - 1, maxelm);
			str.pop_back();
		}
	}
}
int main() {
    int n;
    std::cin >> n;
	generateStr(n, 1);
	return 0;
}