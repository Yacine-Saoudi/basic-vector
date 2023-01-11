// Cpp file header
#include "vector.h"
#include <iostream>
#include <string>

// using namespace vector;
// using namespace std;
// vector(const vector&); //copy constructor
// vector& operator=(vector&&); //copy assignment

// vector(vector&&); //move constructor
// vector& operator=(vector&&); //move assignment

template<class T>
vector<T>::vector(const vector& v){ //copy constructor
        size = v.size;
        arr = v.arr;
}

template<class T>
vector<T>& vector<T>::operator=(const vector& v){ //copy assignment
        size = v.size;
        arr = v.arr;
}

template<class T>
vector<T>::vector(vector&& v){

}

template<class T>
vector<T>& vector<T>::operator=(vector&& v){

}

// parameterized constructor
template<class T>
vector<T>::vector(T t, int i){
    size = i;
    for (int j=0; j < size; j++){
        arr[j] = t;
    }
    
}

// default constructor
template<class T>
vector<T>::vector(){
    arr = new T[1];
    size = 0;
    capacity = 1;
}

template<class T>
vector<T>::~vector(){
    delete [] arr;
}

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
void vector<T>::resize(){

}

template<class T>
void vector<T>::reserve(int newcapacity){
    // set the new capacity to reserve
}

// push
template<class T>
void vector<T>::push(T element){
    if(size == capacity){
        this->resize();
    }
    else{
        arr[size++] = element;
    }
}

// swap element
template<class T>
void vector<T>::swap(T element, int index){
    if(index < 0 || index > size) throw;
    arr[index] = element;
}

// pop
template<class T>
T vector<T>::pop(){
    T ret = arr[size];
    arr[size--] = 0;
    return ret;
}

// get length of vector
template<class T>
size_t vector<T>::length(){
    return size;
}

// max size
template<class T>
size_t vector<T>::max_size(){
    return 256;
}

// capacity
template<class T>
size_t vector<T>::capacity(){
    return 256-size;
}

// get array
template<class T>
const std::array<T, 256> vector<T>::getarr(){
    return this->arr;
}

int main(){
    vector<char> v;
    v.print();
    v.push('y');
    v.push('a');
    v.push('c');
    v.push('i');
    v.push('n');
    std::cout << v.length() << std::endl;
    v.print();
    v.pop();
    v.swap('p', 1);
    char out = v.pop();
    v.print();
    std::cout << out << std::endl;

    vector<int> b(10, 10);
    b.print();

    vector<int> c = b;
    c.print();

    vector<char> d(v);
    
    d.pop();
    d.pop();
    d.print();
    v.print();
    using namespace std;
    cout << d[1] << endl;

    return 0;
}