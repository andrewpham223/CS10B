#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

int fileSum(const string &);

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

// Place fileSum implementation here
int fileSum(const string &fileName) {
    ifstream inpFile; // Input file stream
    int sum = 0;      // Sum variable to return
    int addToSum;     // Data value from file
    
    // Open file
    inpFile.open(fileName);
    
    // Print error message if unable to open file
    if(!inpFile.is_open()) {
        cout << "Error opening " << fileName << endl;
        exit(1);
    }
    
    // Reading values from the file and adding to sum variable
    while(inpFile >> addToSum) {
        sum += addToSum;
    }
    
    inpFile.close();
    
    return sum;
}
