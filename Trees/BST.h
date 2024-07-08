//
// Created by youssef on 5/16/2024.
//

#ifndef _BST_H
#define _BST_H

#include <iostream>
#include <queue>


template <class elemType>
struct binaryTreeNode
{
    elemType info;
    binaryTreeNode<elemType> *llink;
    binaryTreeNode<elemType> *rlink;

    /// >>>>>>>>>> Default constructor
    binaryTreeNode() : info(elemType()), llink(nullptr), rlink(nullptr) {}

    /// >>>>>>>>>  Constructor with parameters
    binaryTreeNode(const elemType& value, binaryTreeNode<elemType>* left = nullptr, binaryTreeNode<elemType>* right = nullptr)
            : info(value), llink(left), rlink(right) {}
};

template <class elemType, typename Compare = std::less<elemType>>
class BinarySearchTree {
private:
    binaryTreeNode<elemType>* root;
    Compare comparator;     ///<<<< Here I Can Say what I want to sort the tree according to so later I can Use it for any 7aga <3
                           /// The default is Less Than


    void destroyTree(binaryTreeNode<elemType>* node);
    void removeHelper(binaryTreeNode<elemType>*& p);
    void print_LVR_Helper(binaryTreeNode<elemType>* node);
    void print_RVL_Helper(binaryTreeNode<elemType>* node);

public:

    BinarySearchTree() : root(nullptr) {}
    BinarySearchTree(const elemType& value) : root(new binaryTreeNode<elemType>(value)) {}


    ~BinarySearchTree();

    bool search(const elemType& searchItem) const;
    void insert(const elemType& value);
    void remove(const elemType& value);
    void print_BFS();
    void print_LVR();
    void print_RVL();
};


template <class elemType, typename Compare>
void BinarySearchTree<elemType, Compare>::insert(const elemType& insertItem) {
    binaryTreeNode<elemType>* current; // pointer to traverse the tree
    binaryTreeNode<elemType>* trailCurrent; // pointer behind current
    binaryTreeNode<elemType>* newNode; // pointer to create the node

    // Create a new node for the item to be inserted
    newNode = new binaryTreeNode<elemType>;
    newNode->info = insertItem;
    newNode->llink = nullptr;
    newNode->rlink = nullptr;

    if (this->root == nullptr) // If the tree is empty, insert the node as the root
    {
        this->root = newNode;
    }
    else
    {
        current = this->root;
        trailCurrent = nullptr;

        while (current != nullptr)
        {
            trailCurrent = current;

            if (comparator(current->info, insertItem))
            {
                current = current->rlink;
            }
            else if (comparator(insertItem, current->info))
            {
                current = current->llink;
            }
            else
            {
                std::cerr << "The insert item is already in the list - duplicates are not allowed: " << insertItem << std::endl;
                delete newNode; // Deallocate memory for the new node
                return;

            }
        }

        if (trailCurrent != nullptr) {
            if (comparator(insertItem, trailCurrent->info)) // Insert the new node as the left child of trailCurrent
            {
                trailCurrent->llink = newNode;
            }
            else // Insert the new node as the right child of trailCurrent
            {
                trailCurrent->rlink = newNode;
            }
        }
    }
}


template <class elemType, typename Compare>
void BinarySearchTree<elemType, Compare>::removeHelper(binaryTreeNode<elemType>*& p) {
    binaryTreeNode<elemType>* current;       // pointer to traverse the tree
    binaryTreeNode<elemType>* trailCurrent;  // pointer behind current
    binaryTreeNode<elemType>* temp;          // pointer to delete the node

    if (p == nullptr)
    {
        std::cerr << "Error: The node to be deleted is NULL." << std::endl;
    }
    else if (p->llink == nullptr && p->rlink == nullptr) // Node to be deleted has no children
    {
        temp = p;
        p = nullptr;
        delete temp;
    }
    else if (p->llink == nullptr) // Node to be deleted has only a right child
    {
        temp = p;
        p = temp->rlink;
        delete temp;
    }
    else if (p->rlink == nullptr) // Node to be deleted has only a left child
    {
        temp = p;
        p = temp->llink;
        delete temp;
    }
    else // Node to be deleted has both left and right children
    {
        current = p->llink;
        trailCurrent = nullptr;

        while (current->rlink != nullptr) // Find the rightmost node in the left subtree
        {
            trailCurrent = current;
            current = current->rlink;
        }

        // Replace the info of the node to be deleted with the info of the rightmost node
        p->info = current->info;

        if (trailCurrent == nullptr) // If the rightmost node is the left child of the node to be deleted
        {
            p->llink = current->llink;
        }
        else // If the rightmost node is not the left child of the node to be deleted
        {
            trailCurrent->rlink = current->llink;
        }

        delete current;
    }
}

template <class elemType, typename Compare>
void BinarySearchTree<elemType, Compare>::remove(const elemType& deleteItem) {
    binaryTreeNode<elemType>* current;       // pointer to traverse the tree
    binaryTreeNode<elemType>* trailCurrent;  // pointer behind current
    bool found = false;                      // flag to indicate if the item to delete is found

    if (this->root == nullptr) // If the tree is empty
    {
        std::cout << "Cannot delete from the empty tree." << std::endl;
        return;
    }

    current = this->root;
    trailCurrent = nullptr;

    // Search for the node containing deleteItem
    while (current != nullptr && !found)
    {
        if (current->info == deleteItem) // If deleteItem is found
        {
            found = true;
        }
        else
        {
            trailCurrent = current; // Update trailCurrent to be behind current

            if (comparator(deleteItem,current->info))
            {
                current = current->llink; // Move to the left child
            }
            else
            {
                current = current->rlink; // Move to the right child
            }
        }
    }

    if (current == nullptr)
    {
        std::cerr << "The delete item is not in the tree." << '\n';
    }
    else if (found)
    {
        if (current == this->root)
        {
            removeHelper(this->root);
        }
        else if (comparator(deleteItem , trailCurrent->info))
        {
            removeHelper(trailCurrent->llink);
        }
        else
        {
            removeHelper(trailCurrent->rlink);
        }
    }

}



template <class elemType, typename Compare>
bool BinarySearchTree<elemType, Compare>::search(const elemType& searchItem) const {
    binaryTreeNode<elemType>* current;
    bool found = false;

    if (this->root == nullptr)
    {
        std::cerr << "Cannot search the empty tree." << std::endl;
    }
    else
    {
        current = this->root;
        while (current != nullptr && !found)
        {
            if (comparator(current->info, searchItem)) /// >>>>> If current->info is less than searchItem
            {
                current = current->rlink;
            }
            else if (comparator(searchItem, current->info)) /// >>>>> If current->info is greater than searchItem
            {
                current = current->llink;
            }
            else
            {
                found = true;
            }
        }
    }

    return found;
}



template <class elemType, typename Compare>
void BinarySearchTree<elemType, Compare>::print_BFS() {
    if (this->root == nullptr) {
        std::cout << "Tree is empty." << std::endl;
        return;
    }

    std::queue<binaryTreeNode<elemType>*> q;
    q.push(this->root);

    while (!q.empty()) {
        binaryTreeNode<elemType>* current = q.front();
        q.pop();
        std::cout << current->info << " ";

        if (current->llink != nullptr)
            q.push(current->llink);

        if (current->rlink != nullptr)
            q.push(current->rlink);
    }

    std::cout << std::endl;
}

template <class elemType, typename Compare>
void BinarySearchTree<elemType, Compare>::print_LVR() {
    print_LVR_Helper(this->root);
    std::cout << std::endl;
}

template <class elemType, typename Compare>
void BinarySearchTree<elemType, Compare>::print_LVR_Helper(binaryTreeNode<elemType>* node) {
    if (node != nullptr) {
        print_LVR_Helper(node->llink);
        std::cout << node->info << " ";
        print_LVR_Helper(node->rlink);
    }
}

template <class elemType, typename Compare>
void BinarySearchTree<elemType, Compare>::print_RVL() {
    print_RVL_Helper(this->root);
    std::cout << std::endl;
}

template <class elemType, typename Compare>
void BinarySearchTree<elemType, Compare>::print_RVL_Helper(binaryTreeNode<elemType>* node) {
    if (node != nullptr) {
        print_RVL_Helper(node->rlink);
        std::cout << node->info << " ";
        print_RVL_Helper(node->llink);
    }
}


template <class elemType, typename Compare>
BinarySearchTree<elemType, Compare>::~BinarySearchTree() {
    // Call a helper function to deallocate memory recursively
    destroyTree(root);
}

template <class elemType, typename Compare>
void BinarySearchTree<elemType, Compare>::destroyTree(binaryTreeNode<elemType>* node) {
    if (node != nullptr) {
        destroyTree(node->llink); // Recursively deallocate memory for left subtree
        destroyTree(node->rlink); // Recursively deallocate memory for right subtree
        delete node; // Deallocate memory for current node
    }
}












#endif //_BST_H
