//
//  Node.cpp
//  AlvTree
//
//  Created by RAIDEMOT on 18.05.2021.
//

#include "Node.hpp"

template<typename T>
Node<T>::Node(){
    leftChild = NULL;
    rightChild = NULL;
    height = 1;
}

template<typename T>
Node<T>::Node(T key) {
    this->key = key;
    leftChild = NULL;
    rightChild = NULL;
    height = 1;
}

template<typename T>
T Node<T>::getKey() {
    return key;
}

template<typename T>
unsigned int Node<T>::getHeight() {
    return height;
}

template<typename T>
void Node<T>::setHeight(unsigned int height) {
    this->height = height;
}

template<typename T>
Node<T>* Node<T>::getPointerLeftChild() {
    return leftChild;
}

template<typename T>
void Node<T>::setPointerLeftChild(Node<T> *node) {
    leftChild = node;
}

template<typename T>
Node<T>* Node<T>::getPointerRightChild() {
    return rightChild;
}

template<typename T>
void Node<T>::setPointerRightChild(Node<T> *node) {
    rightChild = node;
}

template<typename T>
Node<T>::~Node(){};
