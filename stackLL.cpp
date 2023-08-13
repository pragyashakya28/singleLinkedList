#include<iostream>
#include "singleLL.cpp"
using namespace std;


template <typename T>
class Stack {
private:
    LinkedList<T> list;

public:
    void push(T data) {
        list.insert(data);
    }

    void pop() {
        if (!isEmpty()) {
            list.removeAtTop();
        }
    }

    T peek() {
        return list.peek();
    }

    bool isEmpty() {
        return list.isEmpty();
    }
};

int main() {
    Stack<int> stack;

    int choice, data;

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Peek\n";
        std::cout << "4. Is Empty?\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter data to push: ";
                std::cin >> data;
                stack.push(data);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                std::cout << "Top element: " << stack.peek() << std::endl;
                break;
            case 4:
                std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;
                break;
            case 5:
                exit(0);
            default:
                std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}
