#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class Stack {
public:
    Node* head;
    Node* top;
    Stack() {
        head = nullptr;
        top = nullptr;
    }
    void push(int data) {
        Node* new_node = new Node(data);
        if(head == nullptr) {
          head = new_node;
          top = new_node;
        }
        else {
            top->next = new_node;
            top = new_node;
        }
    }
    int pop() {
        if(head == nullptr) {
          cout << "Stack Underflow" << endl;
          return -1;
        }
        int popped_value = top->data;
        if(top == head) {
            delete top;
            top = nullptr;
            head = nullptr;
        }
        else {
            Node* tmp = head;
            while(tmp->next != top) {
                tmp = tmp->next;
            }
            tmp->next = nullptr;
            delete top;
            top = tmp;
        }
        return popped_value;
    }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl; 
    return 0;
}
