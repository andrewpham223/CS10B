#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here
void flipString(string &s) {
   string middleStr = " ";
    if (s.size() <= 1) {
        s = s;
    }
    else {
        middleStr = s.substr(1, s.length()-2);
        flipString(middleStr);
        s = s.at(s.length()-1) + middleStr + s.at(0);
    }
}


