#include "linkedStack.h"
#include "Utility.h"

// Konstruktori
linkedStack::linkedStack() {
    top_node = nullptr;
}

// Lisätään uusi alkio stackkiin
Error_code linkedStack::push(const int &item) {
   Node* node = new Node(item);
   if (node == nullptr) {
        return overflow;
   }
   node->next = top_node;
   top_node = node;

   return success;
}

// Poistetaan alkio stackin päältä
Error_code linkedStack::pop() {
   if (empty()) {
        return underflow;
   }
   int popped_item = top_node->data;
   Node* temp = top_node;
   top_node = top_node->next;
   delete temp;

   return success;
}

// Palauttaa stackin alkioiden määrän
int linkedStack::size() const {
    int count = 0;
    Node* current = top_node;

    while(current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

// Tarkistaa onko stack tyhjä
bool linkedStack::empty() const {
   return top_node == nullptr;
}
