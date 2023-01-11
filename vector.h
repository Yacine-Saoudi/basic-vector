// vector.h
#include <array>

// using namespace std;

template<typename T>
class vector {
    // current amount of elements in the array
    int size;
    // current max size of the vector
    int capacity;
    // array the vector uses
    T* arr;

    public:

    vector(const vector&); //copy constructor
    vector& operator=(vector); //copy assignment

    vector(vector&&); //move constructor
    vector& operator=(vector&&); //move assignment

    vector(); // default constructor

    ~vector();

    T operator[](int);
    void reserve(int);
    void print();
    void push(T);
    friend void swap(vector<T>&, vector<T>&);
    T pop();

    int length();
    int max_capacity();
};

