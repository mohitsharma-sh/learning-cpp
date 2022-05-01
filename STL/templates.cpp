#include<iostream>

template<typename T>
T square(T x)
{
    return x*x;
}

template<typename T>
class movector
{
    T arr[1000]; // Fixed size arr
    int size;

    public:
    movector(): size(0){};
    void push_back(T const& element){arr[size] = element; size++;}
    T get_item(int const i) const {return arr[i];}
    int get_size() const {return size;}
    void print()
    {
        for(int i=0; i<size;i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    T operator[](int i) const{return arr[i];}

};

template<typename T>
movector<T> operator*(movector<T> const& lhs, movector<T> const& rhs)
{
    movector<T> result;
    int size = lhs.get_size();
    for(auto i=0; i < size; i++)
    {
        result.push_back(lhs[i]*rhs[i]);
    }
    return result;
}

int main()
{
    std::cout << square<double>(5) << std::endl;

    movector<int> vec;
    for(auto i=0; i < 10; i++)
    {
        vec.push_back(i);
    }
    vec.print();

    movector<int> sq_vector = square(vec);
    sq_vector.print();
    return 0;
}

