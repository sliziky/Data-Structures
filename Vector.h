#ifndef VECTOR
#define VECTOR
#define INITIAL_SIZE 10
#include <iostream>
template <class T>
class Vector2 {
	
private:
    unsigned int currentSize;
    unsigned int maxSize;
    T * buffer;
	
public:
    Vector2();
    Vector2(int size);
    Vector2(const Vector2<T> &source);
    ~Vector2();
    Vector2<T> &operator=(const Vector2<T> &source);
    void swap(Vector2<T> &n1, Vector2<T> &n2);
    void push_back(const T &num);
    void print();
    void resize(int num);
};

template <class T>
Vector2<T>::Vector2() :
    currentSize(0),
    maxSize(INITIAL_SIZE),
    buffer (new T[INITIAL_SIZE])
    {}

template <class T>
Vector2<T>::Vector2(int size) : 
    currentSize(size), 
    maxSize(size), 
    buffer(new T[size]) 
    {}

template <class T>
Vector2<T>::Vector2(const Vector2<T> &source) :
    maxSize(source.maxSize), 
    currentSize(source.currentSize) {
    std::copy(source.buffer, source.buffer + source.currentSize, buffer);
}

template <class T>
Vector2<T> & Vector2<T>::operator=(const Vector2<T> &source) {
    swap(*this, source);
    return *this;
}

template <class T>
void Vector2<T>::push_back(const T &num) {
    if (currentSize >= maxSize) {
	maxSize += 5;
	resize(maxSize);
	}
    buffer[currentSize++] = num;
}

template <class T>
void Vector2<T>::swap(Vector2<T> &n1, Vector2<T> &n2) {
    std::swap(n1.buffer, n2.buffer);
    std::swap(n1.currentSize, n2.currentSize);
    std::swap(n1.maxSize, n2.maxSize);
}

template <class T>
void Vector2<T>::print() {
    for (int i = 0; i < currentSize; ++i)
	std::cout << buffer[i] << std::endl;
}

template <class T>
Vector2<T>::~Vector2() {
    delete[ ] buffer;
}

template <class T>
void Vector2<T>::resize(int num) {
    T * temp = new T[num]; 
    std::copy(buffer, buffer + currentSize, temp);
    delete[ ] buffer;
    buffer = temp;
}
#endif
