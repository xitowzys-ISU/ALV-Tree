//
//  Node.hpp
//  AlvTree
//
//  Created by RAIDEMOT on 18.05.2021.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

template<typename T>
class Node {
private:
    T key;
    unsigned int height;
    Node* leftChild;
    Node* rightChild;
    
public:
    Node();
    Node(T key);
    ~Node();
    
    T getKey();
    Node* getPointerLeftChild();
    Node* getPointerRightChild();
    
    void setPointerLeftChild(Node* node);
    void setPointerRightChild(Node* node);
    
    unsigned int getHeight();
    void setHeight(unsigned int height);
};

#endif /* Node_hpp */
