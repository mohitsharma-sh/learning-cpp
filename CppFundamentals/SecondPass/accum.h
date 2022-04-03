#pragma once

template <class T>
class Accum
{
    private:
        T total;
    public:
        Accum(T start): total(start){}
        void operator+=(T const& item){total += item;}
        T getTotal() const {return total;}
};

