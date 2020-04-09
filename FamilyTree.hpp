

#ifndef UNTITLED2_FAMILYTREE_H
#define UNTITLED2_FAMILYTREE_H

#include <iostream>

using namespace  std;
class Node{
public:

 string name;
 Node* father;
 Node* mather;

 Node(string name)
 {
     this->name = name;
     this->father = NULL;
     this->mather = NULL;

 };

};

namespace family {


    class Tree {

    public:
        Node *root;

        Tree(string name) {
            this->root = new Node(name);
        };

        void addFather( string,  string);

        void addMother(const string, const string);

        string relation(const string);

        string find(const string);

        void display();

        void remove(const string);


        Node *findthis(const string basicString, Node *pNode);
    };
}



#endif //UNTITLED2_FAMILYTREE_H
