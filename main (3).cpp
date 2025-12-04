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
    ++letterCount[current];
    
    if (prev != '\0') {
      string comb = string(1, prev) + current;
      ++combCount[comb];
    }
    prev = current;
  }

  cout << "Letter frequency:\n";
  for (auto letterIter = letterCount.begin(); letterIter != letterCount.end(); ++letterIter) {
    if (letterIter->second > 1) {
      cout << "'" << letterIter->first << "': " << letterIter->second - 1 << " repeats" << endl;
    }
  }

  cout << "\nTwo-letter combinations:\n";
  for (auto combIter = combCount.begin(); combIter != combCount.end(); ++combIter) {
    if (combIter->second > 1) {
      cout << "\"" << combIter->first << "\": " << combIter->second - 1 << " repeats" << endl;
    }
  }

  return 0;
}
