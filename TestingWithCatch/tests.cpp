#include <iostream>
#include <string>
#include "catch.hpp"
#include "FzList.hpp"

using namespace std;



TEST_CASE("FZ Node", "[NODE]") {

   SECTION("Initialize"){
      FzNode *node = new FzNode(1, nullptr);

      REQUIRE(node->getData() == 1);
      REQUIRE(node->getNext() == nullptr);
   }

   SECTION("Link Multiple"){
      FzNode *beginning = new FzNode(1, nullptr);
      beginning->setNext( new FzNode(2, nullptr));
      beginning->getNext()->setNext(new FzNode(3, nullptr));

      REQUIRE(beginning->getData() == 1);
      REQUIRE(beginning->getNext()->getData() == 2);
      REQUIRE(beginning->getNext()->getNext()->getData() == 3);
      REQUIRE(beginning->getNext()->getNext()->getNext() == nullptr); 
   }
}

TEST_CASE("My LinkedList", "[LINKED LIST]") {

    SECTION("Empty List"){
        string a = "foo";
        string b = "foo";
        REQUIRE(a == b);
    }

    SECTION("Test push back"){
       FzList *list = new FzList();
       list->push_back(1);
       list->push_back(2);
       list->push_back(3);
      
       REQUIRE(list->find(1) == 0);
       REQUIRE(list->find(2) == 1);
       REQUIRE(list->find(3) == 2);
       REQUIRE(list->find(-1) == -1);
       REQUIRE(list->find(4) == -1);
    }
}
