#include <stdio.h>
// Queue ADT using array
//
//

// T                 
//  - - - - - - - - - - 
//  0 1 2 3 4 5 6 7 8 9
// H
int queue[10] = {0};
int head = -1;
int tail = -1;

void enqueue(int n) {
  tail++;
  if (tail >= 10) {
    printf("***Enqueue Error. OVERFLOW!!. Item=%d. Head=%d, Tail=%d\n", n, head, tail);
    tail = -1;
    return;
  }
  printf("Enqueue OK. Item=%d. Head=%d, Tail=%d\n", n, head, tail);
  queue[tail] = n;
}

int dequeue() {
  if (head == -1) {
    head++;
  }
  if (head == tail && head == -1) {
    printf("********* Dequeue Error. Empty Queue!!!. Head=%d, Tail=%d\n", head, tail);
    return -1;
  }
  if (head >= 10) {
    printf("*** Wrap paround queue head as it has crossed the boundry. head=%d, new head =%d\n", head, -1);
    head = -1;
    return -1;
  }

  int item =  queue[head];
  head++;
  printf("Dequeue OK. Item=%d. head=%d, tail=%d\n", item, head, tail);
  return item;
}

int peak(void) {
  if (head == -1) {
    //must be special condition.. 
    head++;
  }
  printf("Peak. Head=%d, Tail=%d. Item at Head=%d\n", head, tail, queue[head]);
  return queue[head];
}

int main(void) {

  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  enqueue(5);
  enqueue(6);
  enqueue(7);
  enqueue(8);
  enqueue(9);
  enqueue(10);
  enqueue(11);

  peak();
 
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  dequeue();

  enqueue(20);
  enqueue(21);
  enqueue(22);
  enqueue(23);

  dequeue();
  dequeue();
  dequeue();

  return 0;
}
  
