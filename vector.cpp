// Cpp file header
#include "vector.h"
#include <iostream>
#include <string>
#include <thread>

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

// swap two vector's attributes
template<class T>
void swap(vector<T>& first, vector<T>& second){
    using std::swap;
    swap(first.size, second.size);
    swap(first.capacity, second.capacity);
    swap(first.arr, second.arr);
    swap(first.mutex, second.mutex);
}

// destructor
template<class T>
vector<T>::~vector(){
    delete [] arr;
}

// subscript access operator 
template<class T>
T vector<T>::operator[](int index){
    const std::lock_guard<std::mutex> lock(mutex);
    return arr[index];
}

// print array's elements
template<class T>
void vector<T>::print(){
    const std::lock_guard<std::mutex> lock(mutex);
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

// change capacity of array and move elements to new array
template<class T>
void vector<T>::reserve(int newcap){
    using std::swap;
    this->capacity = newcap;
    T* temp = new T[newcap];
    swap(temp, arr);
    delete[] arr;
    arr = temp;
}

// push new element into vector array
template<class T>
void vector<T>::push(T element){
    const std::lock_guard<std::mutex> lock(mutex);
    if(size == capacity){
        this->reserve(2*size);
    }
    arr[size++] = element;
}

// remove top element of vector
template<class T>
void vector<T>::pop(){
    const std::lock_guard<std::mutex> lock(mutex);
    if(size <= 0) throw;
    if(size/3 > capacity){
        reserve(size/2);
    }
    T ret = arr[size];
    arr[size--] = 0;
    // return ret;
}

// get length of vector
template<class T>
int vector<T>::length(){
    const std::lock_guard<std::mutex> lock(mutex);
    return size;
}

// capacity
template<class T>
int vector<T>::max_capacity(){
    const std::lock_guard<std::mutex> lock(mutex);
    return capacity;
}

void fill(vector<char>* v){
    printf("filling...\n");
    for(int i = 0; i < 100; i++){
        std::cout << "filling" << std::endl;
        v->push('a');
    }
}

void empty(vector<char>* v){
    printf("emptying...\n");
    while(v->length() > 0){
        std::cout << "emptying" << std::endl;
        v->pop();
    }
}

void read(vector<char>* v){
    printf("reading...\n");
    for (int i = 0; i < v->length(); i++){
        std::cout << v->operator[](1) << std::endl;
    }
    
}

int main(){
    vector<char> *big = new vector<char>;

    std::thread t1(fill, big);
    std::thread t2(empty, big);
    std::thread t3(read, big);

    t1.join();
    t2.join();
    t3.join();

    big->print();
    return 0;
}