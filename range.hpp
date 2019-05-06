//
// Created by Itayt on 5/5/2019.
//

#ifndef EX5_RANGE_HPP
#define EX5_RANGE_HPP

#include "iostream"

namespace itertools {
    template <typename T> class range {
    public:
        typedef T* pointer;
        T rng1, rng2;

        range(T rng1, T rng2) {
            this->rng1 = rng1;
            this->rng2 = rng2;
        }

        //-------------------------------------------------------------------
        // iterator related code:
        // inner class and methods that return instances of it)
        //-------------------------------------------------------------------
        class iterator {
        private:
            pointer ptr;
        public:
            explicit iterator(pointer ptr = nullptr): ptr(ptr) {}

            // Note that the method is const as this operator does not
            // allow changing of the iterator.
            // Note that it returns T& as it allows to change what it points to.
            // A const_iterator class will return const T&
            // and the method will still be const
            T& operator*() const {
                return *ptr;
            }

            iterator& operator++() {
                (*ptr)++;
                return *this;
            }

            const iterator operator++(int) {
                iterator tmp = *this;
                ptr++;
                return tmp;
            }

            bool operator==(const iterator &it) const {
                return *ptr == *it.ptr;
            }

            bool operator!=(const iterator& it) const {
                return *ptr != *it.ptr;
            }

        };// END OF CLASS ITERATOR

        iterator begin() {
            return iterator{&rng1};
        }

        iterator end() {
            return iterator{&rng2};
        }

    };
}

#endif //EX5_RANGE_HPP
