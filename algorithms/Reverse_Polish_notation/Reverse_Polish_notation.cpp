#include <iostream>

#include <cmath>
#include <string>
#include <stack>
#include <sstream>

int main()
{
    std::string str;
    std::stack<int> stack;

    while (std::cin >> str)
    {
        if(str == "-"){
            int op1 = stack.top();
            stack.pop();
            int op2 = stack.top();
            stack.pop();
            stack.push(op2-op1);
            continue;
        }
        if(str == "+"){
            int op1 = stack.top();
            stack.pop();
            int op2 = stack.top();
            stack.pop();
            stack.push(op1+op2);
            continue;
        }
        if(str == "*"){
            int op1 = stack.top();
            stack.pop();
            int op2 = stack.top();
            stack.pop();
            stack.push(op1*op2);
            continue;
        }

        stack.push(std::stoi( str ));

    }
    std::cout << stack.top()<<std::endl;
    
    return 0;
}

