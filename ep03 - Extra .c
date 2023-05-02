	/*
	Guilherme Araújo Mendes de Souza - 156437
	UNIFESP - ICT
	AED 1

	beecrowd | 1340
	Eu Posso Adivinhar a Estrutura de Dados!
	*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct stack {
    Node *top;
} Stack;

typedef struct queue {
    Node *head;
    Node *tail;
} Queue;

typedef struct priority_queue {
    Node *head;
} PriorityQueue;

Node* create_node(int value) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

Stack* create_stack() {
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack *stack, int value) {
    Node *node = create_node(value);
    node->next = stack->top;
    stack->top = node;
}

int pop(Stack *stack) {
    if (stack->top == NULL) {
        return -1;
    }
    int value = stack->top->value;
    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return value;
}

int is_empty_stack(Stack *stack) {
    return stack->top == NULL;
}

void clear_stack(Stack *stack) {
    while (!is_empty_stack(stack)) {
        pop(stack);
    }
}

Queue* create_queue() {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void enqueue(Queue *queue, int value) {
    Node *node = create_node(value);
    if (queue->head == NULL) {
        queue->head = node;
        queue->tail = node;
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }
}

int dequeue(Queue *queue) {
    if (queue->head == NULL) {
        return -1;
    }
    int value = queue->head->value;
    Node *temp = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    free(temp);
    return value;
}

int is_empty_queue(Queue *queue) {
    return queue->head == NULL;
}

void clear_queue(Queue *queue) {
    while (!is_empty_queue(queue)) {
        dequeue(queue);
    }
}

PriorityQueue* create_priority_queue() {
    PriorityQueue *priority_queue = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    priority_queue->head = NULL;
    return priority_queue;
}

void enqueue_priority(PriorityQueue *priority_queue, int value) {
   Node *node = create_node(value);
   if (priority_queue->head == NULL || value > priority_queue->head->value) {
       node->next = priority_queue->head;
       priority_queue->head = node;
   } else {
       Node *current = priority_queue->head;
       while (current->next != NULL && current->next->value > value) {
           current = current -> next;
       }
       node -> next = current -> next;
       current -> next = node;
   }
}

int dequeue_priority(PriorityQueue *priority_queue) {
   if (priority_queue -> head == NULL) {
       return -1;
   } else {
       int value = priority_queue -> head -> value;
       Node* temp = priority_queue -> head;
       priority_queue -> head = priority_queue -> head -> next;
       free(temp);
       return value;
   }
}

int is_empty_priority(PriorityQueue *priority_queue) {
   return priority_queue -> head == NULL;
}

void clear_priority(PriorityQueue *priority_queue) {
   while (!is_empty_priority(priority_queue)) {
       dequeue_priority(priority_queue);
   }
}

int main() {

  int n, op, x;

  while(scanf("%d", &n) != EOF){

      Stack* stack = create_stack();
      Queue* queue = create_queue();
      PriorityQueue* priority_queue = create_priority_queue();

      int is_stack, is_queue, is_priority;

      is_stack=1; is_queue=1;
      is_priority=1;

      for(int i = 0; i < n; i++){
          scanf("%d %d", &op, &x);
          if(op == 1){
              push(stack, x);
              enqueue(queue, x);
              enqueue_priority(priority_queue, x);
          } else {
              int s = pop(stack);
              int q = dequeue(queue);
              int p = dequeue_priority(priority_queue);

              if(s != x) is_stack = 0;
              if(q != x) is_queue = 0;
              if(p != x) is_priority = 0;
          }
      }

      if(is_stack + is_queue + is_priority > 1){
          printf("not sure\n");
      } else if(is_stack){
          printf("stack\n");
      } else if(is_queue){
          printf("queue\n");
      } else if(is_priority){
          printf("priority queue\n");
      } else {
          printf("impossible\n");
      }

      clear_stack(stack);
      clear_queue(queue);
      clear_priority(priority_queue);

      free(stack);
      free(queue);
      free(priority_queue);

  }

  return 0;
}
