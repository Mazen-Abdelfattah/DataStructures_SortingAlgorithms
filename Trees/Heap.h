//
// Created by youssef on 5/17/2024.
//

#ifndef _HEAP_H
#define _HEAP_H

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>


// MinHeap class template
template <typename T, typename Compare = std::less<T>>
class MinHeap {
public:
    // Default constructor
    MinHeap() = default;

    // Constructor that takes a vector
    explicit MinHeap(const std::vector<T>& elements);

    // Copy constructor
    MinHeap(const MinHeap& other);

    // Copy assignment operator
    MinHeap& operator=(const MinHeap& other);

    // Destructor
    ~MinHeap() = default;

    // Member functions
    void heapify(int low, int high);
    void buildHeap();
    void heapSort();
    void insert(const T& element);
    void remove(const T& element);
    void print_BFS() const;

private:
    std::vector<T> elements; /// <<<<<< Vector to store heap elements
    Compare comp;            /// <<<<<<<< Comparator to maintain heap property

};

template <typename T, typename Compare>
MinHeap<T, Compare>::MinHeap(const std::vector<T>& elements) : elements(elements) {
    buildHeap();
}


template <typename T, typename Compare>
MinHeap<T, Compare>::MinHeap(const MinHeap& other) : elements(other.elements), comp(other.comp) {}


template <typename T, typename Compare>
MinHeap<T, Compare>& MinHeap<T, Compare>::operator=(const MinHeap& other) {
    if (this != &other) {
        elements = other.elements;
        comp = other.comp;
    }
    return *this;
}


template <typename T, typename Compare>
void MinHeap<T, Compare>::heapify(int low, int high) {
    int smallIndex;
    T temp = elements[low];
    smallIndex = 2 * low + 1;

    while (smallIndex <= high) {

        if (smallIndex < high && comp(elements[smallIndex + 1], elements[smallIndex])) {
            smallIndex = smallIndex + 1; // index of the smallest child
        }


        if (comp(temp, elements[smallIndex])) {
            break;
        } else {

            elements[low] = elements[smallIndex];


            low = smallIndex;
            smallIndex = 2 * low + 1;
        }
    }

    elements[low] = temp;
}


template <typename T, typename Compare>
void MinHeap<T, Compare>::buildHeap() {

    for (int index = elements.size() / 2 - 1; index >= 0; index--) {
        heapify(index, elements.size() - 1);
    }
}


template <typename T, typename Compare>
void MinHeap<T, Compare>::insert(const T& element) {
    // Add the new element to the end of the vector
    elements.push_back(element);

    // Get the index of the newly inserted element
    int index = elements.size() - 1;

    // Move the element upwards to restore the heap property
    while (index > 0 && comp(elements[index], elements[(index - 1) / 2])) {
        std::swap(elements[index], elements[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

template <typename T, typename Compare>
void MinHeap<T, Compare>::remove(const T& element) {
    // Find the position of the element in the heap
    auto it = std::find(elements.begin(), elements.end(), element);
    if (it == elements.end()) {
        // Element not found in the heap
        return;
    }

    // Get the index of the element to be removed
    int index = std::distance(elements.begin(), it);

    // Move the last element to the position of the removed element
    elements[index] = elements.back();
    elements.pop_back();

    // Restore the heap property
    heapify(index, elements.size() - 1);
}

template <typename T, typename Compare>
void MinHeap<T, Compare>::print_BFS() const {
    if (elements.empty()) {
        std::cout << "Heap is empty." << std::endl;
        return;
    }

    std::queue<int> level_queue;
    level_queue.push(0); // Start with the root index

    while (!level_queue.empty()) {
        int level_size = level_queue.size();
        for (int i = 0; i < level_size; ++i) {
            int index = level_queue.front();
            level_queue.pop();
            std::cout << elements[index] << " "; // Print the element at the current index
            int left_child = 2 * index + 1;
            int right_child = 2 * index + 2;
            if (left_child < elements.size()) {
                level_queue.push(left_child);
            }
            if (right_child < elements.size()) {
                level_queue.push(right_child);
            }
        }

    }
}


/// >>>>>>>>> heap sort on MINHEAP makes it DESCENDING
template <typename T, typename Compare>
void MinHeap<T, Compare>::heapSort() {
    buildHeap();

    for (int i = elements.size() - 1; i > 0; --i) {
        std::swap(elements[0], elements[i]);
        heapify(0, i - 1);
    }
}





/// .................................................................................................................




// MaxHeap class template
template <typename T, typename Compare = std::less<T>>
class MaxHeap {
public:
    // Default constructor
    MaxHeap() = default;

    // Constructor that takes a vector
    explicit MaxHeap(const std::vector<T>& elements);

    // Copy constructor
    MaxHeap(const MaxHeap& other);

    // Copy assignment operator
    MaxHeap& operator=(const MaxHeap& other);

    // Destructor
    ~MaxHeap() = default;

    // Member functions
    void heapify(int low, int high);
    void buildHeap();
    void heapSort();
    void insert(const T& element);
    void remove(const T& element);
    void print_BFS() const;

private:
    std::vector<T> elements; // Vector to store heap elements
    Compare comp;            // Comparator to maintain heap property
};

// Constructor that takes a vector
template <typename T, typename Compare>
MaxHeap<T, Compare>::MaxHeap(const std::vector<T>& elements) : elements(elements) {
    buildHeap();
}

// Copy constructor
template <typename T, typename Compare>
MaxHeap<T, Compare>::MaxHeap(const MaxHeap& other) : elements(other.elements), comp(other.comp) {}

// Copy assignment operator
template <typename T, typename Compare>
MaxHeap<T, Compare>& MaxHeap<T, Compare>::operator=(const MaxHeap& other) {
    if (this != &other) {
        elements = other.elements;
        comp = other.comp;
    }
    return *this;
}

// Member function to heapify a subtree rooted at index low
template <typename T, typename Compare>
void MaxHeap<T, Compare>::heapify(int low, int high) {
    int largeIndex;
    T temp = elements[low];
    largeIndex = 2 * low + 1;

    while (largeIndex <= high) {
        if (largeIndex < high && comp(elements[largeIndex], elements[largeIndex + 1])) {
            largeIndex = largeIndex + 1; // index of the larger child
        }

        if (!comp(temp, elements[largeIndex])) {
            break;
        } else {
            elements[low] = elements[largeIndex];
            low = largeIndex;
            largeIndex = 2 * low + 1;
        }
    }

    elements[low] = temp;
}

// Member function to build the heap
template <typename T, typename Compare>
void MaxHeap<T, Compare>::buildHeap() {
    for (int index = elements.size() / 2 - 1; index >= 0; index--) {
        heapify(index, elements.size() - 1);
    }
}

// Member function to insert an element into the heap
template <typename T, typename Compare>
void MaxHeap<T, Compare>::insert(const T& element) {
    elements.push_back(element);
    int index = elements.size() - 1;

    while (index > 0 && comp(elements[(index - 1) / 2], elements[index])) {
        std::swap(elements[index], elements[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Member function to remove an element from the heap
template <typename T, typename Compare>
void MaxHeap<T, Compare>::remove(const T& element) {
    auto it = std::find(elements.begin(), elements.end(), element);
    if (it == elements.end()) {
        return;
    }

    int index = std::distance(elements.begin(), it);
    elements[index] = elements.back();
    elements.pop_back();

    if (index < elements.size()) {
        heapify(index, elements.size() - 1);
        if (index > 0) {
            int parent = (index - 1) / 2;
            if (comp(elements[parent], elements[index])) {
                while (index > 0 && comp(elements[(index - 1) / 2], elements[index])) {
                    std::swap(elements[index], elements[(index - 1) / 2]);
                    index = (index - 1) / 2;
                }
            }
        }
    }
}

// Member function to print the elements of the heap using BFS traversal
template <typename T, typename Compare>
void MaxHeap<T, Compare>::print_BFS() const {
    if (elements.empty()) {
        std::cout << "Heap is empty." << std::endl;
        return;
    }

    std::queue<int> level_queue;
    level_queue.push(0); // Start with the root index

    while (!level_queue.empty()) {
        int level_size = level_queue.size();
        for (int i = 0; i < level_size; ++i) {
            int index = level_queue.front();
            level_queue.pop();
            std::cout << elements[index] << " ";
            int left_child = 2 * index + 1;
            int right_child = 2 * index + 2;
            if (left_child < elements.size()) {
                level_queue.push(left_child);
            }
            if (right_child < elements.size()) {
                level_queue.push(right_child);
            }
        }

    }
}

/// >>>>>>>>> heap sort on MAXHEAP makes it ASCENDING
template <typename T, typename Compare>
void MaxHeap<T, Compare>::heapSort() {
    buildHeap(); // Ensure the heap is built

    for (int i = elements.size() - 1; i > 0; --i) {
        std::swap(elements[0], elements[i]); // Move the root of the heap to the end
        heapify(0, i - 1); // Restore the heap property for the reduced heap
    }
}

























#endif //_HEAP_H
