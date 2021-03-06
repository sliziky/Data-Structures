#include <algorithm>
#ifndef STACK
#define STACK
#define DEFAULT_SIZE 5

template <class T>
class Stack {
	
public:
	Stack();
	Stack(const Stack<T> &obj);
	Stack& operator=(const Stack<T> &obj);
	~Stack();
	T pop();
    	void swap(Stack<T> &first, Stack<T> &second);
	void push(const T& num);
	void resize(const int& size);
	void print();

private:
	T * buffer;
	unsigned int actualSize;
	unsigned int maxSize;	
};
template <class T>
Stack<T>::Stack() :  // default constructor
    maxSize(DEFAULT_SIZE), 
    actualSize(0), 
    buffer(new T[DEFAULT_SIZE]) {}

template <class T>
Stack<T>::Stack(const Stack<T> &obj):  // copy constructor 
    buffer(new T[obj.actualSize]),
    actualSize(obj.actualSize),
    maxSize(obj.maxSize) {
    std::copy(obj.buffer, obj.buffer + obj.actualSize, buffer);
}      

template <class T>
Stack<T>&  Stack<T>::operator=(const Stack<T> &obj) {  // copy assignment
    swap(*this, obj);
    return *this;
}

template <class T>
void Stack<T>::swap(Stack<T> &first, Stack<T> &second) {  // copynswap idiom 
    std::swap(first.buffer,second.buffer);
    std::swap(first.actualSize, second.actualSize);
    std::swap(first.maxSize, second.maxSize);
}

template <class T>
void Stack<T>::push(const T& num) {  // push number into stack
	if (actualSize >= maxSize) {
		maxSize += 5;
		resize(maxSize);
	}
	buffer[actualSize++] = num;
}

template <class T>
void Stack<T>::resize(const int& size) {  // resize stack and copy elements into new stack
	T* temp = new T[size];
	std::copy(buffer, buffer + actualSize, temp);
	delete[] buffer;
	buffer = temp;              
}

template <class T>
void Stack<T>::print() {  
    /*for (auto i : buffer) {
        std::cout << i << std::endl;
    }*/

	for (int i = 0; i < actualSize; i++) {
		std::cout << buffer[i] << std::endl;
	}
}


template <class T>
T Stack<T>::pop() {
	if (actualSize > 0)  
		return buffer[--actualSize];
}

template <class T>
Stack<T>::~Stack() {  // destructor
	delete[] buffer;
}

#endif
