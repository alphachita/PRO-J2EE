#include<iostream>

using namespace std;

class Node{

	private: 
		int data;
		Node* next;
		Node* prev;

	public:

		Node(){}

		Node(int data){
			this->data=data;
			this->next=NULL;
			this->prev=NULL;
		}


		void setData(int data){
			this->data=data;
		}

		void setNext(Node* next){
			this->next=next;
		}
		void setPrev(Node* prev){
			this->prev=prev;
		}

		int getData(){
			return this->data;
		}

		Node* getNext(){

			return this->next;
		}
		Node* getPrev(){
			return this->prev;

		}
		void print(){
			cout<<data<<"<=>";
		}
};

class DoubleLL{
	private:
		Node* head;

	public:

		DoubleLL(){
			head=NULL;
		}
		void insertE(int data){

			Node* newNode = new Node(data);
			if(head==NULL){
				head=newNode;
			}else{

				Node* tempNode;

				tempNode=head;
				while(tempNode->getNext()!=NULL){
					tempNode=tempNode->getNext(); //this line update tempNode				
				}
				tempNode->setNext(newNode);
				newNode->setPrev(tempNode);
			}


		}

		void insertB(int data){

			Node* newNode = new Node(data);

			if(head==NULL){

				head= newNode;
			}else{

				Node* tempNode=head;

				newNode->setNext(tempNode);
				head=newNode;
			}

		}

		void insertBf(int search,int data){

			Node* newNode = new Node(data);
			Node* tempNode;
			if(head==NULL){
				cout<<"List is Empty"<<endl;
			}else{

				if(head->getData()==search){
					insertB(data);

				}else{
					Node* prevNode; 
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

			Node* temp = head;
			while(temp!=NULL){
				temp->print();
				temp=temp->getNext();

			}
			cout<<"NULL"<<endl;
		}
};
int main(){

	
DoubleLL dl;
	int data;
	while(1){
		cin>>data;
		if(data==-1){

			break;
		}else{

			dl.insertE(data);
		}
	}
	dl.insertBf(30,70);
	dl.printData();
}
