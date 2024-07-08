

#ifndef _Sorting_Algorithms
#define _Sorting_Algorithms

#include <algorithm>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()


// Insertion Sort
template <class T, class Compare>
void insertionSort(T data[], int n, Compare comp, int& comparisonCount) {
    comparisonCount = 0;
    for (int i = 1; i < n; i++) {
        T tmp = data[i];
        int j = i;

        // Shift elements of data[0..i-1] that are greater than tmp
        while (j > 0 && comp(tmp, data[j - 1])) {                                        // a < b for Ascending  a > b for Descending
            data[j] = data[j - 1];
            j--;
            comparisonCount++;
        }

        // Place tmp at its correct position
        data[j] = tmp;
    }
}

// Selection Sort
template<class T, class Compare>
void selectionSort(T info[], int n, Compare comp, int& comparisonCount){
    comparisonCount = 0;
    for (int i = 0; i < n - 1; i++) {
        int least = i; // Initialize the index of the minimum element

        // Find the index of the minimum element in the unsorted portion
        for (int j = i + 1; j < n; j++) {
            if (comp(info[j], info[least])) {                                        // a < b for Ascending  a > b for Descending
                least = j; // Update the index of the minimum element
                comparisonCount++;
            }
        }

        // Only swap elements if the minimum element is not already at its correct position
        if (least != i) {
            std::swap(info[i], info[least]);
        }
    }
}


// Bubble Sort
template <class T, class Compare>
void bubbleSort(T data[], int n, Compare comp,int& comparisonCount) {
    comparisonCount = 0;
    bool swapped; // Flag to indicate whether swapping has occurred in a pass

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = n - 1; j > i; --j) {
            if (comp(data[j], data[j - 1])) {                                         // a < b for Ascending  a > b for Descending
                std::swap(data[j], data[j - 1]);
                swapped = true;
                comparisonCount++;
            }
        }

        // If no swapping occurred, the array is already sorted
        if (!swapped)
            break;
    }
}


// Shell Sort
template <typename T, class Compare>
void shellSort(T arr[], int n, Compare comp, int& comparisonCount) {
    comparisonCount = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            // save arr[i] in temp and make a hole at position i
            T temp = arr[i];

            int j;
            for (j = i; j >= gap && comp(arr[j - gap], temp); j -= gap) {                                  // a > b for Ascending  a < b for Descending
                arr[j] = arr[j - gap];
                comparisonCount++;
            }

            // put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
}


// Merge Function
template<typename T, class Compare>
void merge(T arr[], int l, int m, int r, Compare comp, int& comparisonCount) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    T *L = new T[n1];
    T *R = new T[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (comp(L[i], R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        comparisonCount++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

// Merge sort
template<typename T, class Compare>
void mergeSort(T arr[], int l, int r, Compare comp,int& comparisonCount) {                                             // a < b for Ascending  a > b for Descending
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, comp,comparisonCount);
        mergeSort(arr, m + 1, r, comp,comparisonCount);
        merge(arr, l, m, r, comp,comparisonCount);
    }
}

// Function to generate a random number between low and high
int getRandom(int low, int high) {
    return low + rand() % (high - low + 1);
}

// Partition Function
template<typename T, class Compare>
int partition(T arr[], int low, int high, Compare comp,int& comparisonCount) {
    // Select a random pivot index
    int pivotIndex = getRandom(low, high);
    T pivot = arr[pivotIndex];
    std::swap(arr[pivotIndex], arr[low]); // Move the pivot element to the beginning

    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= j && comp(arr[i], pivot)) {
            i++;
            comparisonCount++; // Increment comparison count
        }
        while (i <= j && comp(pivot, arr[j])) {
            j--;
            comparisonCount++; // Increment comparison count
        }
        if (i > j) {
            break;
        }
        std::swap(arr[i], arr[j]);
    }
    std::swap(arr[low], arr[j]); // Move pivot element to its correct position
    return j; // Return the pivot index
}

// Quick Sort
template<typename T, class Compare>
void quickSort(T arr[], int low, int high, Compare comp,int& comparisonCount) {                                         // a < b for Ascending  a > b for Descending
    if (low < high) {
        int pivotIndex = partition(arr, low, high, comp,comparisonCount);
        quickSort(arr, low, pivotIndex - 1, comp,comparisonCount);
        quickSort(arr, pivotIndex + 1, high, comp,comparisonCount);
    }
}


// Count Sort
void countSort(Student arr[], int n, bool descending = false) {

    // Find the range of input elements
    double maxGpa = arr[0].getGpa();
    double minGpa = arr[0].getGpa();
    for (int i = 1; i < n; ++i) {
        if (arr[i].getGpa() > maxGpa) {
            maxGpa = arr[i].getGpa();
        }
        if (arr[i].getGpa() < minGpa) {
            minGpa = arr[i].getGpa();
        }
    }
    int range = static_cast<int>(maxGpa - minGpa) + 1;

    // Create a count array to store the count of each GPA
    std::vector<int> count(range, 0);

    // Store count of each GPA
    for (int i = 0; i < n; ++i) {
        count[static_cast<int>(arr[i].getGpa() - minGpa)]++;
    }

    // Modify count array such that each element stores the sum of previous counts
    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    // Build the output array
    std::vector<Student> output(n);
    for (int i = n - 1; i >= 0; --i) {
        output[count[static_cast<int>(arr[i].getGpa() - minGpa)] - 1] = arr[i];
        count[static_cast<int>(arr[i].getGpa() - minGpa)]--;
    }

    // Copy the output array to arr, so that arr now contains sorted elements
    if (descending){
        for (int i = 0; i < n; ++i) {
            arr[i] = output[n - i - 1];
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            arr[i] = output[i];
        }
    }

}








#endif // _Sorting_Algorithms



















