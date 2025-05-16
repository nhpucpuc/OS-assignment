#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
        if (q == NULL) return 1;
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
        /* TODO: put a new process to queue [q] */
        if (q == NULL || proc == NULL){
                printf("\033[1;31mNuLL Value\033[0m\n");
                return;
        } 
        if(q->size >= MAX_QUEUE_SIZE){
                printf("\033[1;31mMax Size\033[0m\n");
                return;
        } 

        q->proc[q->size] = proc;
        q->size ++;
}

struct pcb_t * dequeue(struct queue_t * q) {
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
        struct pcb_t* proc = NULL;
        if(q->proc[0] != NULL){
                proc = q->proc[0];
                for(int i = 0 ; i < q->size - 1; i++){
                        q->proc[i] = q->proc[i+1];
                }
                q->size--;
        }
        return proc;
}

