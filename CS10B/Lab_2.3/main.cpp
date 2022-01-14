#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   
   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];
   // Create input stream and open input csv file.
   ifstream inFS;
   inFS.open(inputFile);
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if(!inFS.is_open()) {
       cout << "Error opening " << inputFile << endl;
       return 1;
   }
   // Read in integers from input file to vector.
   vector<int> intVector;
   int val;
   //string str;
   while(inFS >> val) {
       inFS.ignore(1,',');
       //str = inFS.get();
       //if(str != ",") {
           //val = atoi(str.c_str());
           //intVector.push_back(val);
       //}
       intVector.push_back(val);
   }
   // Close input stream.
   inFS.close();
   // Get integer average of all values read in.
   int count = 0;
   for(unsigned i = 0; i < intVector.size(); ++i) {
       count += intVector.at(i);
   }
   int avg = count / intVector.size();
   // Convert each value within vector to be the difference between the original value and the average.
   int temp;
   for(unsigned i = 0; i < intVector.size(); ++i) {
       temp = intVector.at(i);
       intVector.at(i) = temp-avg;
   }
   // Create output stream and open/create output csv file.
   ofstream outFS;
   outFS.open(outputFile);
   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if(!outFS.is_open()) {
       cout << "Error opening " << outputFile << endl;
       return 1;
   }
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for(unsigned i = 0; i < intVector.size(); i++) {
       if(i == intVector.size()-1) {
           outFS << intVector.at(i);
       }
       else {
           outFS << intVector.at(i) << ",";
       }
   }
   // Close output stream.
   outFS.close();
   return 0;
}
