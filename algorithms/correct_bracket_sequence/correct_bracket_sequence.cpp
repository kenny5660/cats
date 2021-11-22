#include <iostream>

#include <cmath>
#include <string>
#include <stack>
#include <sstream>
  
char close2open(char c){
    if(c == ')') return '(';
    if(c == ']') return '[';
    if(c == '}') return '{';
    return '[';
}

int main()
{
    char c;
    std::stack<char> stack;

    while (std::cin >> c)
    {
        if(c == '(' || c == '{' || c == '[' ){
            stack.push(c);
        }
        if(c == ')' || c == '}' || c == ']' ){
            if(stack.empty() || stack.top() != close2open(c)){
                std::cout << "no"<<std::endl;
                return 0;
            }
            stack.pop();

        }
    }
    if(stack.empty()){
        std::cout << "yes"<<std::endl;
    }
    else{
        std::cout << "no"<<std::endl;
    }
    return 0;
}

