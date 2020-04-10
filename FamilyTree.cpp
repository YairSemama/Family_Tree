#include "FamilyTree.hpp"
#include <iostream>
#include <string>
#define g "great"
bool static check = false;
bool static check1 = false ;
using namespace family;


void family::Tree::addFather( string child, string father) {
    if (this->root == NULL)
    {
        out_of_range{"The Family tree is Empty!"};
        return;
    }
    Node *temp = nullptr;
    findthis(child, this->root ,&temp);
    if(temp == NULL)
    {
        out_of_range{"cannot fin.id this child!"};
        return;
    }
    if(temp != NULL)
    {
        temp->father = new Node(father);
        temp->father->height = temp->height+1 ;
        temp->father->sex = 1 ;
        this->size++;


    }
    check = false ;



}

void family::Tree::addMother( string child, string mother) {
    if (this->root == NULL)
    {
        out_of_range{"The Family tree is Empty!"};
        return;
    }
    Node *temp = nullptr;
    findthis(child, this->root ,&temp);
    if(temp == NULL)
    {
        out_of_range{"cannot fin.id this child!"};
        return;
    }
    if(temp != NULL)
    {
        temp->mother = new Node(mother);
        temp->mother->height = temp->height+1 ;
        temp->mother->sex = 2 ;
        this->size++;

    }
    check = false ;


}


string Tree::relation(const string name)
{
    Node *temp = nullptr;
    findthis(name, this->root ,&temp);
    int height = temp->height;
    int sex = temp->sex ;

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



}

string Tree::find(const string reletion )
{
    int count = 0 ;
    int sex = 0 ;
    string granm = "grandmother";
    string granf = "grandfahter";

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
    if(tempnode == NULL) return "" ;
    return tempnode->name ;

}

void Tree::remove(const string name)
{
    Node *temp = nullptr;
    findthis(name, this->root ,&temp);
    delete(temp);
}

void Tree::display()
{
int MaxHeight = Max(root , this->size);
}

void Tree::findthis(const string child, Node *root ,  Node** temp) {

    if(root == NULL) return;
    if(root->name == child && !check )
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
        check = true ;
    }
    if(!check)
    {
        Tree::findtheFamily(sex ,count , root->father , temp);
        Tree::findtheFamily(sex ,count ,  root->mother , temp );
    }

}

int Tree::Max(Node *root  , int size) {
    static int count = 0 ;
    static int maxvalue = 0 ;
    if(root != NULL) count++ ;
    if(maxvalue < root->height)
    {
        maxvalue = root->height ;
    }
    if(count) return maxvalue;
    Tree::Max(root->father , size);
    Tree::Max(root->mother , size);
}






