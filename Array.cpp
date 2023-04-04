#include <iostream>
using namespace std;
int stack[100], n=100, top=-1;
void push(int x) {
    top++;
    if(top>n){
        cout<<"Stack Overflow"<<endl;
    }
    else {
        stack[top]=x;
   }
}
void pop() {
   if(top<0){
       cout<<"Stack Underflow"<<endl;
   }
   else {
       top--;
       cout<< stack[top+1] <<endl;
      
   }
}
int main(){
  push(200);
  push(20);
  pop();
}