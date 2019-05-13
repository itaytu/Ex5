//
// Created by Itayt on 5/5/2019.
//

#ifndef EX5_POWERSET_HPP
#define EX5_POWERSET_HPP

namespace itertools {
    template <typename T>
    class powersetC {
        T a;
        powersetC(T t) :a(t){}
        class iterator{
            iterator();
            auto operator*() const{
                return;
            }
            iterator& operator++(){ return ;}
            bool operator==(const iterator &it) const{ return true ;}
            bool operator!=(const iterator& it) const { return true;}
        };
        iterator begin() const {
            return iterator();
        }

        iterator end() const {
            return iterator();
        }
    };
    template <typename T> powersetC<T> powerset(T t){
        return powersetC<T>(t);
    }
}

#endif //EX5_POWERSET_HPP
