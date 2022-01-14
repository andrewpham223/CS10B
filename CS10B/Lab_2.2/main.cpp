#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int charCnt(const string &, const char &);


int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

int charCnt(const string &filename, const char &ch) {
    ifstream inpFile;
    char comp;
    int count = 0;
    
    inpFile.open(filename);

    if(!inpFile.is_open()) {
        cout << "Error opening " << filename << endl;
        exit(1);
    }
    
    while(inpFile >> comp) {
        if(comp == ch) {
            count++;
        }
    }
    if(!inpFile.eof()) {
        cout << "Input failure before reaching end of file." << endl;
    }
    
    inpFile.close();
    
    return count;
}
