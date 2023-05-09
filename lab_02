#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* head;

    Stack() { 
        head = nullptr;
    }

    void Push(int x) { 
        Node* temp = new Node;
        temp->data = x;
        temp->next = head;
        head = temp;
    }

    void Pop() { 
        if (head == nullptr) {
            cout << "Stack underflow" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int StackTop() { 
        if (head == nullptr) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return head->data;
    }
    
    bool isEmpty() {
        return (head == nullptr);
    }
    
    void Display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    cout<<"Stack Using LinkedLists:\n";
    double time_spent=0.0;
    clock_t begin=clock();//clock starts
 
    Stack s;
    s.Push(8);
    s.Push(10);
    s.Push(5);
    s.Push(11);
    s.Push(15);
    s.Push(23);
    s.Push(6);
    s.Push(18);
    s.Push(20);
    s.Push(17);
    s.Display();
    s.Pop() ;
    s.Pop() ;
    s.Pop() ;
    s.Pop() ;
    s.Pop() ;
    s.Display();
    s.Push(4);
    s.Push(30);
    s.Push(3);
    s.Push(1);
    s.Display();
    
    clock_t end=clock();//clock ends
    
    time_spent+=(double)(end-begin)/CLOCKS_PER_SEC;
    cout<<"THE ELAPSED TIME IS "<<time_spent*1000<<" miliseconds" << endl;
    
    return 0;
}
