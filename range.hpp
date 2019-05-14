#ifndef EX5_RANGE_HPP
#define EX5_RANGE_HPP

#include "iostream"

namespace itertools {
    template <typename T> class rangeC {
    public:
        const T rng1;
        const T rng2;
        rangeC(){}
        rangeC(const T& rng1, const T& rng2) :
            rng1(rng1), rng2(rng2){}

        class iterator {
        public:
           T ptr;

            iterator(const T pointer) : ptr(pointer){}

            iterator() {}

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

        iterator begin() const  {
            return iterator{rng1};
        }

        iterator end() const {
            return iterator{rng2};
        }

        int size() const {
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
