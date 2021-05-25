//
//  main.cpp
//  AlvTree
//
//  Created by RAIDEMOT on 18.05.2021.
//

#include <iostream>
#include <ctime>
#include "Tree.cpp"

int main(int argc, const char * argv[]) {
    Tree<int> tree;
    
    int value;
    for (int i = 0; i < 10; i++) {
        value = i + rand() % 1320;
//        value = i;
        tree.insert(value);
        std::cout << value << " ";
    }
    
    tree.remove(967);
    
    std::cout << "\n\n\n";

//    std::cout << tree.seekMin(tree.getRoot()) << std::endl;
    tree.printLevelOrder();
    
    return 0;
}
