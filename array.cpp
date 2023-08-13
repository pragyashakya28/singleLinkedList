#include<iostream>

template <typename T>
class Array {
private:
    T* arr;
    int capacity;
    int size;
    int frontIndex;

public:
    Array(int cap) : capacity(cap), size(0), frontIndex(0) {
        arr = new T[capacity];
    }

    ~Array() {
        delete[] arr;
    }

    void push(T data) {
        if (size < capacity) {
            arr[size++] = data;
        } else {
            std::cout << "Array is full." << std::endl;
        }
    }

    void pop(T data) {
        int index = -1;
        for (int i = 0; i < size; ++i) {
            if (arr[i] == data) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            std::cout << "Element not found." << std::endl;
            return;
        }

        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --size;
    }

    T peek() {
        if (size > 0) {
            return arr[size - 1];
        } else {
            std::cout << "Array is empty." << std::endl;
            return T(); // Return a default value for the data type
        }
    }

	
     
    void enqueue(T data) {
        if (size < capacity) {
            arr[(frontIndex + size) % capacity] = data;
            ++size;
        } else {
            std::cout << "Array is full." << std::endl;
        }
    }

    void dequeue() {
        if (size > 0) {
            frontIndex = (frontIndex + 1) % capacity;
            --size;
        } else {
            std::cout << "Array is empty." << std::endl;
        }
    }

    T front() 
    {
        if (size > 0) {
            return arr[frontIndex];
        } else {
            std::cerr << "Array is empty." << std::endl;
            return T(); // Return a default value for the data type
        }
    }
     	
	
    bool isEmpty() {
        return (size == 0);
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[(frontIndex + i) % capacity] << " ";
        }
        std::cout << std::endl;
    }
};






//int main() {
  //  const size_t arraySize = 10;
    //Array<int, arraySize> arr;

   // int choice, value;
    //size_t position;

   // while (true) {
     //   cout << "\nArray Operations:\n";
     //   cout << "1. Insert\n";
     //   cout << "2. Delete\n";
     //   cout << "3. Search\n";
     //   cout << "4. Print\n";
     //   cout << "5. Exit\n";
     //   cout << "Enter your choice: ";
     //   cin >> choice;

      //  switch (choice) {
        //    case 1:
        //        cout << "Enter the value to insert: ";
        //        cin >> value;
        //        cout << "Enter the position to insert: ";
        //        cin >> position;
        //        arr.addElement(value, position);
        //        break;
        //    case 2:
        //        cout << "Enter the position to delete: ";
        //        cin >> position;
        //        arr.removeElement(position);
        //        break;
        //    case 3:
        //        cout << "Enter the value to search: ";
        //        cin >> value;
        //        position = arr.search(value);
        //        if (position != -1) {
        //            cout << "Element found at position " << position << "." << endl;
        //        } else {
        //            cout << "Element not found in the array." << endl;
        //        }
        //        break;
        //    case 4:
        //        arr.display();
        //        break;
        //    case 5:
        //        cout << "Exiting the program.\n";
        //        return 0;
        //    default:
        //        cout << "Invalid choice. Please try again.\n";
        //        break;
       // }
   // }

  //  return 0;
//}

