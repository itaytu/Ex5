#ifndef EX5_CHAIN_HPP
#define EX5_CHAIN_HPP

#include "range.hpp"

namespace itertools {
    template <typename T1, typename T2> class chainC {
    public:
        T1 a;
        T2 b;
        chainC(T1& t1, T2& t2):
            a(t1),
            b(t2)
        {}

        chainC(){}

        class iterator {
        public:
            decltype(a.begin()) aBegin;
            decltype(a.end()) aEnd;
            decltype(b.begin()) bBegin;
            decltype(b.end()) bEnd;

            iterator(T1& a, T2& b):
                aBegin(a.begin()),
                aEnd(a.end()),
                bBegin(b.begin()),
                bEnd(b.end())
            {}

            iterator(T1& a, T2& b, bool flag):
                aBegin(a.end()),
                aEnd(a.end()),
                bBegin(b.end()),
                bEnd(b.end())
            {}

            iterator() {}

            auto operator*() const {
                if(aBegin != aEnd) return *aBegin;
                else return *bBegin;
            }

            iterator& operator++() {
                if(aBegin != aEnd) ++aBegin;
                else if(bBegin != bEnd) ++bBegin;
                return *this;
            }

          const iterator operator++(int) {
                iterator tmp;
                if(aBegin != aEnd) {
                    tmp = aBegin;
                    aBegin++;
                }
                else {
                    tmp = bBegin;
                    bBegin++;
                }
                return tmp;
            }

            bool operator==(const iterator &it) const {
                return (aBegin == it.aBegin || bBegin == it.bBegin);
            }

            bool operator!=(const iterator& it) const {
                return (aBegin != it.aBegin || bBegin != it.bBegin);
            }

        };// END OF CLASS ITERATOR

        iterator begin() {
            return iterator(a, b);
        }

        iterator end() {
            return iterator(a, b, false);
        }
    };

    template<typename T1, typename T2> chainC<T1, T2> chain(T1 a, T2 b) {
        return chainC<T1, T2>(a,b);
    }
}

#endif //EX5_CHAIN_HPP
