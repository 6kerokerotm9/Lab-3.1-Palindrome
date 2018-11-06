#include <iostream>
#include <iomanip>
#include <cctype>

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

void push(node * &n, int &counter, char input) { //can be used for both stack and queue because of how pops work
  if(isEmpty(counter) == false) { //for every push after the first case
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
  head = head->next; //sets the first elements to the next element
  return temp;
}

void fill(node * &current, std::string s, int &counter) { //function to fill the queue and stack
  for(int i=0; i < s.size(); i++) { //for loop that takes character and puts it in each place in the stack or queue
    if(s[i] < 91 && s[i] > 64) { //checks to see if the letter is uppercase
      push(current, counter, std::tolower(s[i])); //changes the letter to lowercase and then pushes it in
    }
    else if(s[i] < 97 || s[i] > 122) { //if the letter is a symbol then this catches it 
      continue; //ignore all the symbols, spaces, and numbers and do not push into the stack for the sake of simplicity
    }
    else { 
      push(current, counter, s[i]);
    }
  }
}

void print(node * head, int counter) { //test print statement
  for(int i=0; i<counter; i++) {
    std::cout << head->letter << " ";
    head = head->next;
  }
  std::cout << std::endl;
}

int main() {
  //initialize stack
  node * head_stack = new node; //creates the head pointer
  node * current_stack = new node; //keeps track of the most recently added element into the stack
  head_stack = current_stack;
  int counter_stack = 0; //counter for stack to keep track of how many elements are in the stack
  
  //initialize queue
  node * head_queue = new node; //creates the queue head pointer
  node * current_queue = new node; //same as stack but for queue
  head_queue = current_queue;
  int counter_queue = 0; //counter for queue to see how many elements are in the queue
  
  //initialize other variables
  std::string input;
  int size; //constant that will be used later when the counters change because of popping 
 
  std::cout << "Please enter a word: ";
  std::getline(std::cin, input);
  fill(current_stack, input, counter_stack); //fill the stack with the characters from the string
  fill(current_queue, input, counter_queue); //fills the queue
  size = counter_stack; //set size to how many elements are max in the queue and stack
  print(head_stack, counter_stack);
  print(head_queue, counter_queue);
  for(int i=1; i<=size; i++) {
    if(pop_stack(current_stack, head_stack, counter_stack) != pop_queue(head_queue, counter_queue)) { //pops accordingly and then compares
      std::cout << "The input is not a palindrome." << std::endl;
      break;
    }
    else if(i == size) { //if all the letters are popped out and all matched to each other
      std::cout << "The input is a palindrome." << std::endl;
    }
  }   
}
    

