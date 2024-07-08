#ifndef _SORT_STUDENTS_H
#define _SORT_STUDENTS_H


#include "Student.h"
#include "Sorting_Algorithms.h"


class applySorting {
private:
    int n;
    Student *students;

public:

    // Constructor to read input from file
    applySorting(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Error: Unable to open file." << std::endl;
            return;
        }

        file >> n;
        file.ignore(); // Ignore the newline character

        students = new Student[n];

        for (int i = 0; i < n; ++i) {
            std::string id, name;
            double gpa;

            std::getline(file, name);
            std::getline(file, id);

            file >> gpa;
            file.ignore(); // Ignore the newline character

            students[i] = Student(id, name, gpa);
        }
    }

    // Destructor to free memory
    ~applySorting() {
        delete[] students;
    }

    void sortByname() {
        int comparisonCount = 0;

        // Make a copy of the original array
        Student* originalStudents = new Student[n];
        std::copy(students, students + n, originalStudents);
        std::ofstream Sorted("SortedByName.txt");


        // Apply insertion sort
        Sorted << "Algorithm: Insertion Sort" << '\n';
        auto start1 = std::chrono::steady_clock::now();
        insertionSort(originalStudents, n,[](Student s1,Student s2){return s1.getName() < s2.getName();},comparisonCount);
        auto end1 = std::chrono::steady_clock::now();
        Sorted << "Comparison Count :" << comparisonCount << '\n';
        Sorted << "Running Time:" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << '\n';
        for (int i = 0; i < n; ++i) {
            Sorted << "ID: " << originalStudents[i].getId() << ", Name: " << originalStudents[i].getName() << ", GPA: " << originalStudents[i].getGpa() << '\n';
        }
        Sorted << '\n';
        comparisonCount = 0;


        // Apply selection sort
        std::copy(students, students + n, originalStudents);

        Sorted << "Algorithm: Selection Sort" << '\n';
        auto start2 = std::chrono::steady_clock::now();
        selectionSort(originalStudents, n,[](Student s1,Student s2){return s1.getName() < s2.getName();},comparisonCount);
        auto end2 = std::chrono::steady_clock::now();
        Sorted << "Comparison Count :" << comparisonCount << '\n';
        Sorted << "Running Time:" << std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() << " microseconds" << '\n';
        for (int i = 0; i < n; ++i) {
            Sorted << "ID: " << originalStudents[i].getId() << ", Name: " << originalStudents[i].getName() << ", GPA: " << originalStudents[i].getGpa() << '\n';
        }
        Sorted << '\n';
        comparisonCount = 0;


    // Apply bubble sort
        std::copy(students, students + n, originalStudents);
        Sorted << "Algorithm: Bubble sort" << '\n';

        auto start3 = std::chrono::steady_clock::now();
        bubbleSort(originalStudents, n,[](Student s1,Student s2){return s1.getName() < s2.getName();},comparisonCount);
        auto end3 = std::chrono::steady_clock::now();
        Sorted << "Comparison Count :" << comparisonCount << '\n';
        Sorted << "Running Time:" << std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3).count() << " microseconds" << '\n';

        for (int i = 0; i < n; ++i) {
            Sorted << "ID: " << originalStudents[i].getId() << ", Name: " << originalStudents[i].getName() << ", GPA: " << originalStudents[i].getGpa() << '\n';
        }
        Sorted << '\n';
        comparisonCount = 0;



    // Apply Shell Sort
        std::copy(students, students + n, originalStudents);
        Sorted << "Algorithm: Shell Sort" << '\n';
        auto start4 = std::chrono::steady_clock::now();
        shellSort(originalStudents, n,[](Student s1,Student s2){return s1.getName() > s2.getName();},comparisonCount);
        auto end4 = std::chrono::steady_clock::now();
        Sorted << "Comparison Count :" << comparisonCount << '\n';
        Sorted << "Running Time:" << std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4).count() << " microseconds" << '\n';

        for (int i = 0; i < n; ++i) {
            Sorted << "ID: " << originalStudents[i].getId() << ", Name: " << originalStudents[i].getName() << ", GPA: " << originalStudents[i].getGpa() << '\n';
        }
        Sorted << '\n';
        comparisonCount = 0;



    // Apply merge sort
        std::copy(students, students + n, originalStudents);
        Sorted << "Algorithm: Merge Sort" << '\n';
        auto start5 = std::chrono::steady_clock::now();
        mergeSort(originalStudents, 0, n - 1,[](Student s1,Student s2){return s1.getName() <= s2.getName();},comparisonCount);
        auto end5 = std::chrono::steady_clock::now();
        Sorted << "Comparison Count :" << comparisonCount << '\n';
        Sorted << "Running Time:" << std::chrono::duration_cast<std::chrono::microseconds>(end5 - start5).count() << " microseconds" << '\n';

        for (int i = 0; i < n; ++i) {
            Sorted << "ID: " << originalStudents[i].getId() << ", Name: " << originalStudents[i].getName() << ", GPA: " << originalStudents[i].getGpa() << '\n';
        }
        Sorted << '\n';
        comparisonCount = 0;


    // Apply quick sort
        std::copy(students, students + n, originalStudents);
        Sorted << "Algorithm: Quick Sort" << '\n';
        auto start6 = std::chrono::steady_clock::now();
        quickSort(originalStudents, 0, n - 1,[](Student s1,Student s2){return s1.getName() <= s2.getName();},comparisonCount);
        auto end6 = std::chrono::steady_clock::now();
        Sorted << "Comparison Count :" << comparisonCount << '\n';
        Sorted << "Running Time:" << std::chrono::duration_cast<std::chrono::microseconds>(end6 - start6).count() << " microseconds" << '\n';

        for (int i = 0; i < n; ++i) {
            Sorted << "ID: " << originalStudents[i].getId() << ", Name: " << originalStudents[i].getName() << ", GPA: " << originalStudents[i].getGpa() << '\n';
        }
        comparisonCount = 0;

        Sorted.close();
        delete[] originalStudents;

    };
    void sortBygpa(){

        int comparisonCount = 0;

        // Make a copy of the original array
        Student* originalStudents = new Student[n];
        std::copy(students, students + n, originalStudents);
        std::ofstream Sorted("SortedByGPA.txt");


        // Apply insertion sort
        Sorted << "Algorithm: Insertion Sort" << '\n';
        auto start1 = std::chrono::steady_clock::now();
        insertionSort(originalStudents, n,[](Student s1,Student s2){return s1.getGpa() > s2.getGpa();},comparisonCount);
        auto end1 = std::chrono::steady_clock::now();
        Sorted << "Comparison Count :" << comparisonCount << '\n';
        Sorted << "Running Time:" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << '\n';
        for (int i = 0; i < n; ++i) {
            Sorted << "ID: " << originalStudents[i].getId() << ", Name: " << originalStudents[i].getName() << ", GPA: " << originalStudents[i].getGpa() << '\n';
        }
        Sorted << '\n';
        comparisonCount = 0;


        // Apply selection sort
        std::copy(students, students + n, originalStudents);

        Sorted << "Algorithm: Selection Sort" << '\n';
        auto start2 = std::chrono::steady_clock::now();
        selectionSort(originalStudents, n,[](Student s1,Student s2){return s1.getGpa() > s2.getGpa();},comparisonCount);
        auto end2 = std::chrono::steady_clock::now();
        Sorted << "Comparison Count :" << comparisonCount << '\n';
        Sorted << "Running Time:" << std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() << " microseconds" << '\n';
        for (int i = 0; i < n; ++i) {
            Sorted << "ID: " << originalStudents[i].getId() << ", Name: " << originalStudents[i].getName() << ", GPA: " << originalStudents[i].getGpa() << '\n';
        }
        Sorted << '\n';
        comparisonCount = 0;



        // Apply bubble sort
        std::copy(students, students + n, originalStudents);
        Sorted << "Algorithm: Bubble sort" << '\n';

        auto start3 = std::chrono::steady_clock::now();
        bubbleSort(originalStudents, n,[](Student s1,Student s2){return s1.getGpa() > s2.getGpa();},comparisonCount);
        auto end3 = std::chrono::steady_clock::now();
        Sorted << "Comparison Count :" << comparisonCount << '\n';
        Sorted << "Running Time:" << std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3).count() << " microseconds" << '\n';

        for (int i = 0; i < n; ++i) {
            Sorted << "ID: " << originalStudents[i].getId() << ", Name: " << originalStudents[i].getName() << ", GPA: " << originalStudents[i].getGpa() << '\n';
        }
        Sorted << '\n';
        comparisonCount = 0;




        // Apply Shell Sort
        std::copy(students, students + n, originalStudents);
        Sorted << "Algorithm: Shell Sort" << '\n';
        auto start4 = std::chrono::steady_clock::now();
        shellSort(originalStudents, n,[](Student s1,Student s2){return s1.getGpa() < s2.getGpa();},comparisonCount);
        auto end4 = std::chrono::steady_clock::now();
        Sorted << "Comparison Count :" << comparisonCount << '\n';
        Sorted << "Running Time:" << std::chrono::duration_cast<std::chrono::microseconds>(end4 - start4).count() << " microseconds" << '\n';

        for (int i = 0; i < n; ++i) {
            Sorted << "ID: " << originalStudents[i].getId() << ", Name: " << originalStudents[i].getName() << ", GPA: " << originalStudents[i].getGpa() << '\n';
        }
        Sorted << '\n';
        comparisonCount = 0;




        // Apply merge sort
        std::copy(students, students + n, originalStudents);
        Sorted << "Algorithm: Merge Sort" << '\n';
        auto start5 = std::chrono::steady_clock::now();
        mergeSort(originalStudents, 0, n - 1,[](Student s1,Student s2){return s1.getGpa() >= s2.getGpa();},comparisonCount);
        auto end5 = std::chrono::steady_clock::now();
        Sorted << "Comparison Count :" << comparisonCount << '\n';
        Sorted << "Running Time:" << std::chrono::duration_cast<std::chrono::microseconds>(end5 - start5).count() << " microseconds" << '\n';

        for (int i = 0; i < n; ++i) {
            Sorted << "ID: " << originalStudents[i].getId() << ", Name: " << originalStudents[i].getName() << ", GPA: " << originalStudents[i].getGpa() << '\n';
        }
        Sorted << '\n';
        comparisonCount = 0;



        // Apply quick sort
        std::copy(students, students + n, originalStudents);
        Sorted << "Algorithm: Quick Sort" << '\n';
        auto start6 = std::chrono::steady_clock::now();
        quickSort(originalStudents, 0, n - 1,[](Student s1,Student s2){return s1.getGpa() >= s2.getGpa();},comparisonCount);
        auto end6 = std::chrono::steady_clock::now();
        Sorted << "Comparison Count :" << comparisonCount << '\n';
        Sorted << "Running Time:" << std::chrono::duration_cast<std::chrono::microseconds>(end6 - start6).count() << " microseconds" << '\n';

        for (int i = 0; i < n; ++i) {
            Sorted << "ID: " << originalStudents[i].getId() << ", Name: " << originalStudents[i].getName() << ", GPA: " << originalStudents[i].getGpa() << '\n';
        }
        Sorted << '\n';
        comparisonCount = 0;

        // Apply Count Sort
        std::copy(students, students + n, originalStudents);
        Sorted << "Algorithm: Count Sort" << '\n';
        auto start7 = std::chrono::steady_clock::now();
        countSort(originalStudents,n, true);
        auto end7 = std::chrono::steady_clock::now();
        Sorted << "Comparison Count :" << comparisonCount << '\n';
        Sorted << "Running Time:" << std::chrono::duration_cast<std::chrono::microseconds>(end7 - start7).count() << " microseconds" << '\n';
        for (int i = 0; i < n; ++i) {
            Sorted << "ID: " << originalStudents[i].getId() << ", Name: " << originalStudents[i].getName() << ", GPA: " << originalStudents[i].getGpa() << '\n';
        }

        Sorted.close();
        delete[] originalStudents;



    };

};



#endif // _SORT_STUDENTS_H
