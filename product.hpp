//
// Created by Itayt on 5/5/2019.
//

#ifndef EX5_PRODUCT_HPP
#define EX5_PRODUCT_HPP

#include <utility>
#include "zip.hpp"

namespace itertools {
    template <typename T1, typename T2>
    class productC {
        T1 a;
        T2 b;
    public:
        productC(T1& a, T2& b) : a(a), b(b){}
        productC(){}

        class iterator{
        public:
            decltype(b.begin()) bConst;
            decltype(a.begin()) aBegin;
            decltype(a.end()) aEnd;
            decltype(b.begin()) bBegin;
            decltype(b.end()) bEnd;

            iterator(T1& a, T2& b) :
                    aBegin(a.begin()),
                    aEnd(a.end()),
                    bBegin(b.begin()),
                    bEnd(b.end()),
                    bConst(b.begin())
            {}

            iterator(T1& a, T2& b, bool flag) :
                    aBegin(a.end()),
                    aEnd(a.end()),
                    bBegin(b.end()),
                    bEnd(b.end())
            {}

            auto operator*() const {
                return make_pair(*aBegin, *bBegin);
            }
            iterator& operator++() {
                if(aBegin != aEnd) {
                    if(bBegin != bEnd) {
                        ++bBegin;
                    }
                    else {
                        ++aBegin;
                        bBegin = bConst;
                    }
                }
                return *this;
            }

            bool operator==(const iterator &it) const {
                return (aBegin == it.aBegin || bBegin == it.bBegin);
            }

            bool operator!=(const iterator& it) const {
                return (aBegin != it.aBegin || bBegin != it.bBegin);
            }


        };

        iterator begin() {
            return iterator(a, b);
        }

        iterator end() {
            return iterator(a, b, false);
        }
    };

    template<typename T1, typename T2> productC<T1, T2> product(T1 a, T2 b) {
        return productC<T1, T2>(a,b);
    }

/*    template <typename T1, typename T2>
    ostream& itertools::productC::operator<<(ostream &os, const pair<T1,T2>& pair1) {
        os << pair1.first << "," << pair1.second;
        return os;
    }*/
}

#endif //EX5_PRODUCT_HPP
