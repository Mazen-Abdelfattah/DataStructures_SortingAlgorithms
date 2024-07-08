#include "Student.h"
#include "Sorting_Algorithms.h"
#include "Sort_Students.h"



#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()




int main() {

//    Student s1("20221202","Youssef",1.0), s2("20221255","Momo",3.0) ;
//
//    // Testing Getters
//    std::cout << "ID: " << s1.getId() << ", Name: " << s1.getName() << ", GPA: " << s1.getGpa() << std::endl;
//
//    //Testing Setters
//    s1.setName("F");
//    s1.setGpa(2.8);
//    s1.setId("258");
//    std::cout << "ID: " << s1.getId() << ", Name: " << s1.getName() << ", GPA: " << s1.getGpa() << std::endl;
//
//    std::cout << (s1 < s2) << std::endl;
//
//
////    Testing Selection sort
//    auto start1 = std::chrono::steady_clock::now();
//    int arr[80] = {31, 12, 5, 67, 23, 49, 78, 15, 92, 41,
//                   7, 88, 53, 17, 62, 29, 84, 38, 11, 74,
//                   19, 59, 96, 45, 21, 83, 35, 68, 9, 56,
//                   27, 73, 47, 89, 36, 81, 64, 33, 77, 51,
//                   16, 97, 42, 25, 71, 55, 13, 87, 61, 39,
//                   75, 32, 95, 69, 43, 85, 57, 22, 91, 48,
//                   37, 82, 65, 34, 79, 52, 18, 93, 44, 26,
//                   63, 8, 66, 99, 54, 14, 76, 58, 24, 94};
//    mergeSort(arr,0,79);
//    auto end1 = std::chrono::steady_clock::now();
//    std::cout << "Time taken for sorting arr: " << std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count() << " milliseconds" << std::endl;
//    for (int i = 0; i < 80; ++i) {
//        std::cout << arr[i] << " ";
//    }
//    std::cout<<'\n';
//
//    auto start2 = std::chrono::steady_clock::now();
//    int arr2[80] = {31, 12, 5, 67, 23, 49, 78, 15, 92, 41,
//                   7, 88, 53, 17, 62, 29, 84, 38, 11, 74,
//                   19, 59, 96, 45, 21, 83, 35, 68, 9, 56,
//                   27, 73, 47, 89, 36, 81, 64, 33, 77, 51,
//                   16, 97, 42, 25, 71, 55, 13, 87, 61, 39,
//                   75, 32, 95, 69, 43, 85, 57, 22, 91, 48,
//                   37, 82, 65, 34, 79, 52, 18, 93, 44, 26,
//                   63, 8, 66, 99, 54, 14, 76, 58, 24, 94};
//    quickSort(arr2,0,79);
//    auto end2 = std::chrono::steady_clock::now();
//    std::cout << "Time taken for sorting arr2: " << std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count() << " milliseconds" << std::endl;
//    for (int i = 0; i < 80; ++i) {
//        std::cout << arr2[i] << " ";
//    }
//
//    int arr3[80] = {31, 12, 5, 67, 23, 49, 78, 15, 92, 41,
//                   7, 88, 53, 17, 62, 29, 84, 38, 11, 74,
//                   19, 59, 96, 45, 21, 83, 35, 68, 9, 56,
//                   27, 73, 47, 89, 36, 81, 64, 33, 77, 51,
//                   16, 97, 42, 25, 71, 55, 13, 87, 61, 39,
//                   75, 32, 95, 69, 43, 85, 57, 22, 91, 48,
//                   37, 82, 65, 34, 79, 52, 18, 93, 44, 26,
//                   63, 8, 66, 99, 54, 14, 76, 58, 24, 94};
//    auto start3 = std::chrono::steady_clock::now();
//    countSort(arr3,80);
//    auto end3 = std::chrono::steady_clock::now();
//    std::cout << "Time taken for sorting arr2: " << std::chrono::duration_cast<std::chrono::milliseconds>(end3 - start3).count() << " milliseconds" << std::endl;
//    for (int i = 0; i < 80; ++i) {
//        std::cout << arr3[i] << " ";
//    }

applySorting m1("students.txt");
m1.sortByname();
m1.sortBygpa();



    return 0;
}
