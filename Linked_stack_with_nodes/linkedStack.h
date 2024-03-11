#pragma once
#include "Node.h"
#include "Utility.h"

class linkedStack {
    public:
        linkedStack();
        Error_code pop();
        Error_code push(const int &item);
        int size() const; // Tarkistetaan alkioiden määrä
        bool empty() const; // Tarkistetaan onko tyhjä

    private:
        Node* top_node;
  };
