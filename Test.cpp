#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
#include <iostream>

using namespace family;
using namespace std;


TEST_CASE ("ADD FATHER") {
    Tree test("uriel");
    test.addFather("uriel", "shimon");
    Tree test2("Yosef"); // Yosef is the "root" of the tree (the youngest person).
    test2.addFather("Yosef", "Yaakov");   // Tells the tree that the father of Yosef is Yaakov.
    test2.addFather("Yaakov", "shlof");
    test2.addFather("shlof", "yFather");
    test2.addFather("yFather", "1Father");
    test2.addFather("1Father", "2Father");
    test2.addFather("2Father", "3Father");
    test2.addFather("3Father", "4Father");
    test.addFather("shimon", "tt");
    test.addFather("tt", "tt2");
    test.addFather("tt2", "tt3");


            CHECK(test.relation("tt") == string("grandfather"));
            CHECK(test.relation("tt2") == string("great-grandfather"));
            CHECK(test.relation("tt3") == string("great-great-grandfather"));
            CHECK(test.relation("shimon") == string("father"));
            CHECK(test2.relation("Yaakov") == string("father"));
            CHECK(test2.relation("shlof") == string("grandfather"));
            CHECK(test2.relation("yFather") == string("great-grandfather"));
            CHECK(test2.relation("1Father") == string("great-great-grandfather"));
            CHECK(test2.relation("2Father") == string("great-great-great-grandfather"));
            CHECK(test2.relation("3Father") == string("great-great-great-great-grandfather"));
            CHECK(test2.relation("4Father") == string("great-great-great-great-great-grandfather"));
            CHECK(test.find("father") == string("shimon"));
            CHECK(test2.find("father") == string("Yaakov"));
            CHECK(test2.find("grandfather") == string("shlof"));
            CHECK(test2.find("great-grandfather") == string("yFather"));
            CHECK(test2.find("great-great-grandfather") == string("1Father"));
            CHECK(test2.find("great-great-great-grandfather") == string("2Father"));
            CHECK(test2.find("great-great-great-great-grandfather") == string("3Father"));
            CHECK(test2.find("great-great-great-great-great-grandfather") == string("4Father"));

}



TEST_CASE ("ADD MOTHER") {
    Tree test("uriel");
    test.addMother("uriel", "shimon");
    Tree test2("Yosef");
    test2.addMother("Yosef", "Yaakov");
    test2.addMother("Yaakov", "shlof");
    test2.addMother("shlof", "yFather");
    test2.addMother("yFather", "1Father");
    test2.addMother("1Father", "2Father");
    test2.addMother("2Father", "3Father");
    test2.addMother("3Father", "4Father");
    test.addMother("shimon", "tt");
    test.addMother("tt", "tt2");
    test.addMother("tt2", "tt3");


            CHECK(test.relation("tt") == string("grandmother"));
            CHECK(test.relation("tt2") == string("great-grandmother"));
            CHECK(test.relation("tt3") == string("great-great-grandmother"));
            CHECK(test.relation("shimon") == string("mother"));
            CHECK(test2.relation("Yaakov") == string("mother"));
            CHECK(test2.relation("shlof") == string("grandmother"));
            CHECK(test2.relation("yFather") == string("great-grandmother"));
            CHECK(test2.relation("1Father") == string("great-great-grandmother"));
            CHECK(test2.relation("2Father") == string("great-great-great-grandmother"));
            CHECK(test2.relation("3Father") == string("great-great-great-great-grandmother"));
            CHECK(test2.relation("4Father") == string("great-great-great-great-great-grandmother"));
            CHECK(test.find("mother") == string("shimon"));
            CHECK(test2.find("mother") == string("Yaakov"));
            CHECK(test2.find("grandmother") == string("shlof"));
            CHECK(test2.find("great-grandmother") == string("yFather"));
            CHECK(test2.find("great-great-grandmother") == string("1Father"));
            CHECK(test2.find("great-great-great-grandmother") == string("2Father"));
            CHECK(test2.find("great-great-great-great-grandmother") == string("3Father"));
            CHECK(test2.find("great-great-great-great-great-grandmother") == string("4Father"));

}



TEST_CASE ("RELETION") {
    Tree test("uriel");
    test.addMother("uriel", "shimon");
    Tree test2("Yosef");
    test2.addMother("Yosef", "Yaakov");
    test2.addMother("Yaakov", "shlof");
    test2.addMother("shlof", "yFather");
    test2.addMother("yFather", "1Father");
    test2.addMother("1Father", "2Father");
    test2.addMother("2Father", "3Father");
    test2.addMother("3Father", "4Father");
    test.addMother("shimon", "tt");
    test.addMother("tt", "tt2");
    test.addMother("tt2", "tt3");


            CHECK(test.relation("tt") == string("grandmother"));
            CHECK(test.relation("tt2") == string("great-grandmother"));
            CHECK(test.relation("tt3") == string("great-great-grandmother"));
            CHECK(test.relation("shimon") == string("mother"));
            CHECK(test2.relation("Yaakov") == string("mother"));
            CHECK(test2.relation("shlof") == string("grandmother"));
            CHECK(test2.relation("yFather") == string("great-grandmother"));
            CHECK(test2.relation("1Father") == string("great-great-grandmother"));
            CHECK(test2.relation("2Father") == string("great-great-great-grandmother"));
            CHECK(test2.relation("3Father") == string("great-great-great-great-grandmother"));
            CHECK(test2.relation("4Father") == string("great-great-great-great-great-grandmother"));
            CHECK(test.relation("1") == string("unrelated"));
            CHECK(test2.relation("yaakov") == string("unrelated"));
            CHECK(test2.relation("1father") == string("unrelated"));
            CHECK(test2.relation("4") == string("unrelated"));
            CHECK(test2.relation("2father") == string("unrelated"));
            CHECK(test2.relation("6") == string("unrelated"));
            CHECK(test2.relation("7mother") == string("unrelated"));
            CHECK(test2.relation("8") == string("unrelated"));

}