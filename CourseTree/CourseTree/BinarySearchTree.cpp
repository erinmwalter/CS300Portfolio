#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

//default constructor
BinarySearchTree::BinarySearchTree() {
    //root is equal to nullptr
    root = nullptr;
}

//destructor
BinarySearchTree::~BinarySearchTree() {
    // recurse from root deleting every node
    destroy(root);

}

void BinarySearchTree::destroy(Node* node) {
    //destructor that recursively deletes all nodes
    if (node != nullptr) {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }
        else {
            destroy(node->left);
            destroy(node->right);
        }
    }
}

//display tree nodes in order
void BinarySearchTree::InOrder() {
    inOrder(root);
}

void BinarySearchTree::inOrder(Node* node) {

    if (node != nullptr) {

        inOrder(node->left);
        cout << node->course.courseNumber << ": " << node->course.courseDescription << endl;
        if (node->course.prerequisites.size() != 0) {
            cout << "Prerequisites: ";
            for (int i = 0; i < node->course.prerequisites.size(); i++)
            {
                cout << node->course.prerequisites[i] << " ";
            }
            cout << endl;
        }
        else {
            cout << "Prerequisites: None" << endl;
        }
        cout << endl;
        inOrder(node->right);
    }
}


//insert a course into tree
void BinarySearchTree::Insert(Course course) {
    // if root equarl to null ptr
    if (root == nullptr) {
        // root is equal to new node course
        root = new Node(course);
    }
    //traverse tree to add node in correct location
    else {
        this->addNode(root, course);
    }
}

//remove a course from tree
//not used in main program but implemented 
//in case CS department would need future need for this
void BinarySearchTree::Remove(string courseNumber) {
    // start at top with root
    removeNode(root, courseNumber);
}

Node* BinarySearchTree::removeNode(Node* node, string courseNumber) {
    //if starting on empty tree
    if (node == nullptr) {
        return node;
    }
    //if it's found remove and restring tree together
    else if (node->course.courseNumber == courseNumber) {
        //case: no children
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }
        //case: only one child to left
        else if (node->left != nullptr && node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        //case: only one child to right
        else if (node->right != nullptr && node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        //case: two children
        else {
            Node* temp = node->right;
            while (temp->left != nullptr) {
                //look for the minimum
                temp = temp->left;
            }
            node->course = temp->course;
            node->right = removeNode(node->right, temp->course.courseNumber);
        }
    }
    //otherwise traverse the tree to find it
    else if (node->course.courseNumber > courseNumber) {
        node->left = removeNode(node->left, courseNumber);
    }
    else {
        node->right = removeNode(node->right, courseNumber);
    }

    return node;
}

//search for a course
Course BinarySearchTree::Search(string courseNumber) {

    // set current node equal to root
    Node* current = root;
    // keep looping downwards until bottom reached or matching courseNumber found
    while (current != nullptr) {
        if (current->course.courseNumber == courseNumber) {
            //if match found return current course
            return current->course;
        }
        else if (current->course.courseNumber > courseNumber) {
            // if course is smaller than current node then traverse left
            current = current->left;
        }
        else {
            // else larger so traverse right
            current = current->right;
        }
    }
    //if no course found returns empty course object
    Course course;
    return course;
}

//add a course 
void BinarySearchTree::addNode(Node* node, Course course) {
    // if node is larger then add to left
    if (node->course.courseNumber > course.courseNumber) {
        if (node->left == nullptr) {
            //if no left node this new course becomes new left
            node->left = new Node(course);
        }
        else {
            //otherwise recurse down left node
            this->addNode(node->left, course);
        }
    }
    else {
        if (node->right == nullptr) {
            //if no right node this new course becomes right
            node->right = new Node(course);
        }
        else {
            //otherwise recusively traverse down the right side
            this->addNode(node->right, course);
        }
    }
}