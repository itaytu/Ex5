#ifndef EX5_CHAIN_HPP
#define EX5_CHAIN_HPP

#include "range.hpp"

namespace itertools {
    template <class T1, class T2> class chain {
    public:
        typedef T1* p1;
        T1 cha1;
        T2 cha2;

        chain(T1 t1, T2 t2) {
            this->cha1 = t1;
            this->cha2 = t2;
        }

        class iterator {
        private:
            p1 ptr1;
        public:
            explicit iterator(p1 ptr1 = nullptr): ptr1(ptr1) {}

            // Note that the method is const as this operator does not
            // allow changing of the iterator.
            // Note that it returns T& as it allows to change what it points to.
            // A const_iterator class will return const T&
            // and the method will still be const
            T1& operator*() const {
                return *ptr1;
            }

            iterator& operator++() {
                (*ptr1)++;
                return *this;
            }

            const iterator operator++(int) {
                iterator tmp = *this;
                ptr1++;
                return tmp;
            }

            bool operator==(const iterator &it) const {
                return *ptr1 == *it.ptr;
            }

            bool operator!=(const iterator& it) const {
                return *ptr1 != *it.ptr;
            }

        };// END OF CLASS ITERATOR

        iterator begin() {
            return iterator{&cha1};
        }

        iterator end() {
            return iterator{&cha2};
        }
    };
}

#endif //EX5_CHAIN_HPP
