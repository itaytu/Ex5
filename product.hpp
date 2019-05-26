#ifndef EX5_PRODUCT_HPP
#define EX5_PRODUCT_HPP

#include <utility>
#include "zip.hpp"

namespace itertools {
    template <typename T1, typename T2>
    class productC {
        const T1 a;
        const T2 b;
    public:
        productC(const T1& a, const T2& b) : a(a), b(b){}
        productC(){}

        class iterator{
        public:
            decltype(b.begin()) bConst;
            decltype(a.begin()) aBegin;
            decltype(a.end()) aEnd;
            decltype(b.begin()) bBegin;
            decltype(b.end()) bEnd;

            iterator(const T1& a, const T2& b) :
                    aBegin(a.begin()),
                    aEnd(a.end()),
                    bBegin(b.begin()),
                    bEnd(b.end()),
                    bConst(b.begin())
            {}

            iterator(const T1& a, const T2& b, const bool flag) :
                    aBegin(a.end()),
                    aEnd(a.end()),
                    bBegin(b.end()),
                    bEnd(b.end()),
                    bConst(b.begin())
            {}

            auto operator*() const {
                return make_pair(*aBegin, *bBegin);
            }
            iterator& operator++() {
                if(aBegin != aEnd) {
                        ++bBegin;
                }
                if(bBegin == bEnd) {
                    bBegin = bConst;
                    ++aBegin;
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

    template<typename T1, typename T2> productC<T1, T2> product(T1 a, T2 b) {
        return productC<T1, T2>(a,b);
    }

}

#endif //EX5_PRODUCT_HPP
