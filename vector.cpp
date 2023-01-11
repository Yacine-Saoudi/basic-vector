// Cpp file header
#include "vector.h"
#include <iostream>
#include <string>

template<class T>
vector<T>::vector(const vector& other) : capacity(other.capacity), size(other.size) { //copy constructor
    arr = new T[other.capacity];
    memcpy(arr, other.arr, sizeof(T[other.capacity]));
    
}

template<class T>
vector<T>& vector<T>::operator=(vector other){ //copy assignment
    swap(*this, other);
    return *this;
}

template<class T>
vector<T>::vector(vector&& other): vector() { //move constructor
    swap(*this, other);
}

template<class T>
vector<T>& vector<T>::operator=(vector&& other) { //move assignment
    swap(*this, other);
    return *this;
}

// default constructor
template<class T>
vector<T>::vector(){
    arr = new T[1];
    size = 0;
    capacity = 1;
}

template<class T>
void swap(vector<T>& first, vector<T>& second){
    using std::swap;

    swap(first.size, second.size);
    swap(first.capacity, second.capacity);
    swap(first.arr, second.arr);
}

// destructor
template<class T>
vector<T>::~vector(){
    delete [] arr;
}

// subscript access operator 
// TODO: add error handling
template<class T>
T vector<T>::operator[](int index){
    return arr[index];
}

// print array
template<class T>
void vector<T>::print(){
    std::cout << "[";
    for(int i = 0; i < size; i++){
        if(i > 0){
            std::cout<< ' ';
        }
        std::cout << arr[i];
        if(i < size-1){
            std::cout<< ',';
        }
    }
    std::cout << "]" << std::endl;
}


template<class T>
void vector<T>::reserve(int newcap){
    this->capacity = newcap;
    T* temp = new T[newcap];
    for(int i = 0; i < size; i++){
        temp[i] = arr[i];
    }

    delete[] arr;
    arr = temp;
}

// push new element into vector array
template<class T>
void vector<T>::push(T element){
    if(size == capacity){
        this->reserve(2*size);
    }
    arr[size++] = element;
}

// swap element
// template<class T>
// void vector<T>::swap(vector<T>& first, vector<T>& second){
//     using std::swap;

//     swap(first.size, second.size);
//     swap(first.capacity, second.capacity);
//     swap(first.arr, second.arr);
// }

// pop
template<class T>
T vector<T>::pop(){
    if(size <= 0) throw;
    if(size/3 > capacity){
        reserve(size/2);
    }
    T ret = arr[size];
    arr[size--] = 0;
    return ret;
}

// get length of vector
template<class T>
int vector<T>::length(){
    return size;
}

// capacity
template<class T>
int vector<T>::max_capacity(){
    return this->capacity;
}


int main(){
    vector<char> v;
    v.max_capacity();
    v.push('1');
    v.push('2');
    v.push('3');
    v.push('4');
    vector<char> d = v;
    d.print();
    v.pop();
    d.print();
    return 0;

}