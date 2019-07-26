#include<iostream>

#ifndef __STACK__
#define __STACK__

using namespace std;

template <typename T>

class Stack{

private:
	int size;
	int top;
public:
	T *stack;
private:
	bool isFull(){
		if(top==size){
			return 1;

		}else{
			return 0;
		}
	}	
public:
	Stack(){}

	Stack(int size){
		this->size=size;
		this->top=0;
		this->stack=new T[size];

	}
	bool isEmpty(){
		if(top==0){
			return 1;
		}else{
			return 0;
		}
	}
	
	void push(T data){
		if(isFull()){
			cout<<"stack is full"<<endl;
			return;
		}else{
			stack[top]=data;
			top++;
			
		}

	}
	T pop(){
		if(isEmpty()){
			T temp;
			cout<<"stack is empty"<<endl;
			return temp;
		}else{
			top--;
			return stack[top];
		}
	}
void print(){
	for(int i=0;i<top;i++){
		cout<<stack[i];
	}

}
};

#endif

