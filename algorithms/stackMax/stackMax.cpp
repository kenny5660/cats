#include <iostream>
#include <cmath>
#include <string>
#include <vector>

size_t stack_size = 0;
std::vector<std::pair<int,int>> stack_array;

void push(int n){
    int max_el = stack_size == 0 ? n : std::max(n, stack_array[stack_size-1].second);
    if(stack_size >= stack_array.size()){
        stack_array.push_back(std::make_pair(n,max_el));
    }else{
        stack_array[stack_size] = std::make_pair(n,max_el);
    }

    stack_size++;
}
void pop(){
    //std::cout << stack_array[stack_size-1].first << std::endl;
    stack_size--;
}
void max(){
    std::cout << stack_array[stack_size-1].second << std::endl;
}



int main()
{
    int n;
    std::cin >>n;
    for(int i = 0; i < n;++i)
    {
        std::string str_cmd;
        std::cin >> str_cmd;

        if (str_cmd == "push"){
            int v;
            std::cin >> v;
            push(v);
        }
        if (str_cmd == "pop"){
            pop();
        }
        if (str_cmd == "max"){
            max();
        }
    }
    

    return 0;
}

