#include<iostream>

#ifndef __QUEUE__
#define __QUEUE__

using namespace std;

template <typename T>

class Queue{
	private:
		int firstE;
		int lastE;
		int size;
		T* queue;

	public:

		Queue(){}

		Queue(int size){
			this->size=size;
			this->firstE=0;
			this->lastE=0;
			this->queue = new T[size];
		}
		bool isFull(){
			if(lastE>=size)
				return 1;
			return 0;
		}

		bool isEmpty(){
			if(firstE==lastE)
				return 1;
			return 0;
		}

		void enqueue(T data){

			if(isFull()){
				cout<<"Queue is Full"<<endl;
				return;
			}

			queue[this->lastE]=data;
			this->lastE++;

		}

		T dequeue(){
			T data;
			if(isEmpty()){
				cout<<"Queue is Empty"<<endl;
			
			}
			data=queue[this->firstE];
			this->firstE++;

			if(firstE==lastE){
				firstE=lastE=0;
			}
			return data;
		}

		void print(){
for(int i=firstE;i<size;i++){
			cout<<queue[i]<<endl;
}

		}
};
#endif
