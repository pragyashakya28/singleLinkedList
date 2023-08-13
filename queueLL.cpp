#include<iostream>
#include "singleLL.cpp"

template <typename T>
class Queue {
private:
    LinkedList<T> list;

public:
    void enqueue(T data) {
        list.insert(data);
    }

    void dequeue() {
        if (!isEmpty()) {
            list.removeAtFront();
        }
    }

    T front() {
        return list.front();
    }

    bool isEmpty() {
        return list.isEmpty();
    }
};



int main() {
    Queue<int> queue;

    int choice, data;

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Enqueue\n";
        std::cout << "2. Dequeue\n";
        std::cout << "3. Front\n";
        std::cout << "4. Is Empty?\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter data to enqueue: ";
                std::cin >> data;
                queue.enqueue(data);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                std::cout << "Front element: " << queue.front() << std::endl;
                break;
            case 4:
                std::cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;
                break;
            case 5:
                exit(0);
            default:
                std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}

