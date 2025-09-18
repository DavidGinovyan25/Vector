#include <algorithm>
#include <cstddef>
#include <initializer_list> 
#include <iostream>

template <typename T>
class Vector {
private:
    T* data_ptr = nullptr;
    size_t sz = 0;;
    size_t cap = 0;
public:
    Vector() = default; //default

    Vector(size_t n)    //one parametr - size
        : data_ptr(new T[n]())
        , sz(n)
        , cap(n) {
    }

    Vector(size_t n, T value)   //two parametres - sz and value
            : data_ptr(new T[n])
            , sz(n)
            , cap(n) {

        for (size_t i = 0; i < n; ++i) {
            data_ptr[i] = value;
        }
    }

    Vector(const Vector& v) //copy construstor
            : data_ptr(new T[v.sz])
            , sz(v.sz)
            , cap(v.cap) {
        
        for (size_t i = 0; i < sz; ++i) {
            data_ptr[i] = v.data_ptr[i];
        }
    }

    Vector(std::initializer_list<T> list) 
            : data_ptr(new T[list.size()])
            , sz(list.size())
            , cap(list.size()) {

        std::copy(list.begin(), list.end(), data_ptr);
    }

    ~Vector() { //destructer
        for (size_t i = 0; i < sz; ++i) {
            data_ptr[i].~T();
        }
        delete[] data_ptr;
        data_ptr = nullptr;
        sz = 0;
        cap = 0;
    }

    void swap(Vector& vector) {
        std::swap(data_ptr, vector.data_ptr);
        std::swap(sz, vector.sz);
        std::swap(cap, vector.cap);
    }

    Vector& operator=(const Vector& vector) {
        Vector temp(vector);
        swap(temp);
        return *this;
    }

    Vector& operator=(std::initializer_list<T> list) {
        Vector temp(list);
        swap(temp);
        return *this;
    }

    T& operator[](size_t index){
        return data_ptr[index];
    }

    const T& operator[](size_t index) const{
        return data_ptr[index];
    }

    T& at(size_t index){
        if (index >= sz)
            throw std::out_of_range("Index out of range");
        return data_ptr[index];
    }

    const T& at(size_t index) const{
        if (index >= sz)
            throw std::out_of_range("Index out of range");
        return data_ptr[index];
    }

    bool empty() {
        if (sz == 0)
            return true;
        return false;
    }

    T& front() {
        if (this->empty())
            throw std::out_of_range("Empty vector doesnt have front element");
        return data_ptr[0];
    } 

    const T& front() const{
        if (this->empty())
            throw std::out_of_range("Empty vector doesnt have front element");
        return data_ptr[0];
    } 

    T& back() {
        if (this->empty())
            throw std::out_of_range("Empty vector doesnt have back element");
        return data_ptr[0];
    } 

    const T& back() const{
        if (this->empty())
            throw std::out_of_range("Empty vector doesnt have back element");
        return data_ptr[0];
    } 

    T* data() {
        return this->data_ptr;
    }

    const T* data() const {
        return this->data_ptr;
    }

    size_t size() {
        return sz;
    }

    size_t capacity() {
        return cap;
    }
};


