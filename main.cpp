#include <iostream>
#include <vector>

using namespace std;

class node {
  public: 
    char data;
    node* next;

    node(char data) {
      this->data = data;
      this->next = nullptr;
    }
};

class list {
  public: 
    node* head;

    list () {
      head = nullptr;
    }

    void add (char data) {
      node* new_node = new node (data);

      if (head == nullptr) {
        head = new_node;
      }

      else {
        node* current = head;

        while (current->next != nullptr) {
          current = current->next;
        }

        current->next = new_node;
      }
    }

    void print () {
      cout << "\n";
      node* current = head;
      while (current != nullptr){
        cout << current->data << " ";
        current = current->next;
      }
      cout << "\n";
    }

    void shuffle (int length){
      for(int j = 0; j < 204; j++){
        int random1 = rand() % length;
        int random2 = rand() % length;
  
        node* letter1 = head;
        node* letter2 = head;
        
        for (int i = 0; i < random1; i++) {
          letter1 = letter1->next;
        }
        for (int i = 0; i < random2; i++) {
          letter2 = letter2->next;
        }
  
        char value1 = letter1->data;
        char value2 = letter2->data;
        
        letter1->data = value2;
        letter2->data = value1;
      }
    }
};

int main () { 
  std::vector <string> words = {"population", "simulation", "inflation", "deflation", "malaysian", "expectations", "keyboard", "elasticity"};
  
  srand (time (0)); 
  int random = rand() % 8;

  string answer = words[random];
  
  list l;
  for(int i = 0; i < answer.length(); i++){
    l.add(answer[i]);
  }

  while (true) {
    l.shuffle(answer.length ());
    l.print();
  
    string INPORT;
    std::cout << "\nunscramble the word? ";
    std::cin >> INPORT;
    
    if(INPORT == answer){
      std::cout<< "\nu win👑";
      break;
    }
  }
}
