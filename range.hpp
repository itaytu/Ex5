//
// Created by Itayt on 5/5/2019.
//

#ifndef EX5_RANGE_HPP
#define EX5_RANGE_HPP

#include "iostream"

namespace itertools {
    template <typename T> class rangeC {
    public:
        T rng1, rng2;

        rangeC(T& rng1, T& rng2) {
            this->rng1 = rng1;
            this->rng2 = rng2;
        }

        rangeC(){}

        //-------------------------------------------------------------------
        // iterator related code:
        // inner class and methods that return instances of it)
        //-------------------------------------------------------------------
        class iterator {
        private:
            T ptr;
        public:
            //explicit iterator(T ptr = nullptr): ptr(ptr) {}

            iterator() { ptr = nullptr; }

            explicit iterator(T pointer) {
                ptr = pointer;
            }

            T operator*() const {
                return ptr;
            }

            iterator& operator++() {
                ptr++;
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

        iterator begin() {
            return iterator{rng1};
        }

        iterator end() {
            return iterator{rng2};
        }
    };
      template<typename T> rangeC<T> range(T a, T b) {
        return rangeC<T>(a,b);
    }
}

#endif //EX5_RANGE_HPP
