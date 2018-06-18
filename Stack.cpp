// Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"
#include <assert.h>
#include <iostream>

Stack::Stack()
{
	Stack::sizeOfStack = 0;
}

Stack::~Stack() {
	delete[] Stack::st;
}

void Stack::push(int num) {
	Stack::st[sizeOfStack++] = num;
}

int Stack::size() {
	return Stack::sizeOfStack;
}

bool Stack::isEmpty() {
	return Stack::sizeOfStack == 0;
}

int Stack::pop() {
	assert(!(Stack::sizeOfStack == 0));
	return Stack::st[sizeOfStack--];
}

void Stack::print() {
	for (int i = 0; i < Stack::sizeOfStack; ++i)
		std::cout << Stack::st[i] << " ";
	std::cout << std::endl;
}