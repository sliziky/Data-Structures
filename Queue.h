#ifndef QUEUE
#define QUEUE
#define DEFAULT_SIZE 5
#include <iostream>
#include <exception>

template <typename T>
class Queue {

private:
    T * buffer;
    unsigned int actualSize;
    unsigned int maxSize;

public:
    Queue();
    Queue(const Queue<T> &obj);
    Queue& operator=(const Queue<T> &obj);
    ~Queue();

    void error();
    T pop();
    void print();
    void push(T num);
    void resize(int size);
    void swap(const Queue<T> &queue1, const Queue<T> &queue2);
};

template <typename T>
Queue<T>::Queue() :
    actualSize(0),
    maxSize(DEFAULT_SIZE),
    buffer(new T[DEFAULT_SIZE]) {}

template <typename T>
Queue<T>::Queue(const Queue& obj) : 
    actualSize(obj.actualSize),
    maxSize(obj.maxSize),
    buffer(new T[obj.actualSize])
    {
    std::copy(obj.buffer, obj.buffer + obj.actualSize, buffer);
    }

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& obj) {
    swap(*this,obj);
    return *this;
}

template <typename T>
Queue<T>::~Queue() {
    delete[] buffer;
}

template <typename T>
void Queue<T>::error() {
    std::cout << "Popping from empty queue ! \nTERMINATING " << std::endl;
    getchar();
    std::exit(1);
}

template <typename T>
T Queue<T>::pop() {
    if (actualSize == 0)
        error();
    T res = buffer[--actualSize];
    for (int i = 0; i < actualSize; ++i) {
        buffer[i] = buffer[i + 1];
    }
    return res;
}

template <typename T>
void Queue<T>::print() {
    for (int i = 0; i < actualSize; ++i)
        std::cout << buffer[i] << " ";
    std::cout << std::endl;
}

template <typename T>
void Queue<T>::push(T obj) {
    if (actualSize >= maxSize) {
        maxSize += 5;
        resize(maxSize);
    }
    buffer[actualSize++] = obj;
}

template <typename T>
void Queue<T>::resize(int size) {
    T* temp = new T[size];
    std::copy(buffer, buffer + actualSize, temp);
    delete[] buffer;
    buffer = temp;
}

template <typename T>
void Queue<T>::swap(const Queue<T> &q1, const Queue<T> &q2) {
    std::swap(q1.actualSize, q2.actualSize);
    std::swap(q1.maxSize, q2.maxSize);
    std::swap(q1.buffer, q2.buffer);
}

#endif
