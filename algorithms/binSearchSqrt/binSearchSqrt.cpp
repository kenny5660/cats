#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


bool comparator(uint64_t x,uint64_t q){

    return x <= q/x;
}

uint64_t search(uint64_t q){
    uint64_t r = q;
    uint64_t l = 0;
    while(r - l > 1){
        uint64_t mid = (l + r)/ 2;
        if(comparator(mid,q)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    if (q == 1){
        return 1;
    }
    return l;
}

int main()
{
uint64_t t;
    while(std::cin >> t){
        std::cout << search(t);
        std::cout << std::endl;
    } 
    
    return 0;
}
