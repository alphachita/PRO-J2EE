#include<iostream>
#include "StackH.cpp"
#include "QueueH.cpp"

using namespace std;

class Node{

	private: 
		int data;
		Node* right;
		Node* left;

	public:

		Node(){}

		Node(int data){
			this->data=data;
			this->right=NULL;
			this->left=NULL;
		}


		void setData(int data){
			this->data=data;
		}

		void setRight(Node* right){
			this->right=right;
		}
		void setLeft(Node* left){
			this->left=left;
		}

		int getData(){
			return this->data;
		}

		Node* getRight(){

			return this->right;
		}
		Node* getLeft(){
			return this->left;

		}
		void print(){
			cout<<data<<"-";
		}
};

class BST{
	private:
		Node* root;

	public:

		BST(){
			root=NULL;
		}
		void insert(int data){

			Node* newNode = new Node(data);
			if(root==NULL){
				root=newNode;
			}else{

				Node* tempNode=root;
				Node* prevNode=NULL;

				while(tempNode!=NULL){
					prevNode=tempNode;
					if(data>=tempNode->getData()){
						tempNode=tempNode->getRight();	
					}else{
						tempNode=tempNode->getLeft();
					}

				}
				if(data>prevNode->getData()){
					prevNode->setRight(newNode);
				}else{
					prevNode->setLeft(newNode);
				}

			}
		}

		void traversalB(){
			Queue<Node*> store(100);

			store.enqueue(root);
			while(!store.isEmpty()){
				Node* prev;

				Node* node;
				prev=node;				
				node = store.dequeue();

				if(prev->getData()>node->getData()){
					cout<<endl;
				}
				node->print();

				if(node->getLeft()!=NULL){

					store.enqueue(node->getLeft());
				}
				if(node->getRight()!=NULL){
					store.enqueue(node->getRight());

				}
			}

		}

		void traversalD(){
			Stack<Node*> store(100);

			store.push(root);
			while(!store.isEmpty()){

				Node* node = store.pop();
				node->print();
				if(node->getRight()!=NULL){

					store.push(node->getRight());
				}
				if(node->getLeft()!=NULL){
					store.push(node->getLeft());

				}
			}

		}

		Inorder storing into array
		/* T *array = new T[3];
                int  i=0;
                void inorder(Node<T> *root){
                        if(root!=NULL){
                                inorder(root->getLeft());
                                array[i] = root->getData();
                                i++;
                                inorder(root->getRight());
                        }
                }
                void inorder(){
                        inorder(root);
                }
                void p(){
                        for(int i=0;i<3;i++){
                                cout<<array[i];
                        }
                }
		*/
		
		
		
		
		
		
		
		void inorder(Node* root){

			if(root!=NULL){

				inorder(root->getLeft());
				root->print();
				inorder(root->getRight());
			}

		}
		void inorder(){
			inorder(root);
			cout<<endl;
		}


		void preorder(Node* root){
			if(root!=NULL){
				root->print();
				preorder(root->getLeft() );
				preorder(root->getRight() );

			}

		}

		void preorder(){

			preorder(root);
			cout<<endl;
		}

		void postorder(Node* root){
			if(root!=NULL){
				postorder(root->getLeft());
				postorder(root->getRight());
				root->print();
			}
		}

		void postorder(){
			postorder(root);
			cout<<endl;
		}


};
int main(){


	BST bst;
	int data;
	while(1){
		cin>>data;
		if(data==-1){

			break;
		}else{

			bst.insert(data);
		}
	}

	cout<<"\n-----------BFS-----------------"<<endl;
	bst.traversalB();
	cout<<"\n-----------DFS-----------------"<<endl;
	bst.traversalD();

	cout<<"\n-----------Inorder-----------------"<<endl;
	bst.inorder();


	cout<<"\n-----------Preorder-----------------"<<endl;
	bst.preorder();
	cout<<"\n-----------Postorder-----------------"<<endl;
	bst.postorder();
}
