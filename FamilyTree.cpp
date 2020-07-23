#include "FamilyTree.hpp"

using namespace family;

Tree::Tree(std::string name)
{
    root = new node(name);
}

Tree &Tree::addFather(std::string childName, std::string fatherName)
{
    node* curr = nameToNode(root, childName);
    if (!curr)
    {
        throw std::runtime_error("ERR: No such child named: " + childName + " in the tree");
    }
    if (!curr->father)
    {
        curr->father = new node(fatherName);
    }
    else
    {
        throw std::runtime_error("ERR: Child named: " + childName + " already has a father");
    }
    return *this;
}

Tree &Tree::addMother(std::string childName, std::string motherName)
{
    node *curr = nameToNode(root, childName);
    if (!curr)
    {
        throw std::runtime_error("ERR: No such child named: '" + childName + "' in the tree");
    }

    if (!curr->mother)
    {
        curr->mother = new node(motherName);
    }
    else
    {
        throw std::runtime_error("ERR: Child named: " + childName + " already has a mother");
    }
    return *this;
}

// Iterative function to perform post-order traversal of the tree
std::string Tree::relation(std::string name)
{
    if (root->name == name)
    {
        return "me";
    }

    std::stack<node*> stack;
    postOrderToStack(stack);

    if (stack.empty())
    {
        throw std::runtime_error("ERR: The tree is empty");
    }

    node *temp = stack.top();
    // find the node in stack
    while (!stack.empty() && temp->name != name)
    {
        temp = stack.top();
        stack.pop();
    }

    if (temp->name != name)
    {
        return "unrelated";
    }

    node* relation_node = temp; // represent the relative
    int sex = 0;                // represent the sex of the relation_node -1:Mother 0:null 1:father
    int generation = 1;

    while (!stack.empty())
    {
        temp = stack.top();

        if (temp->mother == relation_node && sex == 0)
        {
            sex = -1;
            relation_node = temp;
            generation++;
        }
        else if (temp->father == relation_node && sex == 0)
        {
            sex = 1;
            relation_node = temp;
            generation++;
        }
        else if (temp->mother == relation_node || temp->father == relation_node)
        {
            relation_node = temp;
            generation++;
        }

        stack.pop();
    }

    std::string ans;
    if (sex == -1)
    {
        if (generation == 2)
        {
            ans = "mother";
        }
        else
        {
            ans = "grandmother";
        }
    }
    else if (sex == 1)
    {
        if (generation == 2)
        {
            ans = "father";
        }
        else
        {
            ans = "grandfather";
        }
    }

    generation--;

    while (generation > 2)
    {
        ans = "great-" + ans;
        generation--;
    }

    // cout << "sex: " + std::to_std::string(sex) << endl;
    // cout << "generation: " + std::to_std::string(generation) << endl;

    return ans;
}

void Tree::postOrderToStack(std::stack<node*>& out)
{
    // create an empty stack and push root node
    std::stack<node*> stk;
    stk.push(root);

    // create another stack to store post-order traversal
    // run till stack is not empty
    while (!stk.empty())
    {
        // we pop a node from the stack and push the data to output stack
        node *curr = stk.top();
        stk.pop();

        out.push(curr);

        // push left and right child of popped node to the stack
        if (curr->mother)
            stk.push(curr->mother);

        if (curr->father)
            stk.push(curr->father);
    }
}

std::string Tree::find(std::string relation)
{
    std::stack<node*> s;
    Tree::postOrderToStack(s);

    while (!s.empty())
    {
        node *temp = s.top();
        std::string str;
        str = Tree::relation(temp->name);

        if (str == relation)
        {
            return temp->name;
        }
        s.pop();
    }

    throw std::runtime_error("No such relation '" + relation + "' in the tree");
}

void Tree::display() { printTree(root, 0); }

void Tree::remove(std::string name)
{
    if (root->name == name)
        throw std::runtime_error("Can't remove the root of tree");

    stack<node *> stack;
    postOrderToStack(stack);

    if (stack.empty())
        throw std::runtime_error("ERR: No such child named: " + name + " in the tree");

    node *node;  

    while (!stack.empty())
    {
        node = stack.top();
        if (node->father != nullptr && node->father->name == name)
        {   
            delete node->father;
            node->father = nullptr;
            return;
        }
        if (node->mother != nullptr && node->mother->name == name)
        {
            delete node->mother;
            node->mother = nullptr;
            return;
        }
        stack.pop();
    }

    throw std::runtime_error("ERR: No such child named: " + name + " in the tree");
}

//given a @std::string name return the associate node
node* Tree::nameToNode(node *root, std::string name)
{
    // create an empty stack
    std::stack<node *> stack;
    postOrderToStack(stack);
    node *curr;

    while (!stack.empty())
    {
        curr = stack.top();
        if (curr->name == name)
        {
            return curr;
        }
        stack.pop();
    }
    return nullptr;
}

// Recursive function to print binary tree
// It uses inorder traversal
void Tree::printTree(node *root, int space)
{
    const int COUNT = 2;
    if (root == NULL)
        return;
    space += COUNT;
    printTree(root->mother, space);
    for (int i = COUNT; i < space; i++)
        std::cout << "\t";
    std::cout << root->name << "\n";
    printTree(root->father, space);
}
