#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

queue * create() {
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

void add(queue *q, int item) {
    if (q->size == MAX) {
        printf("Queue is full\n");
        return;
    }
q->rear = (q->rear + 1) % MAX;
q->items[q->rear] = item;
q->size++;
}

void rm(queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    q->front = (q->front + 1) % MAX;
    q->size--;
}

int front(queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[q->front];
}

bool is_empty(queue *q) {
    return q->size == 0;
}

void destroy(queue *q) {
    free(q);
}