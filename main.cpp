#include <iostream>
#include "FamilyTree.hpp"

using namespace std;
int main() {
    family::Tree T("yosef");
    T.addFather("yosef","tov");
    T.addFather("tov","yes");


    string t = T.root->father->father->name;
    cout << t ;
    return 0;
}
