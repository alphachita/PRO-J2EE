#include<iostream> 
using namespace std;

template <typename T>
class Node{

	private: 
		T data;
		Node* next;
	public:
		Node(){}
		Node(T data){
			this->data=data;
			this->next = NULL;
		}

		void setData(T data){

			this->data=data;
		}

		void setNext(Node *next){
			this->next=next;

		}

		T getData(){

			return data;
		}
		Node* getNext(){
			return next;
		}
		void print(){

			cout<<data;
		}
};

template <typename T>
class Single{

	private :
		Node<T> *head;
	public:
		Single(){
			this->head=NULL;
		}
		int insertE(T data){
			
			Node<T> *newNode = new Node<T>(data);

			if(head==NULL){
				head=newNode;
			}else{
				Node<T> *tempNode=head;

				while(tempNode->getNext()!=NULL){
				
				tempNode=tempNode->getNext();
				}
				tempNode->setNext(newNode);


			}
		
		}
		void midal(){
		int  count=1;
		if(head==NULL){
		
		cout<<"LL is Empty"<<endl;
		}else{
		
		Node<T> *tempNode = head;
		while(tempNode->getNext()!=NULL){
		count++;
		tempNode=tempNode->getNext();
		}
		}
		Node<T> *midNode=head;
       	       int c1=count/2;
		while(c1){
		
		midNode=midNode->getNext();
		c1--;
		}
		T data=midNode->getData();
		cout<<data;
		}
void withoutCountMiddle(){

Node<T> *faster_ptr = head;
Node<T> *slower_ptr = head;

if(head!=NULL){

while(faster_ptr != NULL && faster_ptr->getNext()!= NULL){

faster_ptr=faster_ptr->getNext()->getNext();
slower_ptr=slower_ptr->getNext();
}
T data=slower_ptr->getData();
cout<<data;
}

}

		void print(){
			Node<T> *tempNode=head;
			while(tempNode!=NULL){

				tempNode->print();
				if(tempNode->getNext()!=NULL)
					cout<<"->";

				tempNode=tempNode->getNext();
			}

		}


};

int main(){

	Single<string> s;
	s.insertE("Hello");
	s.insertE("Hi");
	s.insertE("by");
	s.insertE("Hello");
	s.insertE("Hello");
	s.insertE("Hello");
	s.insertE("Hi");
	s.insertE("by");
	s.insertE("Hi");
	s.insertE("by");
	s.insertE("Hi");
	s.insertE("by");
//	s.print();
	s.midal();
	s.withoutCountMiddle();
}

