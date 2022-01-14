#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   vector<string> monthVector() const;

   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;

};


// Implement the Date member functions here
vector<string> Date::monthVector() const{
   vector<string> months;
   months.push_back("January");
   months.push_back("February");
   months.push_back("March");
   months.push_back("April");
   months.push_back("May");
   months.push_back("June");
   months.push_back("July");
   months.push_back("August");
   months.push_back("September");
   months.push_back("October");
   months.push_back("November");
   months.push_back("December");
   months.push_back("january");
   months.push_back("february");
   months.push_back("march");
   months.push_back("april");
   months.push_back("may");
   months.push_back("june");
   months.push_back("july");
   months.push_back("august");
   months.push_back("september");
   months.push_back("october");
   months.push_back("november");
   months.push_back("december");
   return months;
}

Date::Date() {
   this->month = 1;
   this->day = 1;
   this->year = 2000;
   this->monthName = "January";
}

Date::Date(unsigned m, unsigned d, unsigned y) {
   this->month = m;
   this->day = d;
   this->year = y;
   bool b = false;
   if(this->month < 1) {
      this->month = 1;
      this->monthName = "January";
      b = true;
   }
   if(this->month > 12) {
      this->month = 12;
      this->monthName = "December";
      b = true;
   }
   if(this->day > daysPerMonth(this->month, this->year)) {
      this->day = daysPerMonth(this->month, this->year);
      b = true;
   }
   if(this->day < 1) {
      this->day = 1;
      b = true;
   }
   this->monthName = name(this->month);
   if(b == true) {
      cout << "Invalid date values: Date corrected to " << this->month << "/" << this->day << "/" << this->year << "." << endl;
   }
}

Date::Date(const string &mn, unsigned d, unsigned y) {
   vector<string> months = monthVector();
   
   this->monthName = mn;
   this->day = d;
   this->year = y;
   this->month = -1;
   bool b = false;

   for(unsigned i = 0; i < months.size(); ++i) {
      if(this->monthName == months.at(i)) {
         b = true;
         if(i > 11) {
            this->month = i-11;
            this->monthName = name(this->month);
         }
         if(i <= 11) {
            this->month = i+1;
            this->monthName = months.at(i);
         }
      }
   }

   if(b == false) {
      this->monthName = "January";
      this->month = 1;
      this->day = 1;
      this->year = 2000;
      cout << "Invalid month name: the Date was set to " << this->month << "/" << this->day << "/" << this->year << "." << endl;
   }
   bool c = false;
   if(this->month > 12) {
      this->month = 12;
      this->monthName = "December";
      c = true;
   }
   if(this->month < 1) {
      this->month = 1;
      this->monthName = "January";
      c = true;
   }
   if(this->day > daysPerMonth(this->month, this->year)) {
      this->day = daysPerMonth(this->month, this->year);
      c = true;
   }
   if(this->day < 1) {
      this->day = 1;
      c = true;
   }
   if(c == true) {
      cout << "Invalid date values: Date corrected to " << this->month << "/" << this->day << "/" << this->year << "." << endl;
   }
}

void Date::printNumeric() const {
   cout << this->month << "/" << this->day << "/" << this->year;
}

void Date::printAlpha() const {
   cout << this->monthName << " " << this->day << ", " << this->year; 
}

bool Date::isLeap(unsigned y) const{
   return((year % 4 == 0 && year % 100 != 0)) || year % 400 == 0;
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
   int i = -1;
   if(m==1 || m==3 || m==5 || m==7 || m==8 || m == 10 || m == 12) {
      i = 31;
   }
   if(m==4 || m==6 || m==9 || m==11) {
      i = 30;
   }
   if(m==2) {
      if(isLeap(y)) {
         i = 29;
      }
      else {
         i = 28;
      }
   }
   return i;
}

string Date::name(unsigned m) const {
   vector<string> months = monthVector();
   return months.at(m-1);
}

unsigned Date::number(const string &mn) const {
   vector<string> months = monthVector();
   int m = -1;
   for(unsigned i = 0; i < months.size(); ++i) {
      if(mn == months.at(i)) {
         m = i;
      }
   }
   return m+1;
} 

// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
