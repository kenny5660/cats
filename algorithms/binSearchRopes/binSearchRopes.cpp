#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
long long  n, k;
std::vector<int> m;

bool comparator(int x){
    int ropes = 0;
    for (int i = 0; i < m.size();++i) {
        ropes += m[i]/x;
    }
    return ropes >= k;
}

int search(){
    int r = m.back()+ 1;
    int l = 0;
    while(r - l > 1){
        int mid = (l + r)/ 2;
        if(comparator(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return l;
}

int main()
{
    std::cin >> n >> k;

    for(int i =0; i < n;++i){
        int t;
        std::cin >> t; 
        m.push_back(t);
    } 
    std::sort(m.begin(),m.end());
    std::cout << search();
    return 0;
}
