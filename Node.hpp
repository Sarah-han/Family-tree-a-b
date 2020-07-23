// Node Header 
#pragma once

class node{
public:
    std::string name;
	node* father;
	node* mother;
	
public:	
	node(const std::string& str) : 
		name(str),
		father(nullptr),
		mother(nullptr) {};
	~node(){
		if(father != nullptr) delete father;
		if(mother != nullptr) delete mother;
	}
 	
	friend class tree;
		
};

