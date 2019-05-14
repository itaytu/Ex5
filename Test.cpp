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
        //--------------------rang-----------------------
        rangeC<int> intr(1, 5); // rang int
        rangeC<int> intr1(4, 8); //rang int
        rangeC<double> dour(5.1, 9.1); //rang double
        rangeC<char> charr('a', 'e'); // rang char
        rangeC<char> charr1('x', 'z');

        //----------------chain-----------------------
        chainC<rangeC<int>, rangeC<int>> intC(intr, intr1); //chain int int
        chainC<rangeC<char>, string> charC(charr, s);
        chainC<rangeC<char>, rangeC<char>> charC1(charr, charr1);// chain char string

        //-------------zip--------------------------------
        zipC<rangeC<int>, string> zipIS(intr, s);
        zipC<rangeC<double>, string> zipDS(dour, s);
        zipC<rangeC<int>, rangeC<int>> zipII(intr, intr1);
        zipC<zipC<rangeC<int>, string>, zipC<rangeC<double>, string>> zipzip(zipIS, zipDS);

        //------------------product-------------------------
        productC<rangeC<int>, string> proIntS(intr, s);
        productC<rangeC<double>, string> proDoubleS(dour, s);
        productC<string, string> proSTRS(s, s);
        productC<chainC<rangeC<int>, rangeC<int>>, chainC<rangeC<char>, rangeC<char>>> proTwoChains(intC, charC1);

        cout << iterable_to_string(proTwoChains) << endl;

        //------------------powerset------------------
        /*      powersetC<rangeC<int>> powR(intr);
              powersetC<chainC<rangeC<char>,rangeC<char>>> powChainOfRangChar(charC1);*/

        /*     testcase.setname("range")
             .CHECK_EQUAL(iterable_to_string(intr).compare("1,2,3,4,"), true)
             .CHECK_EQUAL(iterable_to_string(intr1).compare("4,5,6,7,"), true)
             .CHECK_EQUAL(iterable_to_string(dour).compare("5.1,6.1,7.1,8.1,"), true)
             .CHECK_EQUAL(iterable_to_string(charr).compare("a,b,c,d,"), true)
             .CHECK_EQUAL(iterable_to_string(charr).compare("x,y,z,"), true)

             ;
             testcase.setname("chain")
             .CHECK_EQUAL(iterable_to_string(intC).compare("1,2,3,4,4,5,6,7,"), true)


             ;

             grade = testcase.grade();
         } else {
             testcase.print_signal(signal);
             grade = 0;
         }*/
        cout << "Your grade is: " << grade << endl;
        return 0;
    }
}
