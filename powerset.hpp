/*
#ifndef EX5_POWERSET_HPP
#define EX5_POWERSET_HPP

namespace itertools {
    template <typename T>
    class powersetC {
        T a;
        powersetC(T t) :a(t){}
        class iterator{
            decltype(a.begin()) aBegin;

            iterator(T& a) : aBegin(a) {}

            auto operator*() const{
                return;
            }
            iterator& operator++(){ return ;}
            bool operator==(const iterator &it) const{ return true ;}
            bool operator!=(const iterator& it) const { return true;}
        };
        iterator begin() {
            return iterator(a);
        }

        iterator end() {
            return *this;
        }
    };

    template <typename T> powersetC<T> powerset(T t){
        return powersetC<T>(t);
    }
}

#endif //EX5_POWERSET_HPP
*/
