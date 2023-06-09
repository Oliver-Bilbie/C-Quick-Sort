#include <stdbool.h>
#include "linked_list/linked_list.c"

// Asks the user for a list of values to sort.
// The values will be stored as a linked list, and a pointer to the head
// of this list will be returned.
struct node* getValues() {
  struct node *head = NULL;
  int value;
  bool complete = false;
  
  printf("Enter a list of integers, one per line, followed by ctrl-d:\n");
  do {
    if (scanf("%d", &value) == 1) {
      head = prependLinkedList(head, value);
    } else {
      complete = true; 
    }
    
  }
  while (complete == false);

  return head;
}

// Sorts a linked list using the quicksort algorithm.
// Requires a pointer to the head of the list to be sorted.
// Returns a pointer to the head of the sorted list.
struct node* quicksort(struct node *firstNode) {
  if (firstNode != NULL) {
    if (firstNode->next != NULL) {
      struct node *pivot = prependLinkedList(NULL, firstNode->value);
      struct node *current = firstNode->next;
      struct node *left = NULL;
      struct node *right = NULL;      

      while (current != NULL) {
        if (current->value < pivot->value) {
          left = prependLinkedList(left, current->value);
        } else {
          right = prependLinkedList(right, current->value);
        } 
        current = current->next;
      }
      
      cleanupLinkedList(firstNode);

      left = quicksort(left);
      right = quicksort(right);

      left = joinLinkedLists(left, pivot);
      left = joinLinkedLists(left, right);

      firstNode = left;
    }
  }

  return firstNode;
}

int main () {
  struct node* head = getValues();
  if (head == NULL) {
    printf("No values entered.\n");
    return 0;
  }
  
  head = quicksort(head);
  printLinkedList(head);
  cleanupLinkedList(head);
  
  return 0;
}
