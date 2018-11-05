#include <iostream>
#include <iomanip>

struct node {
  char letter;
  node * next;
};

bool isEmpty(int counter) {
  if(counter == 0) { //checks to see if empty
    return true;
  }
  return false;
}

bool isFull(int counter, int size) {
  if(counter == size) { //checks to see if full, might not be used
    return false;
  }
  return false;
}


void push(node * &n, int &counter, int size, char input) { //can be used for both stack and queue because of how pops work
  if(isFull(counter, size) == true) {
    return;
  }
  else if(isEmpty(counter) == false) { //for every push after the first case
    n = n->next; 
  }
  n->letter = input;
  n->next = new node;
  counter++; 
}  

char pop_stack(node * &n, node * &head, int &counter) { 
  if(isEmpty(counter) == true) {
    return ' ';
  }
  char temp = n->letter; //returns value at node if ever needed
  n = head; //resets current pointer
  counter--;
  for(int i=0; i<counter-1; i++) {
    n = n->next; //starts from beginning and loops through stack using counter to find previous
  }
  return temp;
}

char pop_queue(node * &head, int &counter) {
  if(isEmpty(counter) == true) {
    return ' ';
  }
  char temp = head->letter;
  head = head->next;
  return temp;
}

void print(node * head, int counter) { //test print statement
  for(int i=0; i<counter; i++) {
    std::cout << head->letter << " ";
    head = head->next;
  }
}

int main() {
  //initialize stacks
  node * head_stack = new node;
  node * current_stack = new node;  
  head_stack = current_stack;
  int size_stack = 10;
  int counter_stack = 0;
  
  //initialize queues
  node * head_queue = new node;
  node * current_queue = new node; 
  head_queue = current_queue;
  int size_queue = 10;
  int counter_queue = 0;

  /*
  push(current_stack, counter_stack, size_stack, 'r');
  push(current_stack, counter_stack, size_stack, 'o');
  std::cout << pop_stack(current_stack, head_stack, counter_stack) << std::endl;
  std::cout << pop_stack(current_stack, head_stack, counter_stack) << std::endl;
  */

  push(current_queue, counter_queue, size_queue, 'u');
  push(current_queue, counter_queue, size_queue, 'm');
  std::cout << pop_queue(head_queue, counter_queue) << std::endl;
  std::cout << pop_queue(head_queue, counter_queue) << std::endl;




}
