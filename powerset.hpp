#ifndef EX5_POWERSET_HPP
#define EX5_POWERSET_HPP

#include <math.h>
#include <iostream>
#include "product.hpp"

namespace itertools {
    template <typename T>
    class powerset {
    public:
        const T a;
        int size;

        powerset(){}
        powerset(const T& t) :
                a(t)
        {
            int s=0;
            auto start=a.begin();
            while (start!=a.end()){
                ++start;
                s++;
            }
            size=s;
        }


        class iterator{
        public:
            std::pair <unsigned int, T> pair1;
     /*       decltype(a.begin()) aBegin;
            decltype(a.begin()) aConst;
            int length;
            int begin;
            int end;
            string powStr;*/

            iterator(const std::pair  <unsigned int, T> & p2) :
                    pair1(p2){}

            auto operator*(){
                return pair1;
            }

            iterator& operator++(){
                pair1.first++;
                return *this;
            }

            bool operator==(const iterator &it) const{
                return(pair1.first == it.pair1.first);
            }

            bool operator!=(const iterator& it) const {
                return (pair1.first != it.pair1.first);
            }

        };

        iterator begin() const {
            return iterator(std::pair <unsigned int, T> (0,a));        }

        iterator end() const {
            int i=1;
            for(int k=0;k<size;k++){
                i=i<<1;
            }
            return iterator(std::pair <unsigned int, T> (i,a));
        }
    };

    template<typename T> ostream &operator<<(ostream &out, pair<unsigned int, T> &p)
    {
        string ans="";
        out << '{';
        bool first=true;
        auto startT = p.second.begin() ;
        auto endT = p.second.end();
        int i=1;
        while(startT!=endT)
        {
            if(i&p.first)
            {
                if(first)
                {
                    out<<*startT;
                    first=false;
                }
                else
                    out<<','<<*startT;
            }
            i=i<<1;
            ++startT;
        }
        out <<'}';
        return out;
    }
}

#endif //EX5_POWERSET_HPP

