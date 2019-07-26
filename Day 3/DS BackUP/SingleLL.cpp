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
			this->next=NULL;
		}

		void setData(T data){
			this->data=data;
		}

		void setNext(Node* next){
			this->next=next;
		}

		T getData(){
			return this->data;
		}

		Node* getNext(){

			return this->next;
		}

		void print(){
			cout<<data<<"->";
		}
};
template <typename T>

class SingleLL{
	private:
		Node<T> *head;

	public:

		SingleLL(){
			head=NULL;
		}
		void insertE(T data){

			Node<T> *newNode = new Node<T>(data);
			if(head==NULL){
				head=newNode;
			}else{

				Node<T> *tempNode;

				tempNode=head;
				while(tempNode->getNext()!=NULL){
					tempNode=tempNode->getNext(); //this line update tempNode				
				}
				tempNode->setNext(newNode);
			}


		}

		void insertB(T data){

			Node<T> *newNode = new Node<T>(data);

			if(head==NULL){

				head= newNode;
			}else{

				Node<T> *tempNode=head;

				newNode->setNext(tempNode);
				head=newNode;
			}

		}
		void insertBf(T search,T data){

			Node<T> *newNode = new Node<T>(data);
			Node<T> *tempNode;
			if(head==NULL){
				cout<<"List is Empty"<<endl;
			}else{

				if(head->getData()==search){
					insertB(data);

				}else{
					Node<T> *prevNode; 
					tempNode=head;
					while(tempNode->getData()!=search){
						prevNode=tempNode;
						tempNode=tempNode->getNext();
					}
					newNode->setNext(tempNode);
					prevNode->setNext(newNode);
				}
			}
		}


		void printData(){

			Node<T> *temp = head;
			while(temp!=NULL){
				temp->print();
				temp=temp->getNext();

			}
			cout<<"NULL"<<endl;
		}
};
int main(){

	SingleLL <int>sl;
	int data;
	while(1){
		cin>>data;
		if(data==-1){

			break;
		}else{

			sl.insertE(data);
		}
	}
	sl.insertBf(30,70);
	sl.printData();
}
