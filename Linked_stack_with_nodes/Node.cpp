#include "Node.h"

Node::Node(int value, Node* nextNode) {
    data = value;
    next = nextNode;
}