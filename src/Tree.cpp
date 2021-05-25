//
//  Tree.cpp
//  AlvTree
//
//  Created by RAIDEMOT on 18.05.2021.
//

#include "Tree.hpp"

template<typename T>
Tree<T>::Tree(){
    root = NULL;
}

template<typename T>
Tree<T>::~Tree() {}

template<typename T>
unsigned int Tree<T>::height(Node<T>* p) {
    return p?p->getHeight():0;
}

template<typename T>
int Tree<T>::balanceFactor(Node<T>* p) {
    return height(p->getPointerRightChild())-height(p->getPointerLeftChild());
}

template<typename T>
void Tree<T>::fixHeight(Node<T>* p) {
    unsigned int heightLeft = height(p->getPointerLeftChild());
    unsigned int heightRight = height(p->getPointerRightChild());
    p->setHeight((heightLeft > heightRight ? heightLeft : heightRight) + 1);
}

template<typename T>
Node<T>* Tree<T>::rightTurn(Node<T>* p) {
    Node<T>* q = p->getPointerLeftChild();
    
    p->setPointerLeftChild(q->getPointerRightChild());
    q->setPointerRightChild(p);
    fixHeight(p);
    fixHeight(q);
    return q;
}


template<typename T>
Node<T>* Tree<T>::leftTurn(Node<T>* q) {
    Node<T>* p = q->getPointerRightChild();
    
    q->setPointerRightChild(p->getPointerLeftChild());
    p->setPointerLeftChild(q);
    fixHeight(q);
    fixHeight(p);
    return p;
}

template<typename T>
Node<T>* Tree<T>::balance(Node<T>* p)
{
    fixHeight(p);
    if(balanceFactor(p) == 2)
    {
        if(balanceFactor(p->getPointerRightChild()) < 0)
            p->setPointerRightChild(rightTurn(p->getPointerRightChild()));
        return leftTurn(p);
    }
    if(balanceFactor(p) == -2)
    {
        if(balanceFactor(p->getPointerLeftChild()) > 0)
            p->setPointerLeftChild(leftTurn(p->getPointerLeftChild()));
        return rightTurn(p);
    }
    return p;
}

template<typename T>
Node<T>* Tree<T>::insert(Node<T>* p, T key)
{
    if(!root) return new Node<T>(key);
    
    if(!p) return new Node<T>(key);
    
    if(key < p->getKey())
        p->setPointerLeftChild(insert(p->getPointerLeftChild(),key));
    else
        p->setPointerRightChild(insert(p->getPointerRightChild(),key));
    return balance(p);

}

template<typename T>
void Tree<T>::insert(T key) {
    root = insert(root, key);
}

template<typename T>
T Tree<T>::seek(T key) {
    
    Node<T>* current = root;
    
    while(current != NULL) {
        if (key == current->getKey())
            return current->getKey();
        if (key < current->getKey())
            current = current->getPointerLeftChild();
        else
            current = current->getPointerRightChild();
    }
    
    return current->getKey();
}

template<typename T>
T Tree<T>::seekMinKey(Node<T>* p) const {
    Node<T>* current = p;
    while (current->getPointerLeftChild() != nullptr)
        current = current->getPointerLeftChild();
    return current->getKey();
}

template<typename T>
Node<T>* Tree<T>::seekMin(Node<T>* p) const {
    Node<T>* current = p;
    while (current->getPointerLeftChild() != nullptr)
        current = current->getPointerLeftChild();
    return current;
}

template<typename T>
Node<T>* Tree<T>::removemin(Node<T>* p)
{
    if(p->getPointerLeftChild() == 0)
        return p->getPointerRightChild();
    p->setPointerLeftChild(removemin(p->getPointerLeftChild()));
    return balance(p);
}

template<typename T>
Node<T>* Tree<T>::remove(Node<T> *p, T k) {
    if( !p ) return 0;
    if( k < p->getKey() )
        p->setPointerLeftChild(remove(p->getPointerLeftChild(),k));
    else if( k > p->getKey() )
        p->setPointerRightChild(remove(p->getPointerRightChild(),k));
    else
    {
        Node<T>* q = p->getPointerLeftChild();
        Node<T>* r = p->getPointerRightChild();
        delete p;
        if( !r ) return q;
        Node<T>* min = seekMin(r);
        min->setPointerRightChild(removemin(r));
        min->setPointerLeftChild(q);
        return balance(min);
    }
    return balance(p);
}

template<typename T>
Node<T>* Tree<T>::remove(T key) {
    root = remove(root, key);
}

template<typename T>
void Tree<T>::displayTree(){
    printTree(root, 0);
}

template<typename T>
void Tree<T>::printLevelOrder()
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printTree(root, i);
}

template<typename T>
void Tree<T>::printTree(Node<T>* ptr, int level){
    if (ptr == NULL)
        return;
    if (level == 1)
        std::cout << ptr->getKey() << " ";
    else if (level > 1)
    {
        printTree(ptr->getPointerLeftChild(), level-1);
        printTree(ptr->getPointerRightChild(), level-1);
    }
}

template<typename T>
Node<T>* Tree<T>::getRoot() {
    return root;
}
