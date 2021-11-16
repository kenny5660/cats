#include <iostream>
#include <cmath>
#include <vector>
long long  n, k;
std::vector<int> m(10000);
bool search(std::vector<int>& m,int s); 

int main()
{
    std::cin >> n >> k;

    for(int i =0; i < n;++i){
        int t;
        std::cin >> t; 
        m.push_back(t);
    } 

    for(int i =0; i < k;++i){
        int t;
        std::cin >> t; 
        std::cout << (search(m,t) ? "YES":"NO");
        std::cout << std::endl;
    }


    return 0;
}

bool search(std::vector<int>& m,int s){
    int r = m.size();
    int l = 0;
    while(l <= r){
        int mid = (l + r)/ 2;
        if(m[mid] == s){
            return true;
        }
        if(m[mid] > s){
            r = mid -1;
        }
        else{
            l = mid + 1;
        }
    }
    return false;
}