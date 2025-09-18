#include <cstddef>
#include <algorithm>
#include <initializer_list> 

template <typename T>
class Vector {
private:
    T* data = nullptr;
    size_t size = 0;;
    size_t capacity = 0;
public:
    Vector() = default; //default

    Vector(size_t n)    //one parametr - size
        : data(new T[n]())
        , size(n)
        , capacity(n) {
    }

    Vector(size_t n, T value)   //two parametres - size and value
            : data(new T[n])
            , size(n)
            , capacity(n) {

        for (size_t i = 0; i < n; ++i) {
            data[i] = value;
        }
    }

    Vector(const Vector& v) //copy construstor
            : data(new T[v.size])
            , size(v.size)
            , capacity(v.capacity) {
        
        for (size_t i = 0; i < size; ++i) {
            data[i] = v.data[i];
        }
    }

    Vector(std::initializer_list<T> list) 
            : data(new T[list.size()])
            , size(list.size())
            , capacity(list.size()) {

        std::copy(list.begin(), list.end(), data);
    }

    ~Vector() { //destructer
        for (size_t i = 0; i < size; ++i) {
            data[i].~T();
        }
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
    }
};
