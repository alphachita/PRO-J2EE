#include<iostream>

using namespace std;

class Sorting{
	public:

		int* Bubble(int size,int* array){

			for(int i=0;i<size;i++){

				for(int j=0;j<size;j++){

					if(array[i]<array[j]){
						int temp=array[i];
						array[i]=array[j];
						array[j]=temp;

					}

				}

			}
			return array;


		}

		int* Selection(int size, int* array){

			for(int i=0;i<size;i++){
				int max=0;
				for(int j=0;j<size-i;j++){
					if(array[max]<array[j]){
						max=j;

					}
				}
				int temp=array[max];
				array[max]=array[(size-1)-i];
				array[(size-1)-i]=temp;
			}
			return array;
		}


		int* Insertion(int size,int* array){

			for(int i=1;i<size;i++){
				int key = array[i];
				int j=i-1;
				while(j>=0 && key<array[j]){
					array[j+1]=array[j];
					j--;
				}
				array[j+1]=key;
			}
return array;
		}

};

int main(){

	Sorting s;
	int size;
	cout<<"Enter the size"<<endl;
	cin>>size;
	int* array = new int[size];
	cout<<"Enter the data"<<endl;

	for(int i=0;i<size;i++){
		cin>>array[i];
	}

	int* bubbleSort=s.Insertion(size,array);

	for(int i=0;i<size;i++){
		cout<<bubbleSort[i];
	}
}
