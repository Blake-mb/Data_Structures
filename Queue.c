#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue
{
    int size;
    int end;
    int *arr;
} Queue;

void init (Queue *queue, int size)
{
    queue->size = size;
    queue->end = -1;
    queue->arr = (int *)malloc(size * sizeof(int));
}

bool is_empty (Queue *queue)
{
    if (queue->end == -1) return true;
    else return false;
}

bool is_full (Queue *queue)
{
    if (queue->end >= queue->size) return true;
    else return false;
}

void add (Queue *queue, int in_val)
{
    if (is_full(queue))
    {
        printf("The queue is full!\n");
        return;
    }

    queue->end++;
    queue->arr[queue->end] = in_val;
}

int get_front (Queue *queue)
{
    if (is_empty(queue))
    {
        printf("The queue is empty\n");
        return 0;
    }

    int out_val = queue->arr[0];

    int i;

    for (i = 0; i < queue->size; i++)
    {
        queue->arr[i] = queue->arr[i+1];
    }

    queue->end--;

    return out_val;
}

int peek (Queue *queue)
{
    if (is_empty(queue)) return -1;

    else return queue->arr[0];
}