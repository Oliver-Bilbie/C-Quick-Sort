#include <stdio.h>
#include <stdlib.h>

// A node in a linked list.
struct node {
  int value;
  struct node *next;
};

// Prepends a node to a linked list.
// Requires a pointer to the current head of the list, and the value
// to be stored in the new node.
// Returns a pointer to the new head of the list.
struct node* prependLinkedList(struct node *head, int value) {
  struct node *newNode = malloc(sizeof(struct node));
  newNode->value = value;
  newNode->next = head;

  return newNode;
}

// Joins two linked lists together.
// Requires pointers to the heads of the two lists to be joined.
// Returns a pointer to the head of the joined list.
struct node* joinLinkedLists(struct node *first, struct node *second) {
  if (first == NULL & second == NULL) {
    return NULL;
  } else if (first == NULL) {
    return second;
  } else if (second == NULL) {
    return first;
  } else {
    struct node *ptr = first;
    while (ptr->next != NULL) {
      ptr = ptr->next;
    } 
    ptr->next = second;
    return first;
  }
}

// Converts an array of integers to a linked list.
// Requires pointers to the first and last elements of the array.
// Returns a pointer to the head of the linked list.
// This function is not used, but was helpful for debugging.
struct node* arrayToLinkedList(int* firstEntry, int* lastEntry) {
  struct node *head = NULL;

  for (int* i = lastEntry; i >= firstEntry; i--) {
    head = prependLinkedList(head, *i);
  };

  return head;
}

// Prints the values stored in a linked list.
// Requires a pointer to the head of the list.
void printLinkedList(struct node *head) {
  struct node *ptr = head;
  
  printf("%d", ptr->value);
  ptr = ptr->next;
  while (ptr != NULL) {
    printf(", %d", ptr->value);
    ptr = ptr->next;
  } 
  printf("\n");
}

// Free the memory allocated to each node in a linked list.
// Requires a pointer to the head of the list.
void cleanupLinkedList(struct node *head) {
  struct node *ptr = head;
  struct node *next_ptr = NULL;
  
  while (ptr != NULL) {
    next_ptr = ptr->next;
    free(ptr);
    ptr = next_ptr;
  } 
}

