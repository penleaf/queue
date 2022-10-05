#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include<stdbool.h>

typedef struct node node;
struct node
{
    int data;
    node *next
};


typedef struct queue_t queue_t;
struct queue_t
{
    node *head;
    node *tail;
};


queue_t * queue_new(void);
void queue_delete(void *q);
bool queue_is_empty(const queue_t *q);
int queue_peek(const queue_t *q);
bool queue_enqueue(queue_t *q, int data);
int queue_dequeue(queue_t *q);

queue_t * queue_new(void)
{
    queue_t *q =  malloc(sizeof(queue_t));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void queue_delete(void *q)
{
    node *current = ((queue_t *) q)->head;
    while(!current)
    {
        node *tmp =current;
        current = current->next;
        free(tmp);
    }
    free(q);
}

bool queue_is_empty(const queue_t *q)
{
    if(! q->head)
    {
        return true;
    }
    else
    {
        return false;
    }

}

#endif // QUEUE_H_INCLUDED
