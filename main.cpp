#include <iostream>
#include "FamilyTree.cpp"

using namespace std;
int main() {
    string yosef = "yosef";
    string tov = "tov";
    string yes = "yes";
    family::Tree T(yosef);
    T.addFather(yosef,tov);
    T.addFather(tov,yes);
    T.addMother(yosef , "shif");
    T.addMother(yes , "shlof");
    T.addMother(yes ,"the" );

    cout << T.Max(T.root, T.size);



    return 0;
}
