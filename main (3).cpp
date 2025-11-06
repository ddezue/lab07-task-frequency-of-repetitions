/*************************
 * Автор: Бакланова Ляна *  
 *************************/

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
  ifstream file("text.txt");

  map<char, int> letterCount;
  map<string, int> combCount;
  
  char prev = '\0', current;
  
  while (file >> current) {
    letterCount[current]++;
    
    if (prev != '\0') {
      string comb = string(1, prev) + current;
      combCount[comb]++;
    }
    prev = current;
  }

  cout << "Letter frequency:\n";
  for (auto entry : letterCount) {
    if (entry.second > 1) {
      cout << "'" << entry.first << "': " << entry.second <<" repeats" << endl;
    }
  }

  cout << "\nTwo-letter combinations:\n";
  for (auto entry : combCount) {
    if (entry.second > 1) {
      cout << "\"" << entry.first << "\": " << entry.second << " repeats" << endl;
    }
  }

  return 0;

}
