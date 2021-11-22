#include <iostream>
#include <cmath>
#include <string>

size_t queue_frnt = 1;
size_t queue_rear = 0;
const size_t queue_array_size  = 150;
int queue_array[150];

void push(int n){
    queue_rear++;
    queue_array[queue_rear] = n;
    std::cout << "ok" << std::endl;
}
void pop(){
    int x, h;
    x = queue_array[queue_frnt];
    for(h = queue_frnt; h < queue_rear; ++h) {
        queue_array[h] = queue_array[h+1];
    }
    queue_rear--;
    std::cout << x << std::endl;
}

void front(){
    std::cout << queue_array[queue_frnt] << std::endl;
}

void size(){
    
    std::cout << queue_rear - queue_frnt + 1 << std::endl;
}

void clear(){
    queue_frnt = 1;
    queue_rear = 0;
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
        if (str_cmd == "front"){
            front();
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

