#ifndef FZLIST_HPP
#define FZLIST_HPP

#include <iostream>

using namespace std;

class FzNode{
 
private: 
  int Data;
  FzNode *Next;
  
public:
  FzNode(){
    Data = 0;
    Next = nullptr;
  }

  FzNode(int data, FzNode *next){
     this->Data = data;
     this->Next = next;
  }

  FzNode(const FzNode &other){
    this->Data = other.Data;
    this->Next = other.Next;
  }

  FzNode& operator=(const FzNode& other){
     this->Data = other.Data;
     this->Next = other.Next;
     return *this;
  }

  
  void setData(int data){ 
      this->Data = data;
  }

  void setNext(FzNode *next){ 
     this->Next = next;
  }

  int getData() const { 
    return this->Data;
  }  

  FzNode* getNext() const{
    return this->Next;
  }
};

class FzList{

private:
    FzNode *beginning;
public:
    FzList(){
       beginning = nullptr; 
    }

    ~FzList()
    { 
         //TODO destroy and test
    }

    void push_back(int item){
        if(beginning == nullptr){
           beginning = new FzNode(item, nullptr);
        }      
        else{
          
          FzNode* current = beginning;

          while(current->getNext() != nullptr){
           
             current = current->getNext();
         }
         current->setNext(new FzNode(item, nullptr));
       } 
    }

    int size(){
       return 0;
    }

    //returns index or -1 if not found
    int find(int target){

       if(beginning == nullptr) return -1;

       FzNode* current = beginning;
       int index = -1;

       while(current != nullptr){ 
         index++;
         if(current->getData() == target){
           return index;
         } 
         current = current->getNext();
       }

       return -1;
    }  
};

#endif


