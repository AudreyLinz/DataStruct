#include <iostream>

class Node {
public:
  int data;
  Node* next;

  Node(int value) {
    data = value;
    next = nullptr;
  }
};

class Queue {
private:
  Node* front;
  Node* rear;

public:
  Queue() {
    front = nullptr;
    rear = nullptr;
  }

  void enqueue(int value) {
    Node* newNode = new Node(value);
    if(front==nullptr){
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

  }

  void dequeue() {
    if(front==nullptr){
      return;
    }
    Node* to_delete = front;
    front = front->next;
    delete to_delete;

    if(front==nullptr){
      rear==nullptr;
    }
  }
};

struct Node { //linked list
    int data;
    Node* next;
};

bool search(Node* head, int k){ //returns true if k in linked list, other wise false
  if(head==nullptr){
    return false;//empty list
  }
  Node* cur = head;
  while(cur!=nullptr){
    if(cur->data==k){
      return true; //finds k
    }
    cur = cur->next;
  }
  return false; //list doesnt have k
} 

void deleteValue(Node*& head, int target) {
  if(head == nullptr){ //empty
    return;
  } else if (head->data==value){ //if head equal value
    Node* to_delete = head;
    head = head->next;
    delete = to_delete;
  } else {
    Node* cur = head;
    while(cur->next!=nullptr){
      if(cur->next->data == value){
        Node* to_delete = cur->next;
        cur->next = cur->next->next;
        delete to_delete;
        return; //found value
      }
      cur = cur->next;
    }
    return; //didnt find value
  }
}

void removeDuplicates(){
  if(head == nullptr){ //returns if empty
    return;
  }
  Node* cur = head;
  for(int i=0; i<size(); i++){
    if(cur->data == cur->next->data){
     deleteValue(cur->data, cur->next->data);
    }
    cur = cur->next;
  }
}

#include <stack>
#include <queue>

//assuming queue has front and rear pointers

void transfer(stack<int>& s, queue<int>& q) {
  //pop value from stack and add to queue
  if(s.empty()){ //return if stack empty
    return;
  }
  if(front.q == nullptr){ //if queue is empty assigns front
    front.q = s.pop(top_idx);
  } else {
    while(!s.empty()){ //adds to queue until stack empty
      popped=s.pop(top_idx)
      rear = popped; //keeps making end rear to while function over
      q.enqueue(popped);
    }
  }
}


void transfer(stack<int>& s, queue<int>& q) {
    while (!s.empty()) {
        // if empty just does nothing
        q.enqueue(s.pop());
    }
}

string reverseString(string input){
  stack<char> s = new stack();
  while(input.length>0){
    s.push(input[0]);
  }
  stringReversed = "";
  while(s.!empty()){
    stringReversed += s.pop();
  }
  return stringReversed;
}

struct Node {
    int data;
    Node* left;
    Node* right;
};

int findMin(Node* root) {
  if (root == nullptr) { //if tree empty
    return;
  }
  if(root->left==nullptr){ //when left have no more children
    return root->data;
  }
  findMin(root->left);
}

/*
Implement the following function which computes the number of leaf nodes in 
the given tree represented as a pointer to the root of a binary tree. Assume 
that BTNode class has method isLeaf().
*/
template <typename T>

int count_leaves(BTNode* node){
  int count = 0;
  if(node == nullptr){
    return;
  }
  if(isLeaf(node)!=true){
    int left_count= count_leaves(node->left);
    int right_count = count_leaves(node->right);
    } else {
      count++;
    } 
  return left_count+right_count;
}

int count_leaves(BTNode* node) {
  if (node == nullptr) {
    return 0;
  }
  if (node->isLeaf()) {
    return 1;
  }
  return count_leaves(node->left) + count_leaves(node->right);
}

