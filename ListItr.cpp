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

ListItr::ListItr(){
//Constructor
  
  current = NULL;
}


ListItr::ListItr(ListNode* theNode){	// One parameter constructor
    
  current = theNode;

}

//--------------------------------------_METHODS----------------------------
bool ListItr::isPastEnd() const{	//Returns true if past end position
    // in list, else false
  /* if(current->next == NULL)
  return true;
  else
    return false;
  */
  return this->current->next == NULL;
}
    
bool ListItr:: isPastBeginning() const{ //Returns true if past first position
    // in list, else false

  return this->current->previous == NULL;
}



void ListItr:: moveForward(){	//Advances current to next position in list
    //(unless already past end of list)
  if(this->isPastEnd() == false){
    this->current = current->next;}
     

}
  
void ListItr:: moveBackward(){	//Moves current back to previous position
    // in list (unless already past beginning of
    // list)
  if(this->isPastBeginning() == false)
    current = current->previous;

}
  
int ListItr::retrieve() const{	//Returns item in current position

  return current->value;
}
  
