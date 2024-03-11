#include <iostream>
#include <string>
#include "Utility.h"
#include "Queue.h"
#include "Extended_queue.h"

using namespace std;

char testInput(const string &input) {
   Extended_queue leftPartQueue;
   bool colonFound = false;
   string leftPart = input.substr(0, input.find(':'));
   string rightPart = input.substr(input.find(':') + 1);

   // Tarkistetaan löytyykö ':' merkkiä inputista
   for (char c : input) {
      if (c == ':') {
         colonFound = true;
         break;
      }
      leftPartQueue.append(c);
   }

   if (!colonFound) {
      return 'N';
   }

   size_t rightPartLength = input.length() - leftPartQueue.size() - 1;

   // Jos vasen puoli on pidempi
   if (leftPartQueue.size() > rightPartLength) {
      return 'L';
   // Jos oikea puoli on pidempi
   } else if (leftPartQueue.size() < rightPartLength) {
      return 'R';
   } else {
      // Jos molemmat puolet ovat täysin samat
      if (leftPart == rightPart) {
         return 'S';
      // Jos molemmat puolet ovat eri mutta yhtä pitkät
      } else {
         return 'D';
      }
   }
}

int main() {
   string input;

   cout << "N \t No colon on the line." << endl
         << "L \t The left part (before the colon) is longer than the right." << endl
         << "R \t The right part (before the colon) is longer than the left." << endl
         << "D \t The left and right parts have the same length but are different." << endl
         << "S \t The left and right parts are exactly the same." << endl << endl;

   cout << "Enter one line of input (two parts separated by a colon symbol): ";
   getline(cin, input);

   char result = testInput(input);
   cout << "Output: " << result << endl;

   return 0;
}