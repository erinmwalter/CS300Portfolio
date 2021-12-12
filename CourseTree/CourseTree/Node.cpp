#include "Course.cpp"

//structure for nodes in binary tree
struct Node {
    Course course;
    Node* left;
    Node* right;


    // default constructor
    Node() {
        left = nullptr;
        right = nullptr;
    }

    //overloaded constructor initialized with course
    Node(Course aCourse) : Node() {
        this->course = aCourse;
    }


};