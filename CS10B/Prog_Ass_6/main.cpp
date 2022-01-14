#include "SortedSet.h"
#include "IntList.h"

#include <iostream>
using namespace std;

int main() {
    //Testing SortedSet::SortedSet()
    cout << "Testing SortedSet::SortedSet()..." << endl;
    SortedSet test1;
    cout << "Output should be blank: " << test1 << endl;

    //Testing SortedSet::SortedSet(const IntList &)
    cout << endl << "Testing SortedSet::SortedSet(const IntList &)..." << endl;
    IntList IntList1;
    IntList1.push_back(3);
    IntList1.push_back(3);
    IntList1.push_back(2);
    IntList1.push_back(1);
    cout << "IntList1 values: " << IntList1 << endl;
    cout << "SortedSet test2 should remove duplicates and correctly order the list." << endl;
    SortedSet test2(IntList1);
    cout << "test2 values: " << test2 << endl;

    //Testing SortedSet::SortedSet(const SortedSet &)
    cout << endl << "Testing SortedSet::SortedSet(const SortedSet &)..." << endl;
    SortedSet test3(test2);
    cout << "test2 values: " << test2 << endl;
    cout << "test3 values should match test2 values." << endl;
    cout << "test3 values: " << test3 << endl;

    //Testing bool SortedSet::in(int)
    cout << endl << "Testing bool SortedSet::in(int)..." << endl;
    cout << "test3 values: " << test3 << endl;
    cout << "test3.in(1) should return true (1)." << endl;
    cout << "test3.in(4) should return false (0)." << endl;
    cout << "test3.in(1): " << test3.in(1) << endl;
    cout << "test3.in(4): " << test3.in(4) << endl;

    //Testing void SortedSet::add(int)
    cout << endl << "Testing void SortedSet::add(int)..." << endl;
    cout << "test3 values: " << test3 << endl;
    cout << "test3.add(6) should add a 6 in the correct spot." << endl;
    test3.add(6);
    cout << "test3 values after calling test3.add(6): " << test3 << endl;
    cout << "Another call to test3.add(6) should not add the duplicate." << endl;
    test3.add(6);
    cout << "test3 values after calling test3.add(6) again: " << test3 << endl;
    cout << "test3.add(4) should add a 4 in the correct spot." << endl;
    test3.add(4);
    cout << "test3 values after calling test3.add(4): " << test3 << endl;

    cout << endl << "SortedSet's push_front, push_back, and insert_sorted simply call add, so no further testing of these functions is required" << endl;

    //Testing SortedSet SortedSet::operator|(const SortedSet &)
    cout << endl << "Testing SortedSet SortedSet::operator|(const SortedSet &)..." << endl;
    SortedSet test4;
    SortedSet test5;
    test4.add(1);
    test4.add(3);
    test4.add(2);
    test5.add(1);
    test5.add(4);
    test5.add(2);
    test5.add(5);
    cout << "test4 values: " << test4 << endl;
    cout << "test5 values: " << test5 << endl;
    cout << "(test4 | test5) should print out all values in test4, test5, or both, in order, no dupes)" << endl;
    cout << "(test4 | test5): " << (test4 | test5) << endl;

    //Testing SortedSet SortedSet::operator&(const SortedSet &)
    cout << endl << "Testing SortedSet SortedSet::operator&(const SortedSet &)..." << endl;
    cout << "test4 values: " << test4 << endl;
    cout << "test5 values: " << test5 << endl;
    cout << "(test4 & test5) should contain only values that are present in both test4 and test5, in order, no dupes)" << endl;
    cout << "(test4 & test5): " << (test4 & test5) << endl;
    cout << "If there are no values in common, or either SortedSet is empty, the SortedSet returned should be empty" << endl;
    SortedSet test6;
    SortedSet test7;
    cout << "test6 values: " << endl;
    cout << "test7 values: " << endl;
    cout << "(test6 & test7) with empty SortedSets, and no common values: " << (test6 & test7) << endl;

    //Testing SortedSet SortedSet::operator|=(const SortedSet &)
    cout << endl << "Testing SortedSet SortedSet::operator|=(const SortedSet &)" << endl;
    cout << "test4 values: " << test4 << endl;
    cout << "test5 values: " << test5 << endl;
    cout << "test5 |= test4 should change the values in test5 to all values in test4, test5, or both, in order, with no dupes)" << endl;
    test5 |= test4;
    cout << "test5 values: " << test5 << endl;

    //Testing SortedSet SortedSet::operator&=(const SortedSet &)
    cout << endl << "Testing SortedSet SortedSet::operator|=(const SortedSet &)" << endl;
    cout << "test4 values: " << test4 << endl;
    cout << "test5 values: " << test5 << endl;
    cout << "test5 &= test4 should change the values in test5 to only values found in both test4 and test5, in order, with no dupes)" << endl;
    test5 &= test4;
    cout << "test5 values: " << test5 << endl;
    
}