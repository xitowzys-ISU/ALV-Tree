//
//  Tree.hpp
//  AlvTree
//
//  Created by RAIDEMOT on 18.05.2021.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include <iomanip>
#include <iostream>
#include "Node.cpp"

template<typename T>
class Tree {
private:
    Node<T>* root;
    
    unsigned int height(Node<T>* p);
    int balanceFactor(Node<T>* p);
    void fixHeight(Node<T>* p);
    
    Node<T>* rightTurn(Node<T>* p);
    Node<T>* leftTurn(Node<T>* q);
    Node<T>* balance(Node<T>* p);
    Node<T>* insert(Node<T>* p, T key);
    
    Node<T>* remove(Node<T>* p, T key);
    
    void printTree(Node<T>* ptr, int level);
    
public:
    Tree();
    ~Tree();
    
    void insert(T key);
    
    T seek(T key);
    T seekMin(Node<T>* p) const;
    
    Node<T>* remove(T key);
    void displayTree();
    void printLevelOrder();
    
    Node<T>* getRoot();
    
};

#endif /* Tree_hpp */
