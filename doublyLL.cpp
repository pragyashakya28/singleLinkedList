#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
    T value;
    Node* prev;
    Node* next;

    Node(T value) {
        this->value = value;
        prev = NULL;
        next = NULL;
    }
};

template<typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

   
    void addNode(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    
    void removeNode(T value) {
        Node<T>* current = head;

        while (current != NULL) {
            if (current->value == value) {
                if (current == head) {
                    head = current->next;
                } else if (current == tail) {
                    tail = current->prev;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }

                delete current;
                return; 
	    }

            current = current->next;
        }

        cout << "Element not found! " << endl;
    }

    
    void display() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->value << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList<float> list;
    int choice;
    float value;

    while (true) {
        cout << "\nDoubly Linked List Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Print\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                list.addNode(value);
                break;
            case 2:
                cout << "Enter the value to delete: ";
                cin >> value;
                list.removeNode(value);
                break;
            case 3:
                cout << "Doubly Linked List: ";
                list.display();
                break;
            case 4:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}

