#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
    T value;
    Node* next;

    Node(T value) {
        this->value = value;
        next = nullptr;
    }
};

template<typename T>
class CircularLinkedList {
private:
    Node<T>* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    
    void addNode(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node<T>* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
    }

    
    void removeNode(T value) {
        if (head == nullptr) {
            cout << "Circular linked list is empty." << endl;
            return;
        }

        Node<T>* current = head;
        Node<T>* prev = nullptr;

        do {
            if (current->value == value) {
                if (current == head) {
                    head = head->next;
                    delete current;
                    return; 
                } else {
                    prev->next = current->next;
                    delete current;
                    return; 
                }
            }

            prev = current;
            current = current->next;
        } while (current != head);

        cout << "Element not found! "  << endl;
    }

    
    void display() {
        if (head == nullptr) {
            cout << "Circular linked list is empty." << endl;
            return;
        }

        Node<T>* current = head;
        do {
            cout << current->value  << " -> ";
            current = current->next;
        } while (current != head);

        cout << " (Back to head)" << endl;
    }
};

int main() {
    CircularLinkedList<int> list;

    int choice, value;

    while (true) {
        cout << "\nCircular Linked List Operations:\n";
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
                cout << "Circular Linked List: ";
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

