#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

const int MAX_SIZE = 200;

int arr[MAX_SIZE];
int top = -1;

void Push(int x) {
    if (top == MAX_SIZE - 1) {
        cout << "Stack Overflow";
        return;
    }
    arr[++top] = x;
}

void Pop() {
    if (top == -1) {
        cout << "Stack Underflow";
        return;
    }
    top--;
}

int StackTop() {
    if (top == -1) {
        cout << "Stack is empty";
        return -1;
    }
    return arr[top];
}

bool isEmpty() {
    return (top == -1);
}

bool isFull(){
    return (top==MAX_SIZE - 1);
}

void Display(){
    for (int i=0;i<=top;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main() {
    cout<<"Stack Using Arrays:\n";
    double time_spent=0.0;
    clock_t begin=clock();//clock starts
    
    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    Display();
    Pop() ;
    Pop() ;
    Pop() ;
    Pop() ;
    Pop() ;
    cout<<endl;
    Display();
    Push(4);
    Push(30);
    Push(3);
    Push(1);
    cout<<endl;
    Display();
    
    clock_t end=clock();//clock ends
    
    time_spent+=(double)(end-begin)/CLOCKS_PER_SEC;
    cout<<"\nTHE ELAPSED TIME IS "<<time_spent*1000<<" miliseconds" << endl;
    return 0;
}
