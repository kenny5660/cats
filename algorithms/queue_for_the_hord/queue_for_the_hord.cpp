#include <iostream>
#include <cmath>
#include <string>

struct Node
{
    int data;
    Node *next;
    Node *prev;
};
struct Queue
{
    int size;
    Node *first;
    Node *last;
    Node *center;
};

void push(Queue & q, int data){
    Node * new_node = new Node;
    new_node->data = data;
    q.size ++;
    if(q.first == nullptr){
        q.first = new_node;
        q.last = new_node;
        q.center = new_node;
        new_node->next = nullptr;
        new_node->prev = nullptr;
    }else{
        new_node->next = q.last;
        q.last->prev = new_node;
        q.last = new_node;
        new_node->prev = nullptr;

        if(q.size % 2 != 0){
            q.center = q.center->prev;
        }
    }

    
    

}
void push_center(Queue & q, int data){
    Node * new_node = new Node;
    new_node->data = data;
    q.size ++;
    if(q.center == nullptr){
        q.first = new_node;
        q.last = new_node;
        q.center = new_node;
        new_node->next = nullptr;
        new_node->prev = nullptr;
    }
    else{
        if(q.center->prev != nullptr){
            q.center->prev->next = new_node;
        }
        
        new_node->next = q.center;
        new_node->prev = q.center->prev;
        q.center->prev = new_node;
        q.center = new_node;
        if(new_node->prev == nullptr){
            q.last = new_node;
        }
        if(q.size % 2 == 0){
            q.center = q.center->next;
        }
    }

}
int pop(Queue & q){
    int data = q.first->data;
    Node* old_first = q.first;
    q.size--;
    if( q.first->prev != nullptr){
    q.first = q.first->prev;
    q.first->next = nullptr;
    if(q.size % 2 != 0){
        q.center = q.center->prev;
    } 
    }
    delete old_first;
    
    

    return data;
}


void clear(Queue & q){
    q.size = 0;
    q.first = nullptr;
    q.last = nullptr;
    q.center = nullptr;
}


int main()
{
    int n;
    Queue q;
    clear(q);
    std::cin >> n;
    for (int i = 0; i <n;++i)
    {
        std::string str_cmd;
        std::cin >> str_cmd;

        if (str_cmd == "+"){
            int x;
            std::cin >> x;
            push(q,x);
        }
        if (str_cmd == "*"){
            
            int x;
            std::cin >> x;
            push_center(q,x);
        }
        if (str_cmd == "-"){
           std::cout << pop(q) << std::endl;
        }
    }
    

    return 0;
}

