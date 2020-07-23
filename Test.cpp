/**
 * AUTHORS: <Raphael Gozlan, Sarah Hananayev>
 * 
 *TODO add throw test
 *
 *
 * Date: 2020-02
 */

#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;

#include <string>
using namespace std;

static Tree tree("a");

// SARAH - Make about 30 more of them
TEST_CASE("TEST FOR BUILDING TREE AND DISPLAY FUNCTION"){  
    // CHECK_NOTHROW - should work
    CHECK_NOTHROW(tree.addFather("a","c"));
    CHECK_NOTHROW(tree.addMother("a","b"));   

    CHECK_NOTHROW(tree.addFather("c","g"));
    CHECK_NOTHROW(tree.addMother("c","f"));  

    CHECK_NOTHROW(tree.addFather("b","e"));
    CHECK_NOTHROW(tree.addMother("b","d"));

    CHECK_NOTHROW(tree.addFather("g","p"));
    CHECK_NOTHROW(tree.addMother("g","h"));

    CHECK_NOTHROW(tree.addFather("f","m"));
    CHECK_NOTHROW(tree.addMother("f","l"));

    CHECK_NOTHROW(tree.addFather("e","k"));
    CHECK_NOTHROW(tree.addMother("e","j"));

    CHECK_NOTHROW(tree.addFather("d","i"));
    CHECK_NOTHROW(tree.addMother("d","n"));

    CHECK_NOTHROW(tree.addMother("n","q"));

    CHECK_NOTHROW(tree.addFather("j","r"));

    CHECK_NOTHROW(tree.addMother("r","u"));

    CHECK_NOTHROW(tree.addMother("l","s"));

    CHECK_NOTHROW(tree.addFather("s","t"));

    

    // CHECK_THROWS - shouldn work 
    CHECK_THROWS(tree.addFather("z","t"));
    CHECK_THROWS(tree.addFather("x","k"));
    CHECK_THROWS(tree.addMother("w","l"));
    CHECK_THROWS(tree.addFather("y","f"));
    CHECK_THROWS(tree.addMother("z","d"));
    CHECK_THROWS(tree.addFather("x","a"));
    CHECK_THROWS(tree.addMother("w","q"));
    CHECK_THROWS(tree.addMother("y","h"));	

    // display at the end
    CHECK_NOTHROW(tree.display());
    
}

// SARAH - Make test for all the tree and add some throw check
TEST_CASE("TEST FOR FUNCTION RELATION") {
    //1st generation
    CHECK(tree.relation("b") == string("mother"));
    CHECK(tree.relation("c") == string("father"));
    //2nd generation
    CHECK(tree.relation("d") == string("grandmother"));
    CHECK(tree.relation("e") == string("grandfather"));
    CHECK(tree.relation("f") == string("grandmother"));
    CHECK(tree.relation("g") == string("grandfather"));
    //3rd generation 
    CHECK(tree.relation("h") == string("great-grandmother"));
    CHECK(tree.relation("i") == string("great-grandfather"));
    CHECK(tree.relation("j") == string("great-grandmother"));
    CHECK(tree.relation("k") == string("great-grandfather"));
	CHECK(tree.relation("l") == string("great-grandmother"));
    CHECK(tree.relation("m") == string("great-grandfather"));
    CHECK(tree.relation("n") == string("great-grandmother"));
    CHECK(tree.relation("p") == string("great-grandfather"));
    //4th generation
    CHECK(tree.relation("q") == string("great-great-grandmother"));
	CHECK(tree.relation("r") == string("great-great-grandfather"));
	CHECK(tree.relation("s") == string("great-great-grandmother"));
	//5th generation
	CHECK(tree.relation("u") == string("great-great-great-grandmother"));
	CHECK(tree.relation("t") == string("great-great-great-grandfather"));
}


// SARAH - Make test for all the tree and add some throw check
TEST_CASE("TEST FOR FUNCTION FIND"){
    //1st generation
    CHECK(string("b") == tree.find("mother"));
    CHECK(string("c") == tree.find("father"));
    //2nd generation
    CHECK(string("d") == tree.find("grandmother"));
    CHECK(string("e") == tree.find("grandfather"));
    CHECK(string("f") == tree.find("grandmother"));
    CHECK(string("g") == tree.find("grandfather"));
    //3rd generation 
    CHECK(string("h") == tree.find("great-grandmother"));
    CHECK(string("i") == tree.find("great-grandfather"));
    CHECK(string("j") == tree.find("great-grandmother"));
    CHECK(string("k") == tree.find("great-grandfather"));
	CHECK(string("l") == tree.find("great-grandmother"));
    CHECK(string("m") == tree.find("great-grandfather"));
    CHECK(string("n") == tree.find("great-grandmother"));
    CHECK(string("p") == tree.find("great-grandfather"));
    //4th generation
    CHECK(string("q") == tree.find("great-great-grandfather"));
	CHECK(string("r") == tree.find("great-great-grandmother"));
	CHECK(string("s") == tree.find("great-great-grandfather"));
	//5th generation
    CHECK(string("t") == tree.find("great-great-grandfather"));
	CHECK(string("u") == tree.find("great-great-grandmother"));
}

// SARAH - Make test for all the tree and add some throw check
TEST_CASE("TEST FOR FUNCTION REMOVE"){
    //remove single nodes
    // CHECK_NOTHROW(tree.remove("u"));
    // CHECK_NOTHROW(tree.remove("t"));
    // CHECK_NOTHROW(tree.remove("r"));
    // CHECK_NOTHROW(tree.remove("s"));
    // CHECK_NOTHROW(tree.remove("q"));
    // CHECK_NOTHROW(tree.remove("h"));
	// CHECK_NOTHROW(tree.remove("i"));
    // CHECK_NOTHROW(tree.remove("j"));
    // CHECK_NOTHROW(tree.remove("k"));
    // CHECK_NOTHROW(tree.remove("l"));
    // CHECK_NOTHROW(tree.remove("m"));
    // CHECK_NOTHROW(tree.remove("n"));
	// CHECK_NOTHROW(tree.remove("p"));
    // CHECK_NOTHROW(tree.remove("d"));
    // CHECK_NOTHROW(tree.remove("e"));
    // CHECK_NOTHROW(tree.remove("f"));
    // CHECK_NOTHROW(tree.remove("g"));
    // CHECK_NOTHROW(tree.remove("b"));
	// CHECK_NOTHROW(tree.remove("c"));
    CHECK_NOTHROW(tree.remove("a"));
   
	

    // // remove entire sub trees
	// CHECK_NOTHROW(tree.remove("t")); // should delete "t".
	// CHECK_NOTHROW(tree.remove("u")); // should delete "u".
	// CHECK_NOTHROW(tree.remove("r")); // should delete "r","u".
	// CHECK_NOTHROW(tree.remove("s")); // should delete "s"."t".
	// CHECK_NOTHROW(tree.remove("q")); // should delete "q".
    // CHECK_NOTHROW(tree.remove("h")); // should delete "h","q".
    // CHECK_NOTHROW(tree.remove("i")); // should delete "i".
	// CHECK_NOTHROW(tree.remove("j")); // should delete "j","r","u".
	// CHECK_NOTHROW(tree.remove("k")); // should delete "k".
	// CHECK_NOTHROW(tree.remove("l")); // should delete "l","s","t".
	// CHECK_NOTHROW(tree.remove("m")); // should delete "m".    
	// CHECK_NOTHROW(tree.remove("n")); // should delete "n".
	// CHECK_NOTHROW(tree.remove("p")); // should delete "p".
	// CHECK_NOTHROW(tree.remove("d")); // should delete "d","h","i","q".
	// CHECK_NOTHROW(tree.remove("e")); // should delete "e","j","k","r","u".
	// CHECK_NOTHROW(tree.remove("f")); // should delete "f","l","m","s","t".
	// CHECK_NOTHROW(tree.remove("g")); // should delete "g","n","p".
    // CHECK_NOTHROW(tree.remove("b")); // should delete "b","d","e","h","i","j","k","q","r","u".
    // CHECK_NOTHROW(tree.remove("c")); // should delete "c","f","g","l","m","n","p","s","t".
	// CHECK_NOTHROW(tree.remove("a")); // should delete "a","b","c","d","e","f","g","h","i","j","k","l","m","n","p","q","r","s","t","u".
	
}



