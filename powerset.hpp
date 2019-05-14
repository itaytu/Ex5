#ifndef EX5_POWERSET_HPP
#define EX5_POWERSET_HPP

#include <math.h>
#include <iostream>
#include "product.hpp"

namespace itertools {
    template <typename T>
    class powersetC {
    public:
        T a;
        int length;
        int size;

        powersetC(T t) :
        a(t),
        length(a.size()),
        size(pow(2, length))
        {}

        class iterator{
        public:
            decltype(a.begin()) aBegin;
            decltype(a.begin()) aConst;
            int length;
            int begin = 0;
            int end;
            string powStr = "";

            iterator(T& a, int t) :
            aBegin(a),
            aConst(a),
            begin(t),
            end(pow(2,a.size())),
            length(a.size())
            {}

            auto operator*() const{
                return powStr;
            }

            iterator& operator++(){
                powStr= "";
                if(begin != end) {
                    for (int i = 0; i < length; ++i) {
                        if((begin & (1 << i))) {
                            if(*aBegin <= 'z' && *aBegin >= 'a'){
                            }
                              // powStr += "{" + std::string(*aBegin) + "}";
                            else {
                               // powStr += "{" + to_string(*aBegin) + "}";
                            }
                        }
                            ++aBegin;
                    }
                    begin++;
                }
                aBegin = aConst;
            }

            bool operator==(const iterator &it) const{
                return(aBegin == it.aBegin);
            }

            bool operator!=(const iterator& it) const {
                return (begin != it.begin);
            }

        };

        iterator begin() {
            return iterator(a, 0);
        }

        iterator end() {
            return iterator(a, size);
        }
    };

    template <typename T> powersetC<T> powerset(T t){
        return powersetC<T>(t);
    }
}

#endif //EX5_POWERSET_HPP

