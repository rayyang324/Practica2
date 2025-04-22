// MODIFY ONLY THIS FILE
// Fill in the function following the instructions in the README

#include "practica_c.h"

ListNode* toAddress(ListNode*, int);
ListNode* reverseList(ListNode*);

ListNode *reverse_range(ListNode *head, int left, int right)
{
  //save right state
  ListNode* rightAdd = toAddress(head, right - 1);
  //save left state
  ListNode* leftAdd = toAddress(head, left);

  ListNode* leftConnect = toAddress(head, left - 1);
  ListNode* rightConnect = toAddress(head, right);

  leftConnect->next = rightAdd;
  rightAdd->next = NULL;

  rightAdd = reverseList(leftAdd);

  if (rightAdd == NULL)
  {
    leftConnect->next = rightConnect;
    return head;
  }
  ListNode* temp = rightAdd;

  while(temp->next != NULL)
  {
    temp = temp->next;
  }
  if (left == 0)
  {
    leftConnect->next = rightConnect;
  }
  leftConnect->next = rightAdd;
  temp->next = rightConnect;


  return head;
}

ListNode* toAddress(ListNode* head, int pos)
{
  for (int i = 0; i < pos; i++)
  {
    if (head->next == NULL) {return NULL;}
    head = head->next;
  }
  return head;
}

ListNode* reverseList(ListNode* list)
{
  if (list == NULL)
  {
    return NULL;
  }
  else if (list->next == NULL)
  {
    return list;
  }

  ListNode* prev = NULL;
  ListNode* cur = list;
  ListNode* nextSave = list->next;

  while(nextSave->next != NULL)
  {
    cur->next = prev;
    prev = cur;
    nextSave = nextSave->next;
  }
  cur->next = prev;
  nextSave->next = cur;
  return nextSave;
}



