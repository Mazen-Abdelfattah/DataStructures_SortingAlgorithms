#include <iostream>
#include "AVL_Tree.h" // Include the AVL tree class header file
#include "Item_Class.h"
#include "BST.h"
#include "Heap.h"

#include <fstream>
#include <limits>

using namespace std;

void AVL_menu()
{
    AVLTree<item,ComparatorbyPrice> Tree1; /// <<< This tree will sort by price
    AVLTree<item,ComparatorbyName>Tree2; /// <<< This tree will sort by name
    bool flag = true;
    while (flag) {
        int jojo;
        std::cout << "Welcome to AVL simulator" << '\n';
        std::cout << "1. Add Item" << '\n';
        std::cout << "2. Add Items from a file" << '\n';
        std::cout << "3. Remove item" << '\n';
        std::cout << "4. Display All items " << '\n';
        std::cout << "5. Display all the items sorted by their name ascending " << '\n';
        std::cout << "6. Display all the items sorted by their name descending " << '\n';
        std::cout << "7. Display all the items sorted by their prices ascending " << '\n';
        std::cout << "8. Display all the items sorted by their prices descending. " << '\n';
        std::cout << "9. Output all Results in output.txt . " << '\n';
        std::cout << "10. Return to main menu. " << '\n';
        cin >> jojo;

        switch (jojo) {
            case 1: {
                int p;
                string s1, s2;
                cout << "Please inter the item name (no Spaces) \n";
                cin >> s1;
                cout << "Please inter the item category (no Spaces) \n";
                cin >> s2;
                cout << "Please inter the item price \n";
                cin >> p;
                Tree1.insert(item(s1, s2, p));
                Tree2.insert(item(s1, s2, p));
                break;
            }
            case 2: {
                std::string filename;
                std::cout << "Please enter the file name: \n";
                std::cin >> filename;
                std::ifstream file(filename);
                if (!file.is_open()) {
                    std::cout << "Error opening file!\n";
                    break;
                }
                int numInputs;
                file >> numInputs;
                std::string name, category;
                int price;
                for (int i = 0; i < numInputs; ++i) {
                    file.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n'); // Ignore the newline left by previous reads
                    std::getline(file, name);
                    std::getline(file, category);
                    file >> price;
                    Tree1.insert(item(name, category, price));
                    Tree2.insert(item(name, category, price));
                }
                file.close();
                std::cout << "Items added from file.\n";
                break;
            }
            case 3: {
                std::cout << "Enter the name ,category and price of the item you want to remove: \n ";
                int p;
                string s1, s2;
                cout << "Please inter the item name (no Spaces) \n";
                cin >> s1;
                cout << "Please inter the item category (no Spaces) \n";
                cin >> s2;
                cout << "Please inter the item price \n";
                cin >> p;
                Tree1.remove(item(s1, s2, p));
                Tree2.remove(item(s1, s2, p));
                break;
            }
            case 4: {
                cout << "Normal Tree according to Price(BFS) (NO SORTING): \n";
                Tree1.print_BFS();
                cout << '\n' << "--------------------------" << '\n';
                cout << "Normal Tree according to Name(BFS)(NO SORTING): \n";
                Tree2.print_BFS();
                break;
            }
            case 5: {
                std::cout << "Display all the items sorted by their name ascending " << '\n';
                Tree2.print_ASC();
                break;
            }
            case 6: {
                std::cout << "Display all the items sorted by their name descending " << '\n';
                Tree2.print_DESC();
                break;
            }
            case 7: {
                std::cout << "Display all the items sorted by their prices ascending " << '\n';
                Tree1.print_ASC();
                break;

            }
            case 8: {
                std::cout << "Display all the items sorted by their prices descending. " << '\n';
                Tree1.print_DESC();
                break;
            }
            case 9:{
                FILE *file = freopen("output.txt", "w", stdout);
                if (!file) {
                    std::cerr << "Error opening file!" << std::endl;
                    break;
                }
                cout << "AVL RESULTS" << '\n';
                cout << "Normal Tree according to Price(BFS)(NO SORTING): \n";
                Tree1.print_BFS();
                cout << '\n' << "--------------------------" << '\n';
                cout << "Normal Tree according to Name(BFS)(NO SORTING): \n";
                Tree2.print_BFS();
                cout << '\n' << "--------------------------" << '\n';
                std::cout << "Display all the items sorted by their name ascending " << '\n';
                Tree2.print_ASC();
                std::cout << "Display all the items sorted by their name descending " << '\n';
                Tree2.print_DESC();
                std::cout << "Display all the items sorted by their prices ascending " << '\n';
                Tree1.print_ASC();
                std::cout << "Display all the items sorted by their prices descending. " << '\n';
                Tree1.print_DESC();

                fclose(file);
                freopen("/dev/tty", "w", stdout);
                freopen("CON", "w", stdout);
                break;


            }
            case 10:{
                flag = false;
                return;
                break;
            }

        }
    }
}

void BST_menu()
{
    BinarySearchTree<item,ComparatorbyPrice> Tree1; /// <<< This tree will sort by price
    BinarySearchTree<item,ComparatorbyName>Tree2; /// <<< This tree will sort by name
    bool flag = true;
    while (flag) {
        int jojo;
        std::cout << "Welcome to BST simulator" << '\n';
        std::cout << "1. Add Item" << '\n';
        std::cout << "2. Add Items from a file" << '\n';
        std::cout << "3. Remove item" << '\n';
        std::cout << "4. Display All items " << '\n';
        std::cout << "5. Display all the items sorted by their name ascending " << '\n';
        std::cout << "6. Display all the items sorted by their name descending " << '\n';
        std::cout << "7. Display all the items sorted by their prices ascending " << '\n';
        std::cout << "8. Display all the items sorted by their prices descending. " << '\n';
        std::cout << "9. Output all Results in output.txt . " << '\n';
        std::cout << "10. Return to main menu. " << '\n';
        cin >> jojo;

        switch (jojo) {
            case 1: {
                int p;
                string s1, s2;
                cout << "Please inter the item name (no Spaces) \n";
                cin >> s1;
                cout << "Please inter the item category (no Spaces) \n";
                cin >> s2;
                cout << "Please inter the item price \n";
                cin >> p;
                Tree1.insert(item(s1, s2, p));
                Tree2.insert(item(s1, s2, p));
                break;
            }
            case 2: {
                std::string filename;
                std::cout << "Please enter the file name: \n";
                std::cin >> filename;
                std::ifstream file(filename);
                if (!file.is_open()) {
                    std::cout << "Error opening file!\n";
                    break;
                }
                int numInputs;
                file >> numInputs;
                std::string name, category;
                int price;
                for (int i = 0; i < numInputs; ++i) {
                    file.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n'); // Ignore the newline left by previous reads
                    std::getline(file, name);
                    std::getline(file, category);
                    file >> price;
                    Tree1.insert(item(name, category, price));
                    Tree2.insert(item(name, category, price));
                }
                file.close();
                std::cout << "Items added from file.\n";
                break;
            }
            case 3: {
                std::cout << "Enter the name ,category and price of the item you want to remove: \n ";
                int p;
                string s1, s2;
                cout << "Please inter the item name (no Spaces) \n";
                cin >> s1;
                cout << "Please inter the item category (no Spaces) \n";
                cin >> s2;
                cout << "Please inter the item price \n";
                cin >> p;
                Tree1.remove(item(s1, s2, p));
                Tree2.remove(item(s1, s2, p));
                break;
            }
            case 4: {
                cout << "Normal Tree according to Price(BFS)(NO SORTING): \n";
                Tree1.print_BFS();
                cout << '\n' << "--------------------------" << '\n';
                cout << "Normal Tree according to Name(BFS)(NO SORTING): \n";
                Tree2.print_BFS();
                break;
            }
            case 5: {
                std::cout << "Display all the items sorted by their name ascending " << '\n';
                Tree2.print_LVR();
                break;
            }
            case 6: {
                std::cout << "Display all the items sorted by their name descending " << '\n';
                Tree2.print_RVL();
                break;
            }
            case 7: {
                std::cout << "Display all the items sorted by their prices ascending " << '\n';
                Tree1.print_LVR();
                break;

            }
            case 8: {
                std::cout << "Display all the items sorted by their prices descending. " << '\n';
                Tree1.print_RVL();
                break;
            }
            case 9:{
                cout << "BST RESULTS" << '\n';
                FILE *file = freopen("output.txt", "w", stdout);
                if (!file) {
                    std::cerr << "Error opening file!" << std::endl;
                    break;
                }
                cout << "BST RESULTS" << '\n';
                cout << "Normal Tree according to Price(BFS)(NO SORTING): \n";
                Tree1.print_BFS();
                cout << '\n' << "--------------------------" << '\n';
                cout << "Normal Tree according to Name(BFS)(NO SORTING): \n";
                Tree2.print_BFS();
                cout << '\n' << "--------------------------" << '\n';
                std::cout << "Display all the items sorted by their name ascending " << '\n';
                Tree2.print_LVR();
                cout << '\n' << "--------------------------" << '\n';

                std::cout << "Display all the items sorted by their name descending " << '\n';
                Tree2.print_RVL();
                cout << '\n' << "--------------------------" << '\n';

                std::cout << "Display all the items sorted by their prices ascending " << '\n';
                Tree1.print_LVR();
                cout << '\n' << "--------------------------" << '\n';

                std::cout << "Display all the items sorted by their prices descending. " << '\n';
                Tree1.print_RVL();
                cout << '\n' << "--------------------------" << '\n';


                fclose(file);
                freopen("/dev/tty", "w", stdout);
                freopen("CON", "w", stdout);
                break;


            }
            case 10:{
                flag = false;
                return;
                break;
            }

        }
    }
}


void HEAP_menu()
{
    MaxHeap<item,ComparatorbyPrice> XHeap1; /// <<< This tree will sort by price (MAX HEAP)
    MaxHeap<item,ComparatorbyName> XHeap2; /// <<< This tree will sort by name (MAX HEAP)
    MinHeap<item,ComparatorbyPrice> NHeap1; /// <<< This tree will sort by price (MIN HEAP)
    MinHeap<item,ComparatorbyName> NHeap2; /// <<< This tree will sort by name (MIN HEAP)
    bool flag = true;
    while (flag) {
        int jojo;
        std::cout << "Welcome to HEAP simulator" << '\n';
        std::cout << "1. Add Item" << '\n';
        std::cout << "2. Add Items from a file" << '\n';
        std::cout << "3. Remove item" << '\n';
        std::cout << "4. Display All items " << '\n';
        std::cout << "5. Display all the items sorted by their name ascending (This will apply Heap sort on the HEAP) " << '\n';
        std::cout << "6. Display all the items sorted by their name descending (This will apply Heap sort on the HEAP)" << '\n';
        std::cout << "7. Display all the items sorted by their prices ascending (This will apply Heap sort on the HEAP)" << '\n';
        std::cout << "8. Display all the items sorted by their prices descending (This will apply Heap sort on the HEAP) " << '\n';
        std::cout << "9. Output all Results in output.txt . " << '\n';
        std::cout << "10. Return to main menu. " << '\n';
        cin >> jojo;

        switch (jojo) {
            case 1: {
                int p;
                string s1, s2;
                cout << "Please inter the item name (no Spaces) \n";
                cin >> s1;
                cout << "Please inter the item category (no Spaces) \n";
                cin >> s2;
                cout << "Please inter the item price \n";
                cin >> p;
                XHeap1.insert(item(s1, s2, p));
                XHeap2.insert(item(s1, s2, p));
                NHeap1.insert(item(s1, s2, p));
                NHeap2.insert(item(s1, s2, p));

                break;
            }
            case 2: {
                std::string filename;
                std::cout << "Please enter the file name: \n";
                std::cin >> filename;
                std::ifstream file(filename);
                if (!file.is_open()) {
                    std::cout << "Error opening file!\n";
                    break;
                }
                int numInputs;
                file >> numInputs;
                std::string name, category;
                int price;
                for (int i = 0; i < numInputs; ++i) {
                    file.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n'); // Ignore the newline left by previous reads
                    std::getline(file, name);
                    std::getline(file, category);
                    file >> price;
                    XHeap1.insert(item(name, category, price));
                    XHeap2.insert(item(name, category, price));
                    NHeap1.insert(item(name, category, price));
                    NHeap2.insert(item(name, category, price));
                }
                file.close();
                std::cout << "Items added from file.\n";
                break;
            }
            case 3: {
                std::cout << "Enter the name ,category and price of the item you want to remove: \n ";
                int p;
                string s1, s2;
                cout << "Please inter the item name (no Spaces) \n";
                cin >> s1;
                cout << "Please inter the item category (no Spaces) \n";
                cin >> s2;
                cout << "Please inter the item price \n";
                cin >> p;
                XHeap1.remove(item(s1, s2, p));
                XHeap2.remove(item(s1, s2, p));
                NHeap1.remove(item(s1, s2, p));
                NHeap2.remove(item(s1, s2, p));
                break;
            }
            case 4: {
                cout << "Normal MIN HEAP according to Price(BFS) NOTE THAT IF YOU APPLIED HEAP SORT IT WILL BE SORTED: \n";
                NHeap1.print_BFS();
                cout << '\n' << "--------------------------" << '\n';
                cout << "Normal MAX HEAP according to Price(BFS) NOTE THAT IF YOU APPLIED HEAP SORT IT WILL BE SORTED: \n";
                XHeap1.print_BFS();

                cout << '\n' << "--------------------------" << '\n';
                cout << "Normal MIN HEAP according to Name(BFS) NOTE THAT IF YOU APPLIED HEAP SORT IT WILL BE SORTED: \n";
                NHeap2.print_BFS();

                cout << '\n' << "--------------------------" << '\n';
                cout << "Normal MAX HEAP according to Name(BFS) NOTE THAT IF YOU APPLIED HEAP SORT IT WILL BE SORTED: \n";
                XHeap2.print_BFS();

                break;
            }
            case 5: {
                std::cout << "Display all the items sorted by their name ascending THIS WILL APPLY HEAP SORT ON THE MAX HEAP " << '\n';
                XHeap2.heapSort();
                XHeap2.print_BFS();
                break;
            }
            case 6: {
                std::cout << "Display all the items sorted by their name descending THIS WILL APPLY HEAP SORT ON THE MIN HEAP " << '\n';
                NHeap2.heapSort();
                NHeap2.print_BFS();
                break;
            }
            case 7: {
                std::cout << "Display all the items sorted by their prices ascending THIS WILL APPLY HEAP SORT ON THE MAX HEAP" << '\n';
                XHeap1.heapSort();
                XHeap1.print_BFS();
                break;

            }
            case 8: {
                std::cout << "Display all the items sorted by their prices descending THIS WILL APPLY HEAP SORT ON THE MIN HEAP " << '\n';
                NHeap1.heapSort();
                NHeap1.print_BFS();
                break;
            }
            case 9:{
                cout << "HEAP RESULTS" << '\n';
                FILE *file = freopen("output.txt", "w", stdout);
                if (!file) {
                    std::cerr << "Error opening file!" << std::endl;
                    break;
                }

                cout << "Normal MIN HEAP according to Price(BFS) NOTE THAT IF YOU APPLIED HEAP SORT IT WILL BE SORTED: \n";
                NHeap1.print_BFS();
                cout << '\n' << "--------------------------" << '\n';
                cout << "Normal MAX HEAP according to Price(BFS) NOTE THAT IF YOU APPLIED HEAP SORT IT WILL BE SORTED: \n";
                XHeap1.print_BFS();

                cout << '\n' << "--------------------------" << '\n';
                cout << "Normal MIN HEAP according to Name(BFS) NOTE THAT IF YOU APPLIED HEAP SORT IT WILL BE SORTED: \n";
                NHeap2.print_BFS();

                cout << '\n' << "--------------------------" << '\n';
                cout << "Normal MAX HEAP according to Name(BFS) NOTE THAT IF YOU APPLIED HEAP SORT IT WILL BE SORTED: \n";
                XHeap2.print_BFS();
                cout << '\n' << "--------------------------" << '\n';

                std::cout << "Display all the items sorted by their name ascending THIS WILL APPLY HEAP SORT ON THE MAX HEAP " << '\n';
                XHeap2.heapSort();
                XHeap2.print_BFS();
                cout << '\n' << "--------------------------" << '\n';

                std::cout << "Display all the items sorted by their name descending THIS WILL APPLY HEAP SORT ON THE MIN HEAP " << '\n';
                NHeap2.heapSort();
                NHeap2.print_BFS();
                cout << '\n' << "--------------------------" << '\n';

                std::cout << "Display all the items sorted by their prices ascending THIS WILL APPLY HEAP SORT ON THE MAX HEAP" << '\n';
                XHeap1.heapSort();
                XHeap1.print_BFS();
                cout << '\n' << "--------------------------" << '\n';


                std::cout << "Display all the items sorted by their prices descending THIS WILL APPLY HEAP SORT ON THE MIN HEAP " << '\n';
                NHeap1.heapSort();
                NHeap1.print_BFS();
                cout << '\n' << "--------------------------" << '\n';

                fclose(file);
                freopen("/dev/tty", "w", stdout);
                freopen("CON", "w", stdout);
                break;

            }
            case 10:{
                flag = false;
                return;
                break;
            }

        }
    }




}






int main() {

    int option;
    while (true) {
        std::cout << "Welcome to Tree Simulator\n";
        std::cout << "1. BST\n";
        std::cout << "2. AVL\n";
        std::cout << "3. HEAP\n";
        std::cout << "4. Exit\n";
        cin >> option;
        switch (option) {
            case 1:
                std::cout << "You chose BST (Binary Search Tree)\n";
                BST_menu();
                break;
            case 2:
                std::cout << "You chose AVL (Adelson-Velsky and Landis Tree)\n";
                AVL_menu();
                break;
            case 3:
                std::cout << "You chose HEAP\n";
                HEAP_menu();
                break;
            case 4:
                std::cout << "Exiting the program.\n";
                exit(0);
                break;
        }
    }




    return 0;
}

