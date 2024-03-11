#include "extendedQueue.h"

bool Extended_queue::full() {
    // Jono ei ole koskaan täynnä
    return false;
}

void Extended_queue::clear() {
    while (!empty()) {
        serve();
    }
}

Error_code Extended_queue::serve_and_retrieve(Queue_entry &item) {
    if (empty()) {
        return underflow;
    }
    retrieve(item);
    return serve();
}