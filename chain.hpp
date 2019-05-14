#ifndef EX5_CHAIN_HPP
#define EX5_CHAIN_HPP

#include "range.hpp"

namespace itertools {
    template <typename T1, typename T2> class chainC {
    public:
        T1 p1;
        T2 p2;

        chainC(T1& t1, T2& t2):
            p1(t1),
            p2(t2)
        {}

        class iterator {
        public:
            decltype(p1.begin()) p1Start;
            decltype(p1.end()) p1End;
            decltype(p2.begin()) p2Start;
            decltype(p2.end()) p2End;

            iterator(T1& p1, T2& p2):
                p1Start(p1.begin()),
                p1End(p1.end()),
                p2Start(p2.begin()),
                p2End(p2.end())
            {}

            iterator(T1& p1, T2& p2, bool flag):
                p1Start(p1.end()),
                p1End(p1.end()),
                p2Start(p2.end()),
                p2End(p2.end())
            {}

            auto operator*() const {
                if(p1Start != p1End) return *p1Start;
                else return *p2Start;
            }

            iterator& operator++() {
                if(p1Start != p1End) p1Start++;
                else if(p2Start != p2End) p2Start++;
                return *this;
            }

           const iterator operator++(int) {
                iterator tmp;
                if(p1Start != p1End) {
                    tmp = p1Start;
                    p1Start++;
                }
                else {
                    tmp = p2Start;
                    p2Start++;
                }
                return tmp;
            }

            bool operator==(const iterator &it) const {
                return (p1Start == it.p2Start || p2Start == it.p2Start);
            }

            bool operator!=(const iterator& it) const {
                return (p1Start != it.p1Start || p2Start != it.p2Start);
            }

        };// END OF CLASS ITERATOR

        iterator begin() {
            return iterator(p1, p2);
        }

        iterator end() {
            return iterator(p1, p2, false);
        }
    };

    template<typename T1, typename T2> chainC<T1, T2> chain(T1 a, T2 b) {
        return chainC<T1, T2>(a,b);
    }
}

#endif //EX5_CHAIN_HPP
