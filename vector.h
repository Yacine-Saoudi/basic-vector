// vector.h
#include <array>

// using namespace std;

template<typename T>
class vector {
    // current amount of elements in the array
    std::size_t size;
    // current max size of the vector
    std::size_t capacity;
    // array the vector uses
    T* arr;

    public:

    vector(const vector&); //copy constructor
    vector& operator=(const vector&); //copy assignment

    vector(vector&&); //move constructor
    vector& operator=(vector&&); //move assignment


    vector(T t, int i); //duplicate constructor
    vector(); // defailt constructor

    ~vector();

    T operator[](int);
    void resize();
    void reserve(int);
    void print();
    void push(T element);
    void swap(T element, int index);
    T pop();

    const std::array<T, 256> getarr();
    size_t length();
    size_t max_size();
    size_t capacity();
};
// template<class T>
// class vector
// {
//     void print() {}
// };

