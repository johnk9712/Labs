#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
using namespace std;

//Make sure your own files for the List and ListItr
//classes are included here.  These are the names I used.
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"

List::List(){
  //default constructor, create a head and tail node
  head = new ListNode;
  tail = new ListNode;

  //make the head point to the memory of tail and vice versa
  head->next = tail;
  tail->previous = head;

  head->previous = NULL; //head node should have no previous
  tail->next = NULL; //tail node should have no next
  
}


List::~List(){
  //deconstructor, get rid of two nodes once done
  delete head;
  delete tail;
  
}

//List::List(const List& source){

//}

//List& List::operator = (const List& source){
//if not same then add starting from the head node

//}  




bool List::isEmpty() const{
  //Returns true if empty; else false
  return (count == 0); 

}

//---------------------------------------------------------------------
void List::makeEmpty(){
//Removes all items except blank head and tail
 
  while(this->isEmpty() == false){
    this->remove(last().retrieve());
  
  }

}

//---------------------------------------------------------------------

ListItr List::first(){
//Returns an iterator that points to the ListNode in the first position
  ListItr* iterator = new ListItr(this->head->next);
  while(iterator->isPastBeginning() != true){
    iterator->moveBackward();
  }
  return *iterator;
}

//---------------------------------------------------------------------

ListItr List::last(){
//Returns an iterator that points to the ListNode in the last position
  ListItr* iterator = new ListItr(head->next);
  while(iterator->isPastEnd() != true){
    iterator->moveForward();
  }
  return *iterator;
}

//---------------------------------------------------------------------
void List::insertAfter(int x, ListItr position){
//Inserts x after current iterator position p

  ListNode* new_node = new ListNode();
  ListItr* iterator = new ListItr(position);

  new_node->value = x;
  iterator->current->next = new_node;
  count += 1;
}

//---------------------------------------------------------------------
void List::insertBefore(int x, ListItr position){
 //Inserts x before current iterator position p
  
  ListNode* new_node = new ListNode();
  ListItr* iterator = new ListItr(position);

  new_node->value = x;
  iterator->current->previous = new_node;
  count += 1;
}

//---------------------------------------------------------------------
void  List::insertAtTail(int x){
 //Insert x at tail of list
  tail->value = x;
  count +=1;
}

//---------------------------------------------------------------------
void List::remove(int x){
//Removes the first occurrence of x
  ListItr* iterator = new ListItr(head);
  
  while(iterator->retrieve() != x){
    iterator->moveForward();
  }

  iterator->current = NULL;

  count -= 1;
}

//---------------------------------------------------------------------
ListItr List::find(int x){	//Returns an iterator that points to
    // the first occurrence of x, else return a iterator to the dummy tail node
  
  ListItr* iterator = new ListItr(head);
  
  while(iterator->retrieve() != x){
    if(iterator->isPastBeginning() == false)
      iterator->moveForward();
    else if (iterator->isPastBeginning() == true)
      break;
  }

  return *iterator;

  
}

//---------------------------------------------------------------------
int List::size() const{
//Returns the number of elements in the list

  ListItr* iterator = new ListItr(head);
  int size = 0;
  
  while(iterator->isPastEnd() != true){
    size += 1;
    iterator->moveForward();
  }

  return size;
}

