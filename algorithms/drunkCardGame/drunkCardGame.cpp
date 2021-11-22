#include <iostream>

#include <cmath>
#include <string>
#include <deque>
#include <sstream>

int main()
{
    std::deque<int> deq_1,deq_2;
    int card_1,card_2;

    std::string str;
    std::getline(std::cin, str);
    std::istringstream sstr(str);
    int n;
    while(sstr >> n)
        deq_1.push_back(n);
    
    std::getline(std::cin, str);
    std::istringstream sstr2(str);
    while(sstr2 >> n)
        deq_2.push_back(n);

    for(int i = 0; i < 1000002; ++i){
        if(deq_1.empty()){
            std::cout << "second "<< i << std::endl;
            return 0;
        }
        if(deq_2.empty()){
            std::cout << "first " << i << std::endl;
            return 0;
        }

        card_1 = deq_1.front();
        deq_1.pop_front();

        card_2 = deq_2.front();
        deq_2.pop_front();

        if((card_1 > card_2 && !(card_1==9 && card_2==0)) || (card_1==0 && card_2==9)){
            deq_1.push_back(card_1);
            deq_1.push_back(card_2);
        }
        else{
            deq_2.push_back(card_1);
            deq_2.push_back(card_2);
        }
    }
    std::cout << "botva"<< std::endl;

    return 0;
}

