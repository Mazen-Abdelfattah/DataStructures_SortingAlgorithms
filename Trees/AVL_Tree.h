#ifndef _AVL_TREE_H
#define _AVL_TREE_H

#include <iostream>
#include <queue>

// AVL Node
template<class elemType>
struct AVLNode {
    elemType info;
    int bfactor;
    AVLNode<elemType> *llink;
    AVLNode<elemType> *rlink;


    AVLNode(const elemType& data, AVLNode<elemType>* lptr = nullptr, AVLNode<elemType>* rptr = nullptr) :
            info(data), bfactor(0), llink(lptr), rlink(rptr) {}
};




// AVL  Tree Class
template<class elemType, typename Compare = std::less<elemType>>
class AVLTree {
private:
    AVLNode<elemType> *root;
    Compare comparator;  ///<<<< Here I Can Say what I want to sort the tree according to so later I can Use it for any 7aga <3
                         /// The default is Less Than

    void balanceFromLeft(AVLNode<elemType>* &root);
    void balanceFromRight(AVLNode<elemType>* &root);
    void rotateToLeft(AVLNode<elemType>* &root);
    void rotateToRight(AVLNode<elemType>* &root);
    void insertIntoAVL(AVLNode<elemType>* &root, AVLNode<elemType>* newNode, bool& isTaller);
    void deleteFromAVL(AVLNode<elemType>* &root, const elemType &item, bool &shorter);
    void adjustBalanceFactor(AVLNode<elemType>* &root, bool &shorter, bool leftChild);

public:
    AVLTree() : root(nullptr) {}

    void insert(const elemType &newItem);
    void remove(const elemType &item);


    void printTree_ASC(AVLNode<elemType>* root) const;
    void printTree_NORM(AVLNode<elemType>* root) const;
    void printTree_DESC(AVLNode<elemType>* root) const;
    void print_ASC() const;
    void print_NORM() const;
    void print_DESC() const;

    void printTree_BFS(AVLNode<elemType>* root) const;
    void print_BFS() const;

};


template <class elemT, typename Compare>
void AVLTree<elemT, Compare>::balanceFromLeft(AVLNode<elemT>* &root) {
    if (root == nullptr) {
        std::cerr << "Error in the tree: Root is null" << '\n';
        return;
    }

    AVLNode<elemT> *p = root->llink; /// <<<<<< p points to the left subtree of root

    if (p == nullptr) {
        std::cerr << "Error: Cannot balance from the left. Left subtree is null." << '\n';
        return;
    }
    switch (p->bfactor) {
        case -1:
            root->bfactor = 0;
            p->bfactor = 0;
            rotateToRight(root);
            break;
        case 0:
            std::cerr << "Error: Cannot balance from the left." << '\n';
            break;
        case 1:
            AVLNode<elemT> *w = p->rlink;
            switch (w->bfactor) {
                case -1:
                    root->bfactor = 1;
                    p->bfactor = 0;
                    break;
                case 0:
                    root->bfactor = 0;
                    p->bfactor = 0;
                    break;
                case 1:
                    root->bfactor = 0;
                    p->bfactor = -1;
            }
            w->bfactor = 0;
            rotateToLeft(p);
            root->llink = p;
            rotateToRight(root);
            break;
    }

}

template <class elemT, typename Compare>
void AVLTree<elemT, Compare>::balanceFromRight(AVLNode<elemT>* &root) {
    if (root == nullptr) {
        std::cerr << "Error in the tree: Root is null" << '\n';
        return;
    }

    AVLNode<elemT> *p = root->rlink; ///<<<<<  p points to the right subtree of root

    if (p == nullptr) {
        std::cerr << "Error: Cannot balance from the right. Right subtree is null." << '\n';
        return;
    }

    switch (p->bfactor) {
        case -1:{
            AVLNode<elemT> *w = p->llink;
            switch (w->bfactor) {
                case -1:
                    root->bfactor = 0;
                    p->bfactor = 1;
                    break;
                case 0:
                    root->bfactor = 0;
                    p->bfactor = 0;
                    break;
                case 1:
                    root->bfactor = -1;
                    p->bfactor = 0;
            }
            w->bfactor = 0;
            rotateToRight(p);
            root->rlink = p;
            rotateToLeft(root);
            break;}
        case 0:
            std::cerr << "Error: Cannot balance from the right." << std::endl;
            break;
        case 1:
            root->bfactor = 0;
            p->bfactor = 0;
            rotateToLeft(root);
            break;
    }


}


template <class elemT, typename Compare>
void AVLTree<elemT, Compare>::rotateToLeft(AVLNode<elemT>* &root) {
    if (root == nullptr) {
        std::cerr << "Error in the tree: Root is null" << '\n';
        return;
    }

    if (root->rlink == nullptr) {
        std::cerr << "Error in the tree: No right subtree to rotate" << '\n';
        return;
    }

    AVLNode<elemT> *p = root->rlink; /// <<<<<<<<<<<< Pointer to the root of the right subtree of root
    root->rlink = p->llink; /// <<<<<<<<< The left subtree of p becomes the right subtree of root
    p->llink = root;
    root = p; /// <<<<<<<<< Make p the new root node
}

template <class elemT, typename Compare>
void AVLTree<elemT, Compare>::rotateToRight(AVLNode<elemT>* &root) {
    if (root == nullptr) {
        std::cerr << "Error in the tree: Root is null" << '\n';
        return;
    }

    if (root->llink == nullptr) {
        std::cerr << "Error in the tree: No left subtree to rotate" << '\n';
        return;
    }

    AVLNode<elemT> *p = root->llink; /// <<<<<< Pointer to the root of the left subtree of root
    root->llink = p->rlink; /// <<< The right subtree of p becomes the left subtree of root
    p->rlink = root;
    root = p; /// <<<< Make p the new root node
}

template<class elemT, typename Compare>
void AVLTree<elemT, Compare>::insertIntoAVL(AVLNode<elemT>* &root, AVLNode<elemT>* newNode, bool& isTaller) {
    if (root == nullptr) {
        root = newNode;
        isTaller = true;
    } else {

        if (comparator(root->info, newNode->info)) {
            // newItem goes in the left subtree
            insertIntoAVL(root->llink, newNode, isTaller);
            if (isTaller) {
                // After insertion, the subtree grew in height
                switch (root->bfactor) {
                    case -1:
                        balanceFromLeft(root);
                        isTaller = false;
                        break;
                    case 0:
                        root->bfactor = -1;
                        isTaller = true;
                        break;
                    case 1:
                        root->bfactor = 0;
                        isTaller = false;
                        break;
                }
            }
        } else if (comparator(newNode->info, root->info)) {
            // newItem goes in the right subtree
            insertIntoAVL(root->rlink, newNode, isTaller);
            if (isTaller) {
                // After insertion, the subtree grew in height
                switch (root->bfactor) {
                    case -1:
                        root->bfactor = 0;
                        isTaller = false;
                        break;
                    case 0:
                        root->bfactor = 1;
                        isTaller = true;
                        break;
                    case 1:
                        balanceFromRight(root);
                        isTaller = false;
                        break;
                }
            }
        } else {
            // No duplicates allowed
            std::cerr << "No duplicates are allowed." << newNode->info << "Is DELETED AUTOMATICALLY :3 " << '\n';
            delete newNode; // Clean up memory
            isTaller = false;
        }
    }
}


template<class elemT, typename Compare>
void AVLTree<elemT, Compare>::insert(const elemT &newItem) {
    bool isTaller = false; // Flag to track if the tree has grown taller after insertion
    AVLNode<elemT> *newNode = new AVLNode<elemT>(newItem); // Create a new node
    newNode->bfactor = 0; // Initialize balance factor to 0
    newNode->llink = nullptr; // Initialize left child pointer to null
    newNode->rlink = nullptr; // Initialize right child pointer to null

    // Call the helper function to insert the new node into the AVL tree
    insertIntoAVL(root, newNode, isTaller);
}

template <class elemT, typename Compare>
void AVLTree<elemT, Compare>::deleteFromAVL(AVLNode<elemT>* &root, const elemT &item, bool &shorter) {
    if (root == nullptr) {
        // Item not found in the tree
        std::cerr << "Item not found in the tree." << '\n';
        return;
    }

    if (comparator(root->info, item)) {
        // Item is in the left subtree
        deleteFromAVL(root->llink, item, shorter);
        if (shorter)
            adjustBalanceFactor(root, shorter, true);
    } else if (comparator(item, root->info)) {
        // Item is in the right subtree
        deleteFromAVL(root->rlink, item, shorter);
        if (shorter)
            adjustBalanceFactor(root, shorter, false);
    } else {
        // Item found, perform deletion
        AVLNode<elemT> *temp;
        if (root->llink == nullptr || root->rlink == nullptr) {
            // Node has one or no child
            temp = root;
            if (root->llink == nullptr)
                root = root->rlink;
            else
                root = root->llink;
            delete temp;
            shorter = true;
        } else {
            // Node has two children
            temp = root->llink;
            while (temp->rlink != nullptr)
                temp = temp->rlink;
            root->info = temp->info;
            deleteFromAVL(root->llink, temp->info, shorter);
            if (shorter)
                adjustBalanceFactor(root, shorter, true);
        }
    }
}

template <class elemT, typename Compare>
void AVLTree<elemT, Compare>::adjustBalanceFactor(AVLNode<elemT>* &root, bool &shorter, bool leftChild) {
    if (leftChild) {
        // Left subtree is shorter
        switch (root->bfactor) {
            case 1:
                root->bfactor = 0;
                shorter = false;
                break;
            case 0:
                root->bfactor = -1;
                shorter = true;
                break;
            case -1:
                AVLNode<elemT> *p = root->rlink;
                if (p->bfactor == 0 || p->bfactor == -1) {
                    // Single rotation required
                    rotateToLeft(root);
                    if (p->bfactor == 0)
                        shorter = false;
                    else
                        shorter = true;
                } else {
                    // Double rotation required
                    AVLNode<elemT> *q = p->llink;
                    rotateToRight(p);
                    root->rlink = p;
                    rotateToLeft(root);
                    if (q->bfactor == 0)
                        root->bfactor = p->bfactor = 0;
                    else if (q->bfactor == 1) {
                        root->bfactor = 0;
                        p->bfactor = -1;
                    } else {
                        root->bfactor = 1;
                        p->bfactor = 0;
                    }
                    shorter = false;
                }
                break;
        }
    } else {
        // Right subtree is shorter
        // Similar logic as above, but for the right subtree
    }
}

template <class elemT, typename Compare>
void AVLTree<elemT, Compare>::remove(const elemT &item) {
    bool shorter = false; // Flag to track if the tree has become shorter after deletion
    deleteFromAVL(root, item, shorter);
}

template <class elemT, typename Compare>
void AVLTree<elemT, Compare>::printTree_DESC(AVLNode<elemT>* root) const {
    if (root != nullptr) {
        printTree_DESC(root->llink);
        std::cout << root->info << " ";
        printTree_DESC(root->rlink);
    }
}

template <class elemT, typename Compare>
void AVLTree<elemT, Compare>::printTree_NORM(AVLNode<elemT>* root) const {
    if (root != nullptr) {
        std::cout << root->info << " ";
        printTree_NORM(root->rlink);
        printTree_NORM(root->llink);
    }
}
template <class elemT, typename Compare>
void AVLTree<elemT, Compare>::printTree_ASC(AVLNode<elemT>* root) const {
    if (root != nullptr) {
        printTree_ASC(root->rlink);
        std::cout << root->info << " ";
        printTree_ASC(root->llink);
    }
}

template <class elemT, typename Compare>
void AVLTree<elemT, Compare>::print_DESC() const {
    printTree_DESC(root);
    std::cout << '\n';
}

template <class elemT, typename Compare>
void AVLTree<elemT, Compare>::print_NORM() const {
    printTree_NORM(root);
    std::cout << '\n';
}

template <class elemT, typename Compare>
void AVLTree<elemT, Compare>::print_ASC() const {
    printTree_ASC(root);
    std::cout << '\n';
}


template <class elemT, typename Compare>
void AVLTree<elemT, Compare>::printTree_BFS(AVLNode<elemT>* root) const {
    if (root == nullptr)
        return;

    std::queue<AVLNode<elemT>*> q;
    q.push(root);

    while (!q.empty()) {
        AVLNode<elemT>* current = q.front();
        q.pop();

        std::cout << current->info << " ";

        if (current->rlink != nullptr)
            q.push(current->rlink);
        if (current->llink != nullptr)
            q.push(current->llink);

    }
}


template <class elemT, typename Compare>
void AVLTree<elemT, Compare>::print_BFS() const {
    printTree_BFS(root);
    std::cout << '\n';
}




#endif //_AVL_TREE_H
