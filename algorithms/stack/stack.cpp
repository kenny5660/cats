#include <iostream>
#include <cmath>
#include <string>

size_t stack_size = 0;
int stack_array[150];

void push(int n){
    stack_array[stack_size] = n;
    stack_size++;
    std::cout << "ok" << std::endl;
}
void pop(){
    std::cout << stack_array[stack_size-1] << std::endl;
    stack_size--;
}

void back(){
    std::cout << stack_array[stack_size-1] << std::endl;
}

void size(){
    
    std::cout << stack_size << std::endl;
}

void clear(){
    stack_size = 0;
    std::cout << "ok" << std::endl;
}


int main()
{
    while (1)
    {
        std::string str_cmd;
        std::cin >> str_cmd;

        if (str_cmd == "push"){
            int n;
            std::cin >> n;
            push(n);
        }
        if (str_cmd == "pop"){
            pop();
        }
        if (str_cmd == "back"){
            back();
        }
        if (str_cmd == "size"){
            size();
        }
        if (str_cmd == "clear"){
            clear();
        }
        if (str_cmd == "exit"){
            std::cout << "bye" << std::endl;
            return 0;
        }

    }
    

    return 0;
}

