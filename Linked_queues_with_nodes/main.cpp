#include <iostream>
#include "Node.h"
#include "linkedQueue.h"
#include "Utility.h"

using namespace std;

int main() {
    Queue q;

    // Lisätään alkioita
    for (int i=1; i <= 5; i++) {
        q.append(i*10);
    }

    // Tulostetaan jono
    while (!q.empty()) {
        Queue_entry item;
        q.retrieve(item);
        cout << item << " ";
        q.serve();
    }

    return 0;
}