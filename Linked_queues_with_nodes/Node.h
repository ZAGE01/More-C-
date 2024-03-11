#pragma once

typedef double Queue_entry;

class Node {
    public:
        Queue_entry data;
        Node* next;

        Node(Queue_entry val);
};