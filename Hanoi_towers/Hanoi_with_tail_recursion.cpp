#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int moves = 0;

void move(int count, int start, int finish, int temp) {
   if (count > 0) {
      move(count - 1, start, temp, finish);
      moves++;

      move(count - 1, temp, finish, start);
   }
}

int main()
{
    int disks;

    for(disks = 10; disks <= 15; disks++) {
        moves = 0;

        auto start = high_resolution_clock::now();
        move(disks, 1, 3, 2);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << disks << " disks: " << endl;
        cout << "Number of transfer orders: " << moves << endl;
        cout << "Execution time: " << duration.count() << " microseconds " << endl;
        cout << endl;
    }

    return 0;
}