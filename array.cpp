#include <iostream>
using namespace std;

template<typename T, size_t N>
class Array {
private:
    T arr[N];
    size_t size;

public:
    Array() {
        size = 0;
    }

    
    void addElement(T value, size_t position) {
        if (size < N && position <= size) {
            for (size_t i = size; i > position; i--) {
                arr[i] = arr[i - 1];
            }
            arr[position] = value;
            size++;
        } else {
            cout << "Invalid position or array is full. Cannot insert the element." << endl;
        }
    }

    
    void removeElement(size_t position) {
        if (position < size) {
            for (size_t i = position; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
        } else {
            cout << "Invalid position. Cannot delete the element." << endl;
        }
    }

    
    int search(T value) {
        for (size_t i = 0; i < size; i++) {
            if (arr[i] == value) {
                return static_cast<int>(i);
            }
        }
        return -1; 
    }

    
    void display() {
        if (size == 0) {
            cout << "Array is empty." << endl;
            return;
        }

        cout << "Array elements: ";
        for (size_t i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    const size_t arraySize = 10;
    Array<int, arraySize> arr;

    int choice, value;
    size_t position;

    while (true) {
        cout << "\nArray Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Print\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                cout << "Enter the position to insert: ";
                cin >> position;
                arr.addElement(value, position);
                break;
            case 2:
                cout << "Enter the position to delete: ";
                cin >> position;
                arr.removeElement(position);
                break;
            case 3:
                cout << "Enter the value to search: ";
                cin >> value;
                position = arr.search(value);
                if (position != -1) {
                    cout << "Element found at position " << position << "." << endl;
                } else {
                    cout << "Element not found in the array." << endl;
                }
                break;
            case 4:
                arr.display();
                break;
            case 5:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}

