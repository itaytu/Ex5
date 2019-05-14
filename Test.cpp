#include <iostream>

#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"
#include "iostream"

using namespace std;
using namespace itertools;

template<typename Iterable>
string iterable_to_string( Iterable& iterable) {
    ostringstream ostr;
    for (decltype(*iterable.begin()) i: iterable)
        ostr << i << ",";
    return ostr.str();
}
int main() {
    badkan::TestCase testcase;
    int grade = 0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0) {

        string s = "hello";
        string s1 = "Moshe";
        //--------------------rang-----------------------
        rangeC<int> intr(1, 5); // rang int
        rangeC<int> intr1(4, 8); //rang int
        rangeC<int> intr2(10, 15); //rang int
        rangeC<double> dour(5.1, 9.1); //rang double
        rangeC<double> dour2(5.1, 10.1);
        rangeC<char> charr('a', 'e'); // rang char
        rangeC<char> charr1('x', 'z');

        //----------------chain-----------------------
        chainC<rangeC<int>, rangeC<int>> intC(intr, intr1); //chain int int
        chainC<rangeC<char>, string> charC(charr, s);
        chainC<rangeC<char>, rangeC<char>> charC1(charr, charr1);// chain char string

        //-------------zip--------------------------------
        zipC<rangeC<int>, string> zipIS(intr2, s);
        zipC<rangeC<double>, string> zipDS(dour2, s1);
        zipC<rangeC<int>, rangeC<int>> zipII(intr, intr1);
        zipC<zipC<rangeC<int>, string>, zipC<rangeC<double>, string>> zipzip(zipIS, zipDS);

        //------------------product-------------------------
        productC<rangeC<int>, string> proIntS(intr, s);
        productC<rangeC<double>, string> proDoubleS(dour, s);
        productC<string, string> proSTRS(s, s);
        productC<chainC<rangeC<int>, rangeC<int>>, chainC<rangeC<char>, rangeC<char>>> proTwoChains(intC, charC1);


        //------------------powerset------------------
        /*      powersetC<rangeC<int>> powR(intr);
              powersetC<chainC<rangeC<char>,rangeC<char>>> powChainOfRangChar(charC1);*/

        testcase.setname("range")
                .CHECK_EQUAL(iterable_to_string(intr).compare("1,2,3,4, "), true)
                .CHECK_EQUAL(iterable_to_string(intr1).compare("4,5,6,7, "), true)
                .CHECK_EQUAL(iterable_to_string(dour).compare("5.1,6.1,7.1,8.1, "), true)
                .CHECK_EQUAL(iterable_to_string(charr).compare("a,b,c,d, "), true)
                .CHECK_EQUAL(iterable_to_string(charr).compare("x,y,z, "), true)
                ;

        testcase.setname("chain")
                .CHECK_EQUAL(iterable_to_string(intC).compare("1,2,3,4,4,5,6,7, "), true)
                .CHECK_EQUAL(iterable_to_string(charC).compare("a,b,c,d,h,e,l,l,o, "),true)
                .CHECK_EQUAL(iterable_to_string(charC1).compare("a,b,c,d,x,y, "),true)
                ;

        testcase.setname("zip")
                .CHECK_EQUAL(iterable_to_string(zipIS).compare("10,h,11,e,12,l,13,l,14,o, "), true)
                .CHECK_EQUAL(iterable_to_string(zipDS).compare("5.1,M,6.1,o,7.1,s,8.1,h,9.1,e, "), true)
                .CHECK_EQUAL(iterable_to_string(zipII).compare("1,4,2,5,3,6,4,7, "), true)
                .CHECK_EQUAL(iterable_to_string(zipzip).compare("10,h,5.1,M,11,e,6.1,o,12,l,7.1,s,13,l,8.1,h,14,o,9.1,e, "), true)
                ;

        testcase.setname("product")
                .CHECK_EQUAL(iterable_to_string(proIntS).compare("1,h,1,e,1,l,1,l,1,o,2,h,2,e,2,l,2,l,2,o,3,h,3,e,3,l,3,l,3,o,4,h,4,e,4,l,4,l,4,o, "), true)
                .CHECK_EQUAL(iterable_to_string(proDoubleS).compare("5.1,h,5.1,e,5.1,l,5.1,l,5.1,o,6.1,h,6.1,e,6.1,l,6.1,l,6.1,o,7.1,h,7.1,e,7.1,l,7.1,l,7.1,o,8.1,h,8.1,e,8.1,l,8.1,l,8.1,o, "), true)
                .CHECK_EQUAL(iterable_to_string(proSTRS).compare("h,h,h,e,h,l,h,l,h,o,e,h,e,e,e,l,e,l,e,o,l,h,l,e,l,l,l,l,l,o,l,h,l,e,l,l,l,l,l,o,o,h,o,e,o,l,o,l,o,o, "), true)
                .CHECK_EQUAL(iterable_to_string(proTwoChains).compare("1,a,1,b,1,c,1,d,1,x,1,y,2,a,2,b,2,c,2,d,2,x,2,y,3,a,3,b,3,c,3,d,3,x,3,y,4,a,4,b,4,c,4,d,4,x,4,y,4,a,4,b,4,c,4,d,4,x,4,y,\n"
                                                                      "5,a,5,b,5,c,5,d,5,x,5,y,6,a,6,b,6,c,6,d,6,x,6,y,7,a,7,b,7,c,7,d,7,x,7,y, "), true)
                ;

        grade = testcase.grade();
    } else {
        testcase.print_signal(signal);
        grade = 0;
    }
    cout << "Your grade is: " << grade << endl;
    return 0;
}

