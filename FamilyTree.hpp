

#ifndef UNTITLED2_FAMILYTREE_H
#define UNTITLED2_FAMILYTREE_H
class Node{
public:

 char* name;
 Node* father;
 Node* mather;

};


class Tree{

public:
    Node root;
    Tree(Node);

    void addFather(const char[] , const char[]);

    void addMother(const char[] , const char[]);

    char* relation(const char[]);

    char* find(const char[]);

    void display();

    void remove(const char[]);

};



#endif //UNTITLED2_FAMILYTREE_H
