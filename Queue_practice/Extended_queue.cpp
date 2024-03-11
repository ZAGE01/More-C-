#include "Extended_queue.h"
#include "Utility.h"
#include "Queue.h"

Extended_queue::Extended_queue() {
count = 0;
rear = maxqueue-1;
front = 0;
}

bool Extended_queue::full() const {
    return count >= maxqueue;
}

int Extended_queue::size() const {
    return count;
}

void Extended_queue::clear() {
    count = 0;
    front = 0;
    rear = maxqueue - 1;
}

Error_code Extended_queue::serve_and_retrieve(Queue_entry &item) {
    if (count <= 0) return underflow;
    item = entry[front];
    serve();
    return success;
}