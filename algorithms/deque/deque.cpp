#include <iostream>
#include <cmath>
#include <string>

int head = 0;
int tail = 0;
int deque_size = 0;
const size_t deque_array_size  = 150;
int deque_array[150];

bool empty(){
  return head == tail;
}
void push_back(int x){
    if (head == (tail + 1) % deque_array_size){
        std::cout << "error" << std::endl;
    }
    deque_array[tail] = x;
    tail = (tail + 1) % deque_array_size;
    std::cout << "ok" << std::endl;
    deque_size++;
}
void pop_back(){
    if(empty()){
        std::cout << "error" << std::endl;
    }
    else{
        tail = (tail - 1 + deque_array_size) % deque_array_size;
        std::cout << deque_array[tail] << std::endl;
        deque_size--;
    }
    
}

void push_front(int x){
    if (head == (tail + 1) % deque_array_size){
        std::cout << "error" << std::endl;
    }
    else{
        head = (head - 1 + deque_array_size) % deque_array_size;
        deque_array[head] = x;
        deque_size++;
    }
    
    std::cout << "ok" << std::endl;
}
void pop_front(){
    if(empty()){
        std::cout << "error" << std::endl;
    }
    else{
        std::cout << deque_array[head] << std::endl;
        head = (head + 1) % deque_array_size;
        deque_size--;
    }
    
}

void front(){
    if(empty()){
        std::cout << "error" << std::endl;
    }
    else{
        std::cout << deque_array[head] << std::endl;
    }
}

void back(){
    if(empty()){
        std::cout << "error" << std::endl;
    }
    else{
        std::cout << deque_array[(tail - 1 + deque_array_size) % deque_array_size] << std::endl;
    }
}

void size(){
        std::cout <<deque_size<< std::endl;
}

void clear(){
    head = 0;
    tail = 0;
    deque_size = 0;
    std::cout << "ok" << std::endl;
}


int main()
{
    while (1)
    {
        std::string str_cmd;
        std::cin >> str_cmd;

        if (str_cmd == "push_front"){
            int n;
            std::cin >> n;
            push_front(n);
        }
        if (str_cmd == "push_back"){
            int n;
            std::cin >> n;
            push_back(n);
        }
        if (str_cmd == "pop_front"){
            pop_front();
        }
        if (str_cmd == "pop_back"){
            pop_back();
        }
        if (str_cmd == "front"){
            front();
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

