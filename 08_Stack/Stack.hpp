#ifndef STACK_HPP
#define STACK_HPP

namespace StackArray{
    template <typename T, int size = 10>
    class Stack{
    public:
        Stack();

        void        push(const T& val);
        bool        empty() const;
        bool        full() const;
        void        print() const;
        T           pop();
        const T&    top() const;
    private:
        T data[size]; //Array of stack elements
        int top_idx;
    };
}

namespace StackList{
    template <typename T>
    class Stack{
    public:
        Stack();
        ~Stack();

        void        push(const T& val);
        bool        empty() const;
        void        print() const;
        T           pop();
        const T&    top() const;
    private:
        class Node{
        public:
            T data;
            Node<T>* next;
            Node(const T& val=T()) : data(val), next(nullptr) {}
        };
        Node<T>* top_node;
    };
}
#endif