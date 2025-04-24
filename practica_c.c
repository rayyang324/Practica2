#include "practica_c.h"

ListNode* toAddress(ListNode* head, int pos);
ListNode* reverseList(ListNode* list);

ListNode* reverse_range(ListNode* head, int left, int right)
{
    if (head == NULL || left >= right) return head;

    // Get relevant nodes
    ListNode* leftPrev = (left == 0) ? NULL : toAddress(head, left - 1);
    ListNode* leftStart = (leftPrev == NULL) ? head : leftPrev->next;
    ListNode* rightEnd = toAddress(head, right - 1);
    ListNode* rightNext = (rightEnd == NULL) ? NULL : rightEnd->next;

    if (leftStart == NULL || rightEnd == NULL) return head;

    // Disconnect the sublist to reverse
    rightEnd->next = NULL;

    // Reverse the sublist
    ListNode* reversedHead = reverseList(leftStart);

    // Reconnect left side
    if (leftPrev != NULL) {
        leftPrev->next = reversedHead;
    } else {
        head = reversedHead; // Reversal started from head
    }

    // Reconnect right side
    leftStart->next = rightNext;

    return head;
}

ListNode* toAddress(ListNode* head, int pos)
{
    ListNode* temp = head;
    for (int i = 0; i < pos; i++)
    {
        if (temp == NULL || temp->next == NULL) {
            return NULL;
        }
        temp = temp->next;
    }
    return temp;
}

ListNode* reverseList(ListNode* list)
{
    ListNode* prev = NULL;
    ListNode* cur = list;

    while (cur != NULL)
    {
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}
