#ifndef EX5_POWERSET_HPP
#define EX5_POWERSET_HPP

#include <math.h>
#include <iostream>
#include "product.hpp"

namespace itertools {
    template <typename T>
    class powersetC {
    public:
        const T a;
        const int size;
        powersetC(){}
        powersetC(const T& t) :
                a(t),
                size(pow(2, a.size()))
        {}

        class iterator{
        public:
            decltype(a.begin()) aBegin;
            decltype(a.begin()) aConst;
            int length;
            int begin;
            int end;
            string powStr;

            iterator(const T& a, int t) :
                    aBegin(a.begin()),
                    aConst(a.begin())
            {
                begin=t;
                end=pow(2,a.size());
                length=a.size();}

            auto operator*() const{
                return powStr;
            }

            iterator& operator++(){
                powStr= "";
                if(begin != end) {
                    powStr += "{";
                    for (int i = 0; i < length; ++i) {
                        if((begin & (1 << i))) {
                            if(*aBegin <= 'z' && *aBegin >= 'a'){
                                powStr += *aBegin ;
                            }
                            else {
                                powStr += to_string(*aBegin) ;
                            }
                            powStr += ",";
                        }
                        ++aBegin;
                    }
                    if(powStr.back() == ',') powStr = powStr.substr(0, powStr.size()-1);
                    begin++;
                    powStr += "}";
                }
                aBegin = aConst;
                return *this;
            }

            bool operator==(const iterator &it) const{
                return(aBegin == it.aBegin);
            }

            bool operator!=(const iterator& it) const {
                return (begin != it.begin);
            }

        };

        iterator begin() const {
            return iterator(a, 0);
        }

        iterator end() const {
            return iterator(a, size);
        }
    };

    template <typename T> powersetC<T> powerset(T t){
        return powersetC<T>(t);
    }
}

#endif //EX5_POWERSET_HPP

