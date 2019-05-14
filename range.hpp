#ifndef EX5_RANGE_HPP
#define EX5_RANGE_HPP

#include "iostream"

namespace itertools {
    template <typename T> class rangeC {
    public:
        T rng1, rng2;

        rangeC(T rng1, T rng2) :
            rng1(rng1), rng2(rng2){}

        class iterator {
        public:
            decltype(rng1) ptr;

            explicit iterator(T pointer) : ptr(pointer){}

            auto operator*() const {
                return ptr;
            }

            iterator& operator++() {
                ++ptr;
                return *this;
            }

          const iterator operator++(int) {
                iterator tmp = *this;
                ptr++;
                return tmp;
            }

             bool operator==(const iterator &it) const {
                return ptr == it.ptr;
            }

            bool operator!=(const iterator& it) const {
                return ptr != it.ptr;
            }

        };// END OF CLASS ITERATOR

        iterator begin()  {
            return iterator{rng1};
        }

        iterator end() {
            return iterator{rng2};
        }

        int size() {
            int counter=0;
            for (auto i: rangeC(rng1, rng2)) {
                counter++;
            }
            return counter;
        }

    };

      template<typename T> rangeC<T> range(T a, T b) {
        return rangeC<T>(a,b);
    }
}

#endif //EX5_RANGE_HPP
