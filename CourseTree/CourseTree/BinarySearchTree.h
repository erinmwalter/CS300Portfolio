#pragma once
#include "Node.cpp"


//binary tree 
class BinarySearchTree {

private:
    Node* root;

    void addNode(Node* node, Course course);
    void inOrder(Node* node);
    void destroy(Node* node);
    Node* removeNode(Node* node, string courseNumber);

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();
    void InOrder();
    void Insert(Course course);
    void Remove(string courseNumber);
    Course Search(string courseNumber);
};