#include "Stack.hpp"
#include "Stack.cpp"

int main(void){
    StackArray::Stack<char, 30> stack;

    int i = 0;
    while(i < 26){
        stack.push(i+'A');
        i++;
    }
    stack.print();

    while(!stack.empty()){
        std::cout << stack.pop() << std::endl;
    }
    return 0;
}   