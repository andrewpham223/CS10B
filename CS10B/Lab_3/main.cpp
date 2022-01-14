#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational(int numerator = 0, int denominator = 1);
      int getNumerator() const;
      int getDenominator() const;
      void setNumerator(int);
      void setDenominator(int);
      Rational add(const Rational &) const; 
      Rational subtract(const Rational &) const; 
      Rational multiply(const Rational &) const; 
      Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};

// Implement Rational class member functions here

Rational::Rational(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}

int Rational::getNumerator() const {
    return this->numerator;
}

int Rational::getDenominator() const {
    return this->denominator;
}

void Rational::setNumerator(int numerator) {
    this->numerator = numerator;
}

void Rational::setDenominator(int denominator) {
    this->denominator = denominator;
}

Rational Rational::add(const Rational &r) const {
    Rational sum;
    sum.setNumerator(this->numerator * r.getDenominator() + this->denominator * r.getNumerator());
    sum.setDenominator(this->denominator * r.getDenominator());
    return sum;
}

Rational Rational::subtract(const Rational &r) const {
    Rational diff;
    diff.setNumerator(this->numerator * r.getDenominator() - this->denominator * r.getNumerator());
    diff.setDenominator(this->denominator * r.getDenominator());
    return diff;
}

Rational Rational::multiply(const Rational &r) const {
    Rational product;
    product.setNumerator(this->numerator * r.getNumerator());
    product.setDenominator(this->denominator * r.getDenominator());
    return product;
}

Rational Rational::divide(const Rational &r) const {
    Rational quotient;
    quotient.setNumerator(this->numerator * r.getDenominator());
    quotient.setDenominator(this->denominator * r.getNumerator());
    return quotient;
}

void Rational::simplify() {
    int gcDenominator = gcd(this->numerator, this->denominator);
    this->numerator = this->numerator / gcDenominator;
    this->denominator = this->denominator / gcDenominator;
}

void Rational::display() const {
    cout << this->numerator << " / " << this->denominator;
}

int Rational::gcd(int numerator, int denominator) const {
    int a, b, temp;
    if(numerator > denominator) {
       a = numerator;
       b = denominator;
    }
    else {
       a = denominator;
       b = numerator;
    }
    while(a != 0 && b != 0) {
       temp = a % b;
       a = b;
       b = temp;
    }
    return a;
}

// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

