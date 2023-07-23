#include<iostream>
using namespace std;

template<typename T>
class Node
{
	public:
		T data;
		Node<T>* next;

		Node(){
		     data=0;
	             next=NULL;
	        }
   		Node(T val){
	             data = val;
                     next = NULL;
		}

};

template<typename T>
class LinkedList
{
	Node<T>* head;
	public:
	LinkedList(){
		head = NULL;
	}

	void insertNode(T val){
		Node<T>* newnode = new Node<T>(val);
		if(head == NULL){
			head = newnode;
			return;
		}

		Node<T>* temp = head;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newnode;
	}

	bool deleteNode(int index)
	{
		
		if(head == NULL){
			cout<<"list is empty";
			return false;
	        }

		if(index == 0){
			Node<T>* temp= head;
			head = head->next;
			delete temp;
			return true;
		}
		Node<T>* prev = NULL;
		Node<T>* curr = head;
		int currpos=0;
		
		while(curr!= NULL && currpos < index){
			prev = curr;
			curr=curr->next;
			currpos++;
		}

		if(curr == NULL){
			return false;
		}

		prev->next = curr->next;
		delete curr;
		return true;
	}	
	

	void printNode(){
		Node<T>* temp = head;
		if(head == NULL){
			cout<<"list is empty";
		}
		while(temp!=NULL){
			cout<<temp->data<<"-> ";
			temp = temp->next;
		}
		if(temp == NULL && head!=NULL){ cout<<"NULL"; }
	}


};

int main()
{
	LinkedList<float>  link;
 	int choice, pos;
	float value;

        do{
		cout<<"1. Insert element\n"
			<<"2. Delete element\n"
			<<"3. Display list\n"
			<<"4. Exit\n"
			<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1: 
				cout<<"Enter value to be inserted: ";
				cin>>value;
				link.insertNode(value);
				break;
			case 2:
				cout<<"Enter position of node to be deleted: ";
				cin>>pos;
				if(link.deleteNode(pos)){
					cout<<"node at position "<<pos<<" deleted successfully\n";
				}
				else{
					cout<<"position "<<pos<<" is out of range\n";
				}
				

				break;
			case 3:
				cout<<"Single Linked List: ";
				link.printNode();
				cout<<endl;
				break;
			case 4:
				cout<<"Exiting program \n";
				break;
			default: 
				cout<<"Invalid choice. Try again. \n";
		}
	}while(choice!=4);	

	return 0;
}


