#ifndef STACK
#define STACK
#include <vector>

class Stack {

	private:
		unsigned short sizeOfStack;
		int *st = new int[sizeOfStack];

	public:
		bool isEmpty();
		int pop();
		void print();
		void push(int num);
		int size();
		Stack();
		~Stack();
		
};
#endif 
