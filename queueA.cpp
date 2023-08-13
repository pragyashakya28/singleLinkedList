#include<iostream>
#include "array.cpp"
 
template <typename T>
class Queue {
private:
    Array<T> array;

public:
    Queue(int capacity) : array(capacity) {}

    void enqueue(T data) {
        array.enqueue(data);
    }

    void dequeue() {
        if (!isEmpty()) {
            array.dequeue();
        }
    }

    T front() {
        return array.front();
    }

    bool isEmpty() {
        return array.isEmpty();
    }
};



int main() {
    int capacity;
    std::cout << "Enter the capacity of the queue: ";
    std::cin >> capacity;

    Queue<int> queue(capacity);

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

