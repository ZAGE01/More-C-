#pragma once
#include "linkedQueue.h"

class Extended_queue : public Queue {
    public:
        bool full();
        void clear();
        Error_code serve_and_retrieve(Queue_entry &item);
};