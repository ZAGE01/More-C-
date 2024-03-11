#include "linkedQueue.h"
#include "Utility.h"

// Konstruktori
Queue::Queue() {
    front = rear = nullptr;
}

// Destruktori
Queue::~Queue() {
    while (!empty()) {
        serve();
    }
}

// Kopiokonstruktori
Queue::Queue(const Queue &original) {
    front = rear = nullptr;
    Node *temp = original.front;
    while (temp != nullptr) {
        append(temp->data);
        temp = temp->next;
    }
}

// Lisää alkion jonon perälle
Error_code Queue::append(const Queue_entry &item) {
    Node *new_node = new Node(item);
    if (new_node == nullptr) {
        return overflow;
    }
    if (empty()) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
    return success;
}

// Tarkistaa onko jono tyhjä vai ei
bool Queue::empty() const {
    return front == nullptr;
}

// Ylikuormitettu sijoitusoperaattori
void Queue::operator=(const Queue &original) {
    if (this != &original) {
        while (!empty()) {
            serve(); // Tyhjennetään nykyinen jono
        }
        Node *temp = original.front;
        while (temp != nullptr) {
            append(temp->data);
            temp = temp->next;
        }
    }
}

// Palauttaa jonon ensimmäisen alkion
Error_code Queue::retrieve(Queue_entry &item) const {
    if (empty()) {
        return underflow;
    }
    item = front->data;
    return success;
}

// Poistetaan alkio jonon alusta
Error_code Queue::serve() {
    if (empty()) {
        return underflow;
    }
    Node *temp = front;
    front = front->next;
    delete temp;
    if (front == nullptr) { // Jos poistettiin viimeinen alkio, päivitetään myös rear
        rear = nullptr;
    }
    return success;
}
