#include "FamilyTree.hpp"
#include <iostream>

using namespace family;

void family::Tree::addFather( string child, string father) {
    if (this->root == NULL)
    {
        out_of_range{"The Family tree is Empty!"};
        return;
    }
    Node *temp = findthis(child, this->root);
    if(temp == NULL)
    {
        out_of_range{"cannot find this child!"};
        return;
    }
    temp->father = new Node(father);
    return;


}

Node *Tree::findthis(const string child, Node *root) {
    if(root == NULL) return NULL;
    if(root->name == child)
    {
        return root;
    }
    findthis(child , root->father);
    findthis(child , root->mather);


    return nullptr;
}






