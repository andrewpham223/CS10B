#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool rCopy(const string &inFile, const string &outFile);
void reverseCopy(ifstream &inFS, ofstream &outFS, string &s\);

int main(int argc, char *argv[]) {
    rCopy(argv[1], argv[2]);
    return 0;
}

bool rCopy(const string &inFile, const string &outFile) {
    ifstream inFS;
    inFS.open(inFile);
    if(!inFS.is_open()) {
        cout << "Error opening " << inFile << endl;
        cout << "Copy not completed" << endl;
        return false;
    }
    ofstream outFS;
    outFS.open(outFile);
    if(!outFS.is_open()) {
        cout << "Error opening " << outFile << endl;
        cout << "Copy not completed" << endl;
        return false;
    }
    reverseCopy(inFS, outFS);
    inFS.close();
    outFS.close();
    return true;
}

void reverseCopy(ifstream &inFS, ofstream &outFS) {
    char ch;
    if(inFS.get(ch)) {
        reverseCopy(inFS, outFS);
        outFS << ch;
    }
    
}

