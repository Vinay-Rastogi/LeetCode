#include <iostream>
using namespace std;

class MyCircularDeque {
public:     
    int *arr;
    int f;  // front
    int r;  // rear
    int size;

    MyCircularDeque(int k) {
        size = k;
        arr = new int[size];
        f = -1;
        r = -1;
    }

    bool insertFront(int value) {
        if (isFull()) return false;

        if (isEmpty()) {
            f = 0;
            r = 0;
            arr[f] = value;
        } else {
            f = (f - 1 + size) % size;
            arr[f] = value;
        }
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;

        if (isEmpty()) {
            f = 0;
            r = 0;
            arr[r] = value;
        } else {
            r = (r + 1) % size;
            arr[r] = value;
        }
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;

        if (f == r) { // only one element
            f = -1;
            r = -1;
        } else {
            f = (f + 1) % size;
        }
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        if (f == r) { // only one element
            f = -1;
            r = -1;
        } else {
            r = (r - 1 + size) % size;
        }
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[f];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[r];
    }

    bool isEmpty() {
        return f == -1;
    }

    bool isFull() {
        return (r + 1) % size == f;
    }
};

int main() {
    // Create a circular deque of size 5
    MyCircularDeque* obj = new MyCircularDeque(5);

    // Inserting elements at the front and rear
    cout << "Insert Front 10: " << obj->insertFront(10) << endl; // true
    cout << "Insert Last 20: " << obj->insertLast(20) << endl;   // true
    cout << "Insert Front 30: " << obj->insertFront(30) << endl; // true
    cout << "Insert Last 40: " << obj->insertLast(40) << endl;   // true

    // Checking the front and rear
    cout << "Front: " << obj->getFront() << endl;  // 30
    cout << "Rear: " << obj->getRear() << endl;    // 40

    // Delete front and rear elements
    cout << "Delete Front: " << obj->deleteFront() << endl; // true
    cout << "Delete Last: " << obj->deleteLast() << endl;   // true

    // Check if deque is empty or full
    cout << "Is Empty: " << obj->isEmpty() << endl; // false
    cout << "Is Full: " << obj->isFull() << endl;   // false

    // Check front and rear after deletion
    cout << "Front after deletion: " << obj->getFront() << endl;  // 20
    cout << "Rear after deletion: " << obj->getRear() << endl;    // 10

    // Insert elements to check full condition
    cout << "Insert Last 50: " << obj->insertLast(50) << endl; // true
    cout << "Insert Last 60: " << obj->insertLast(60) << endl; // true
    cout << "Insert Front 70: " << obj->insertFront(70) << endl; // true
    cout << "Is Full after insertions: " << obj->isFull() << endl; // true

    return 0;
}
