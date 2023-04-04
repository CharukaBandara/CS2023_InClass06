#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// Arrays
int stack_array[100], n=100, top=-1;
void push_a(int x) {
    top++;
    if(top>n){
        cout<<"Stack Overflow"<<endl;
    }
    else {
        stack_array[top]=x;
   }
}
void pop_a() {
   if(top<0){
       cout<<"Stack Underflow"<<endl;
   }
   else {
       top--;
       cout<< stack_array[top+1] <<endl;
      
   }
}
void display() {
   if(top>=0) {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
      cout<<stack_array[i]<<" ";
      cout<<endl;
   } else
   cout<<"Stack is empty";
}
//Linked Lists
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class Stack_LL {
public:
    Node* head;
    Node* top;
    Stack_LL() {
        head = nullptr;
        top = nullptr;
    }
    void push_l(int data) {
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
    int pop_l() {
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




int main(){
  srand(time(nullptr));
  auto start_timei = high_resolution_clock::now();
  push_a(8);
  push_a(10);
  push_a(5);
  push_a(11);
  push_a(15);
  push_a(23);
  push_a(6);
  push_a(18);
  push_a(20);
  push_a(17);
  display();
  for (int i=0;i<5;i++){
    pop_a();
  }
  display();
  push_a(4);
  push_a(30);
  push_a(3);
  push_a(1);
  display();
  auto end_timei = high_resolution_clock::now();
  auto durationi = duration_cast<nanoseconds>(end_timei - start_timei);
  cout << "Time taken to implementaion using array " << durationi.count() << " nanoseconds" << endl;


}