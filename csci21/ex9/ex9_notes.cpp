//oct 16

(*) muliptly
    pointer
      string* s;
      string  s2;
      s = new string(hello);
    dereferencing
      cout << s << endl; //string adress value
      cout << (*s) << endl; //dereferencing s pointer to print out contents
      cout << (*s).size() << endl;
(->) member selection(arrow) opperator
     used to dereference
      cout << s.at(0) << endl; //no good because its a string
      cout << s->at(0) << endl; // correct way need to use arrow
(delete) deletes whatever new created; address not pointer itself;
         need to set the pointer back to nullptr;
(&) pass by reference
    address of
      s = s2; //doesnt work; cant assign a string to a pointer string
      s = &s2; //correct way to assign string to a pointer string

int x = 0; //static variable; its in the stack(found in the stack); anything we declare is on the stack;
string* s = nullptr;//staticly delcared;also on the stack

s = new string("red");// new requests memory from the heap; takes address from the heap and stores it in 's'


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//examples

struct Box {
  string contents;

};

class Barrel  {
private:
  string contents;
public:
  string  getContents();
  void    setContents();
};
//asterisc can go anywhere really;
Box* b1 = nullptr;

Box *b2 = nullptr;

Box * b3 = nullptr;

b1 = new Box;
b2 = b1;
delete b2;
b1 = nullptr;
b2 = nullptr;

Barrel* ba = new Barrel;
ba -> setContents("fun");

if(b1 != nullptr) {
  cout << b1->contents);
  cout << b2->contents;//same thing
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//linked data structures

singly linked list;
doubly linked list;
binary search tree;


//singly
[data][-]->[data][-]->nullptr; //nodes
struct Node {
  int data;
  Node* next;
}
