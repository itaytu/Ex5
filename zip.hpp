#ifndef EX5_ZIP_HPP
#define EX5_ZIP_HPP

#include <utility>
#include "chain.hpp"

using namespace std;

namespace itertools {
    template <typename T1, typename T2> class zipC {
        T1 a;
        T2 b;
    public:
        zipC(T1 a, T2 b) : a(a), b(b) {}

        class iterator {
        public:
            decltype(a.begin()) aBegin;
            decltype(a.end()) aEnd;
            decltype(b.begin()) bBegin;
            decltype(b.end()) bEnd;

            iterator(T1& a, T2& b) :
            aBegin(a.begin()),
            aEnd(a.end()),
            bBegin(b.begin()),
            bEnd(b.end())
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
                    ++aBegin;
                    ++bBegin;
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

        int size() {
            return a.length() + b.length();
        }

    };

    template<typename T1, typename T2> zipC<T1, T2> zip(T1 a, T2 b) {
        return zipC<T1, T2>(a,b);
    }

    template <typename T1, typename T2>
    ostream& operator<<(ostream &os, const pair<T1,T2>& pair1) {
        os << pair1.first << "," << pair1.second;
        return os;
    }
}

#endif //EX5_ZIP_HPP
