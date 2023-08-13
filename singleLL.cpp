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

	void insert(T val){
		Node<T>* newnode = new Node<T>(val);
		newnode->next = head;
		head = newnode;
	}

	void insertAtPosition(T val, int position ){
		Node<T>* newnode = new Node<T>(val);

		
		if(head == NULL || position == 0){
		  newnode->next = head;
		  head = newnode;
		  return;
		}

		Node<T>* current = head;
		Node<T>* prev = NULL;
		int cnt =0;

	        //Traverse the list to the given position
		while(current!=NULL && cnt < position){
			prev=current;
			current=current->next;
                        cnt++;
		}
		prev->next = newnode;
		newnode->next=current;

	}
	
	//For Stack
	void removeAtTop() {
	
		cout<<"Deleted value: "<<head->data<<endl;
        	if (isEmpty()) {
            		cout << "List is empty.";
            		return;
        	}

        	Node<T>* temp = head;
        	head = head->next;
        	delete temp;
    	}
	
	
	T peek(){
		if(head == NULL){
			cout<<"list is empty"<<endl;
			return T();
		}
		 return head->data;
	}
	
	//For Queue
	void removeAtFront() {
        	if (head == nullptr) {
            		std::cout << "List is empty." << std::endl;
            		return;
        	}

       	 	Node<T>* current = head;
        	Node<T>* prev = nullptr;

        	while (current->next != nullptr) {
            		prev = current;
            		current = current->next;
        	}

        	if (prev != nullptr) {
            		prev->next = nullptr;
        	} else {
            	head = nullptr;
        	}

        	delete current;
    	}
	

	T front() {
        	if (head == nullptr) {
        	    std::cout << "List is empty." << std::endl;
        	    return T(); // Return a default value for the data type
        	}

        	Node<T>* current = head;
        	while (current->next != nullptr) {
        	    current = current->next;
        	}

        	return current->data;
    	}

	
	bool isEmpty(){
		return(head==NULL);
	}

	void display() {
        	Node<T>* current = head;
        	while (current != nullptr) {
            	std::cout << current->data << " -> ";
            	current = current->next;
        	}
        	std::cout << "nullptr" << std::endl;
    	}

    	~LinkedList() {
        	Node<T>* current = head;
        	while (current != nullptr) {
        	    Node<T>* temp = current;
        	    current = current->next;
        	    delete temp;
        	}
    	}

};

//int main()
//{
//	LinkedList<int>  link;
// 	int choice, pos, insertpos;
//	int value;
//
//        do{
//		cout<<"1. Insert element\n"
//			<<"2. Delete element\n"
//			<<"3. Display list\n"
//			<<"4. Exit\n"
//			<<"Enter your choice: ";
//		cin>>choice;
//		switch(choice){
//			case 1: 
//				cout<<"Enter value to be inserted: ";
//				cin>>value;
//				cout<<"Enter position of node: ";
//				cin>>insertpos;
//				link.insertAtPosition(value,insertpos);
//				break;
//			case 2:
//				cout<<"Enter position of node to be deleted: ";
//				cin>>pos;
//				if(link.deleteNode(pos)){
//					cout<<"node at position "<<pos<<" deleted successfully\n";
//				}
//				else{
//					cout<<"position "<<pos<<" is out of range\n";
//				}
//				
//
//				break;
//			case 3:
//				cout<<"Single Linked List: ";
//				link.printNode();
//				cout<<endl;
//				break;
//			case 4:
//				cout<<"Exiting program \n";
//				break;
//			default: 
//				cout<<"Invalid choice. Try again. \n";
//		}
//	}while(choice!=4);	

//	return 0;

//}


