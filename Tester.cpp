
#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
using namespace std;

//Make sure your own files for the List and ListItr
//classes are included here.  These are the names I used.
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"

int main(){

  int some_num = 4;
  List* testList = new List;

  ListNode* node1 = new ListNode;
  ListNode* node2 = new ListNode;
  ListNode* node3 = new ListNode;
  ListNode* node4 = new ListNode;

  ListItr* iterator1 = new ListItr(node1);
  ListItr* iterator2 = new ListItr(node2);

  testList->insertAfter(5, * iterator1);
}
