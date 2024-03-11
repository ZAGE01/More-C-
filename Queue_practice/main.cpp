#include <iostream>
#include <limits>
#include "Utility.h"
#include "Queue.h"
#include "Extended_queue.h"

using namespace std;

void help() {
   cout << endl
        << "This program allows the user to enter one command" << endl
        << "(but only one) on each input line." << endl
        << "For example, if the command S is entered, then" << endl
        << "the program will serve the front of the queue." << endl
        << endl

        << " The valid commands are:" << endl
        << "A - Append the next input character to the extended queue" << endl
        << "S - Serve the front of the extended queue" << endl
        << "R - Retrieve and print the front entry." << endl
        << "# - The current size of the extended queue" << endl
        << "C - Clear the extended queue (same as delete)" << endl
        << "P - Print the extended queue" << endl
        << "H - This help screen" << endl
        << "Q - Quit" << endl

        << "Press <Enter> to continue." << flush;

   char c;
   do {
      cin.get(c);
   } while (c != '\n');
}


bool do_command(char c, Extended_queue &test_queue) {
   bool continue_input = true;
   Queue_entry x;

   switch (c) {
   case 'r':
      if (test_queue.retrieve(x) == underflow)
         cout << "Queue is empty." << endl;
      else
         cout << endl
              << "The first entry is: " << x
              << endl;
      break;

    case 'a':
      char new_entry;
      cout << "Enter a character to append to the extended queue: ";
      cin >> new_entry;
      if (test_queue.append(new_entry) == overflow)
         cout << "Queue is full. Cannot append." << endl;
      break;

   case 's':
      if (test_queue.serve() == underflow)
         cout << "Queue is empty. Cannot serve." << endl;
      else
         cout << "Front of the extended queue served." << endl;
      break;

   case 'p':
      if (test_queue.empty()) {
        cout << "Extended queue is empty." << endl;
        }
    else {
        cout << "Extended queue: ";
        Extended_queue temp_queue = test_queue;  // Create a temporary queue for printing
        while (!temp_queue.empty()) {
            Queue_entry element;
            temp_queue.retrieve(element);
            cout << static_cast<char>(element) << " ";
            temp_queue.serve();  // Move to the next element
        }
        cout << endl;
    }
      break;

   case '#':
      cout << "Current size of the extended queue: " << test_queue.size() << endl;
      break;

   case 'c':
      test_queue.clear();
      cout << "Extended queue cleared." << endl;
      break;

   case 'h':
      help();
      break;

   case 'q':
      cout << "Extended queue demonstration finished." << endl;
      continue_input = false;
      break;

   default:
      cout << "Invalid command. Please try again." << endl;
      break;
   }

   return continue_input;
}

void introduction() {
   cout << "Welcome to the Extended Queue demonstration program." << endl;
   cout << "You can perform various operations on the Extended Queue." << endl;
   cout << "Follow the instructions below to enter commands:" << endl;
   cout << "A - Append the next input character to the extended queue" << endl;
   cout << "S - Serve the front of the extended queue" << endl;
   cout << "R - Retrieve and print the front entry." << endl;
   cout << "# - The current size of the extended queue" << endl;
   cout << "C - Clear the extended queue (same as delete)" << endl;
   cout << "P - Print the extended queue" << endl;
   cout << "H - Display this help screen" << endl;
   cout << "Q - Quit" << endl;
   cout << "Press <Enter> to continue." << flush;

   char c;
   do {
      cin.get(c);
   } while (c != '\n');
}

char get_command() {
   char command;
   cout << "\nEnter a command: ";
   cin >> command;
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
   return tolower(command); // Convert to lowercase for case-insensitive comparison
}

int main() {
   Extended_queue test_queue;
   introduction();
   while (do_command(get_command(), test_queue));
}