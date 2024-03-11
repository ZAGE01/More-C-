#pragma once
#include "Node.h"
#include "Utility.h"

class Queue {
    public:
        Queue();
        ~Queue();
        Queue(const Queue &original); // Copy constructor
        Error_code append(const Queue_entry &item);
        Error_code serve();
        Error_code retrieve(Queue_entry &item) const;
        bool empty() const;
        void operator = (const Queue &original); // Overloaded assignment operator

    protected:
        Node *front, *rear;
  };
