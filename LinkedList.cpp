#https://m.facebook.com/story.php?/posts/2629615697301733
#Subscribed by Code House

#include <bits/stdc++.h>
using namespace std;

// Creating a node
class Node {
   public:
  int value;
  Node* next;
};

int main() {
  Node* head;
  Node* one = NULL;
  Node* two = NULL;
  Node* three = NULL;

  one = new Node();
  two = new Node();
  three = new Node();

  one->value = 1;
  two->value = 2;
  three->value = 3;
  
  one->next = two;
  two->next = three;
  three->next = NULL;

  head = one;
  while (head != NULL) {
    printf("%d ", head->value);
    head = head->next;
  }
}
