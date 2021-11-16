#include <iostream>
#include <cmath>
#include <vector>
long long  n, k;
std::vector<int> m;

bool comparator(int x){
    int cows = 1;
    int last_cow_coord = m[0];
    for (int i = 0; i < m.size();++i) {
        if (m[i] - last_cow_coord >= x) {
            cows++;
            last_cow_coord = m[i];
        }
    }
    return cows >= k;
}

int search(){
    int r = m.back() - m.front() + 1 ;
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
    std::cout << search();



    return 0;
}
