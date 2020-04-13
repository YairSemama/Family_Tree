#include "FamilyTree.hpp"
#include <iostream>
#include <string>
#include <cmath>
bool static check = false;
bool static check1 = false ;
using namespace family;
using namespace std ;

Tree& Tree::addFather( string child, string father) {
    if (this->root == NULL)
    {
        out_of_range{"The Family tree is Empty!"};
        return *this;
    }
    Node *temp = nullptr;
    findthis(child, this->root ,&temp);
    check = false ;
    if(temp == NULL)
    {
        out_of_range{"cannot fin.id this child!"};
        return *this;
    }
    if(temp != NULL)
    {
        temp->father = new Node(father);
        temp->father->height = temp->height+1 ;
        temp->father->sex = 1 ;
        this->size++;
        if(maxHeight < temp->father->height) maxHeight = temp->father->height;

    }
    check = false ;
    return *this;


}

Tree& Tree::addMother( string child, string mother) {
    if (this->root == NULL)
    {
        out_of_range{"The Family tree is Empty!"};
        return *this;
    }
    Node *temp = nullptr;
    findthis(child, this->root ,&temp);
    check = false ;
    if(temp == NULL)
    {
        out_of_range{"cannot fin.id this child!"};
        return *this;
    }
    if(temp != NULL)
    {
        temp->mother = new Node(mother);
        temp->mother->height = temp->height+1 ;
        temp->mother->sex = 2 ;
        this->size++;
        if(maxHeight < temp->mother->height) maxHeight = temp->mother->height;

    }
    check = false ;
    return *this;

}


string Tree::relation(const string name)
{
    Node *temp = nullptr;
    findthis(name, this->root ,&temp);
    check = false ;
    if(temp == NULL)
        return "unrelated" ;
    int height = temp->height;
    int sex = temp->sex ;
    check = false ;
    if(height == 0 ) return "me" ;
    if(sex == 1 && height == 1) return "father" ;
    if(sex == 2 && height == 1) return  "mother" ;
    if(sex == 1 && height == 2) return "grandfather" ;
    if(sex == 2 && height == 2) return  "grandmother" ;

    if(sex == 1 && height > 2)
    {
        string ans =  "grandfather" ;
        while(height != 2)
        {
            ans = "great-" + ans ;
            height--;
        }
        return ans ;
    }

    if(sex == 2 && height > 2)
    {
        string ans =  "grandmother" ;
        while(height != 2)
        {
            height--;
            ans = "great-" + ans ;
        }
        return ans ;
    }
    return "" ;
}

string Tree::find(const string reletion )
{
    int count = 0 ;
    int sex = 0 ;
    string granm = "grandmother";
    string granf = "grandfahter";
    if(reletion == "son")
    {
        count = 0;
        sex = 0;
        Node *tempnode = nullptr;
        findtheFamily(sex , count , root , &tempnode);
        check1 = false ;
        if(tempnode == nullptr) return "The tree cannot handle the " + reletion + " relation";
        return tempnode->name ;
    }
    if (reletion == "father")
    {
        count = 1;
        sex = 1 ;
    }
    if (reletion == "mother")
    {
        count = 1;
        sex = 2;
    }
    if (reletion == "grandfather")
    {
        count = 2;
        sex = 1;
    }
    if (reletion == "grandmother")
    {
        count = 2;
        sex = 2;
    }


     if(reletion.find("grandmother") > 4 )
     {

         size_t temp = reletion.find("grandmother") ;
         if(temp != string::npos)
         {
             temp = (temp) / 6;
             count = temp + 2;
             sex = 2;
         }
     }

     if(reletion.find("grandfather") > 4 )
    {
        size_t temp = reletion.find("grandfather") ;
        if(temp != string::npos)
        {
            temp = (temp) / 6;
            count = temp + 2;
            sex = 1;
        }
    }
     Node *tempnode = nullptr;
     findtheFamily(sex , count , root , &tempnode);
    check1 = false ;
    if((sex == 0 && count == 0) || tempnode == nullptr ) return "The tree cannot handle the " + reletion +" relation";
    return tempnode->name ;

}
void deleteFromTree(Node** node){
    if (*node == NULL) return;
    deleteFromTree(&(*(node))->mother);
    deleteFromTree(&(*(node))->father);
    *node = nullptr;
    delete *node;
}
void Tree::remove(const string name)
{
    Node *temp = nullptr;
    findthis(name, this->root ,&temp);
    check = false ;
    deleteFromTree(&temp);
    findthis(name, this->root ,&temp);
    if(this->root == temp)
    {
        this->root = nullptr;
        delete this->root;
    }
    temp = nullptr;
    delete temp;
}

void Tree::display()
{
    printTheTree(root);

}

void Tree::findthis(const string child, Node *root ,  Node** temp) {

    if(root == NULL) return;
    if(root->name == child && !check)
    {
      *temp = root  ;
      check = true ;
    }
    if(!check)
    {
        Tree::findthis(child , root->father , temp);
        Tree::findthis(child , root->mother , temp );
    }
}



void Tree::findtheFamily(int sex, int count, Node *root, Node **temp) {
    if(root == NULL) return;
    if(root->sex  == sex && root->height == count  )
    {
        *temp = root  ;
        check1 = true ;
    }
    if(!check1)
    {
        Tree::findtheFamily(sex ,count , root->father , temp);
        Tree::findtheFamily(sex ,count ,  root->mother , temp );
    }

}

void Tree::printTheTree(Node *root) {
    if(root == NULL) return;
    Tree::printTheTree( root->father);
    Tree::printTheTree(root->mother);

    string tree1 = "      /\\      \n"
                   "     /\\*\\     \n"
                   "    /\\O\\*\\    \n"
                   "   /*/\\/\\/\\   \n"
                   "  /\\O\\/\\*\\/\\  \n"
                   " /\\*\\/\\*\\/\\/\\ \n"
                   "/\\O\\/\\/*/\\/O/\\\n"
                   "      ||      \n"
                   "      ||      \n"
                   "      ||   " ;
    if(root->height == 0 )
    {
        cout << "Me : " << root->name << endl ;
        cout << tree1 << endl ;

    }
    if (root->sex == 1 && root ->height == 1)
    {
       cout << "father :" << root->name  << endl;
        cout << tree1 << endl ;

    }
    if (root->sex == 2 && root ->height == 1)
    {
        cout << "mother :" << root->name << endl;
        cout << tree1 << endl ;

    }
    if (root->sex == 1 && root ->height == 2)
    {
        cout << "grandfahter :" << root->name << endl ;
        cout << tree1 << endl ;

    }
    if (root->sex == 2 && root ->height == 2)
    {
        cout << "grandmother :" << root->name << endl ;
        cout << tree1 << endl ;
    }

    if(root->sex == 1 && root-> height > 2)
    {
        string temp = "great-" ;
        for (int i = 3; i < root->height ; ++i) {
           temp = temp + temp;
        }
        temp = temp + "grandfather :" + root->name;
        cout << temp << endl ;
        cout << tree1 << endl ;
    }

    if(root->sex == 2 && root-> height > 2)
    {
        string temp = "great-" ;
        for (int i = 3; i < root->height ; ++i) {
            temp = temp + temp;
        }
        temp = temp + "grandmother :" + root->name;
        cout << temp << endl ;
        cout << tree1 << endl ;

    }
}








