#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int lower_bound(std::vector<int>& m,int s){
    int r = m.size();
    int l = 0;
    while(l < r){
        int mid = l + (r-l)/ 2;
        if(m[mid] >= s){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}

int upper_bound(std::vector<int>& m,int s){
    int r = m.size();
    int l = 0;
    while(l < r){
        int mid = r - (r-l)/ 2;
        if(m[mid] <= s){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    return l;
}

int main()
{
    long long  n, k;
    std::vector<int> m;
    std::cin >> n;

    for(int i =0; i < n;++i){
        int t;
        std::cin >> t; 
        m.push_back(t);
    } 
    std::sort(m.begin(),m.end());
    
    std::cin >> k;
    for(int i =0; i < k;++i){
        int l,r;
        std::cin >> l >> r;
        //auto ptr_r = std::upper_bound(m.begin(),m.end(),r);
        //auto ptr_l = std::lower_bound(m.begin(),m.end(),l);
        
        auto ptr_r = upper_bound(m,r);
        auto ptr_l = lower_bound(m,l);

        //auto ptr_r_t2 = std::distance( m.begin(), ptr_r );
        //auto ptr_l_t2 = std::distance( m.begin(), ptr_l );

        int dif = ptr_r - ptr_l;
        //int dif = std::distance(ptr_l, ptr_r);
        std::cout << (dif);
        std::cout << std::endl;
    }
    return 0;
}

