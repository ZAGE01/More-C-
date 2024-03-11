#include <iostream>
#include "Utility.h"
#include "Node.h"
#include "linkedStack.h"

using namespace std;

int main() {
    Node* p0 = new Node(10);
    Node* p1 = p0->next = new Node(20);
    Node* p2 = p1->next = new Node(30);

    Node* current = p0;
    while(current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    delete p0;
    delete p1;
    delete p2;

    linkedStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Stack size: " << stack.size() << endl;

    while(!stack.empty()) {
        stack.pop();
    }

    return 0;
}