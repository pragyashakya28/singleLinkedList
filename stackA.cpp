#include<iostream>
#include "array.cpp" 
using namespace std;

template <typename T>
class Stack {
private:
    Array<T> array;

public:
    Stack(int capacity) : array(capacity) {}

    void push(T data) {
        array.insert(data);
    }

    void pop() {
        if (!isEmpty()) {
            array.remove(array.peek());
        }
    }

    T peek() {
        return array.peek();
    }

    bool isEmpty() {
        return array.isEmpty();
    }
};


int main() {
    int capacity;
    cout << "Enter the capacity of the stack: ";
    cin >> capacity;

    Stack<int> stack(capacity);

    int choice, data;

    while (true)
    {
        cout << "Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Is Empty?\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to push: ";
                cin >> data;
                stack.push(data);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout << "Top element: " << stack.peek() << std::endl;
                break;
            case 4:
                cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}

