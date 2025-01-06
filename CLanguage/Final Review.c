#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 10

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(char *array[], int len) {
    for (int k=0; k < len; k++){
        for int j - 0; j < len - 1; j++){
            if (strcmp(array[j], array[j+1]) > 0){
                for (int i = 0; i < N; i++){
                    swap(&array[j][i], &array[j+1][i]);
                }
            }
        }
    }
}

struct node{
    int item;
    struct node *next;
    struct node *prev;
}

struct list{
    struct node *front;
    struct node *tail;
}

struct list * init_dllist () {
    struct list *list = (struct list *) malloc(sizeof(struct list));
    if(list == NULL) 
        return NULL;
    list->front = NULL;
    list->tail = NULL;
    return list;
}

bool insert_front(struct list *list, int item) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));//allocate memory for new node
    if (new_node == NULL) return false;//malloc failed
    new_node->item = item;//initialize new node
    new_node->next = list->front;//set new node's next to the front of the list
    new_node->prev = NULL;//set new node's prev to NULL
    if (list->front != NULL) list->front->prev = new_node;//set the front of the list's prev to the new node
    list->front = new_node;//set the front of the list to the new node
    if (list->tail == NULL) list->tail = new_node;//if the list is empty, set the tail to the new node
    return true;
}

 void list_destroy(struct list *list) {
    struct node *current = list->front;//start at the front of the list
    struct node *next = NULL;//initialize next to NULL
    while (current) {//while current is not NULL
        next = current->next;//set next to the next node
        free(current);//free the current node
        current = next;//set current to the next node
    }
    free(list);
 }

int list_length(const struct list *list) {//return the length of the list
    int len = 0;//initialize length to 0
    const struct node *current = list->front;//start at the front of the list
    while (current) {//while current is not NULL
        ++len;//increment length
        current = current->next;//move to the next node
    }
    return len;
}

int node_length(const struct node *node) {
    if (node == NULL) 
        return 0;//if the node is NULL, return 0
    return 1 + node_length(node->next);//return 1 plus the length of the next node
}

int list_length_recursive(const struct list *list) {
    return node_length(list->front);//return the length of the front node
}

typedef int arr[5];
//arr[10] will result in a 2D array of 10 rows and 5 columns. 

FILE typedef (struct file) {
    char *name;
    int size;
    char *data;
}

int main() {

    return 0;
}