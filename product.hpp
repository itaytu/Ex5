#ifndef EX5_PRODUCT_HPP
#define EX5_PRODUCT_HPP

#include <utility>
#include "zip.hpp"

namespace itertools {
    template <typename T1, typename T2>
    class product {
        const T1 a;
        const T2 b;
    public:
        product(const T1& a, const T2& b) : a(a), b(b){}
        product(){}

        class iterator{
        public:
            decltype(b.begin()) bConst;
            decltype(a.begin()) aBegin;
            decltype(a.end()) aEnd;
            decltype(b.begin()) bBegin;
            decltype(b.end()) bEnd;
            pair < decltype(b.begin()), decltype(b.end())> pair1;

            iterator(const T1& a, const T2& b) :
                    aBegin(a.begin()),
                    aEnd(a.end()),
                    bBegin(b.begin()),
                    bEnd(b.end()),
                    bConst(b.begin()),
                    pair1(std::make_pair(b.begin(),b.end()))
            {}

            iterator(const T1& a, const T2& b, const bool flag) :
                    aBegin(a.end()),
                    aEnd(a.end()),
                    bBegin(b.end()),
                    bEnd(b.end()),
                    bConst(b.begin()),
                    pair1(std::make_pair(b.begin(),b.end()))
            {}

            auto operator*() const {
                return make_pair(*aBegin, *bBegin);
            }
            iterator& operator++() {
                ++bBegin;
                if (!(bBegin != pair1.second)) {
                    ++aBegin;
                    bBegin = pair1.first;
                }
                return *this;
            }

            bool operator==(const iterator &it) const {
                return (aBegin == it.aBegin && bBegin == it.bBegin);
            }

            bool operator!=(const iterator& it) const {
                return (aBegin != it.aBegin && bBegin != it.bBegin);
            }
        };

        iterator begin() const {
            return iterator(a, b);
        }

        iterator end() const {
            return iterator(a, b, false);
        }

        int size() const {
            return a.size() + b.size();
        }

    };


}

#endif //EX5_PRODUCT_HPP
