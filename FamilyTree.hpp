#pragma once

#include<iostream>
#include <string>
#include <stack> // std::stack

#include "Node.hpp"


using namespace std;


namespace family{
class Tree{
private:
    node* root;

public:
    Tree(std::string name);
    Tree& addFather(std::string childName, std::string fatherName);
    Tree& addMother(std::string childName, std::string motherName);
    std::string relation(std::string relation);
    std::string find(std::string name);
    void display();
    void remove(std::string name);
private:
    node* nameToNode(node* node,std::string name);
    void printTree(node *root, int space);
    void postOrderToStack(std::stack<node*>& st);
    void deleteTree(node *&node, string &name,bool &flag);

};

}



