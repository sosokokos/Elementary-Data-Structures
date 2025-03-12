//  Created by Daniel Surina on 2022-02-06.

#include <iostream>
#include <stdexcept> 
using std::cout;
using std::endl;

class Node {
public:
    Node *next;
    Node *prev;
    int value;
    //Constructors
    Node() {next = nullptr; prev = nullptr;}
    Node(const int &val) {next = nullptr; prev = nullptr; value = val;}
    ~Node() {};
};

class DequeT {
private:
    Node* head;
    Node* tail;
public:
    DequeT();
    DequeT(const DequeT &dt); 
    ~DequeT();
    void insertFront(const int &val);
    void insertBack(const int &val);
    int removeFront();
    int removeBack();
    int peekFront() const;
    int peekBack() const;
    bool empty() const;
    int size() const;
    void add(Node *nodex, const int &val);
    void remove(Node *node);
    void print() const;
};
DequeT::DequeT() {
    head = new Node;
    tail = new Node;
    head->next = tail;
    head->prev = nullptr;
    tail->prev = head;
    tail->next = nullptr;
}

//copy constructor – creates a deep copy of its constant Deque reference parameter
DequeT::DequeT(const DequeT &dt) { 
    (*this) = dt;
}
DequeT::~DequeT() { 
    while(!empty()) {
        removeFront();
    }
     delete head;
     delete tail;
}

void DequeT::add(Node *node, const int &val) {
    Node *temp;
    temp = new Node(val);
    temp->next = node;
    temp->prev = node->prev;
    node->prev->next = temp;
    node->prev = temp;
}
 
void DequeT::remove(Node *node) {
    Node *predaccessor = node->prev;
    Node *successor = node->next;
    predaccessor->next = successor;
    successor->prev = predaccessor;
    delete node;
}
 
void DequeT::insertFront(const int &val) {
    add(head->next, val);
}
 
void DequeT::insertBack(const int &val) {
    add(tail, val);
}
 
int DequeT::removeFront() {
    if(this->empty())
        throw std::runtime_error("DequeT is empty!");
    int anws = head->next->value;
    
    remove(head->next);
    return anws;
}
 
int DequeT::removeBack() {
    if(this->empty())
        throw std::runtime_error("DequeT is empty!");
    int anws = tail->prev->value;
    
    remove(tail->prev);
    return anws;
}

int DequeT::peekFront() const{
    if(this->empty()) 
        throw std::runtime_error("DequeT is empty!");
    return (head->next->value);
}

int DequeT::peekBack() const{
    if(this->empty()) 
        throw std::runtime_error("DequeT is empty!");
    return (tail->prev->value);
}

bool DequeT::empty() const{
    return (head->next == tail);
}

int DequeT::size() const{
    int size = 0;
    Node *temp = head->next;
    while(temp->next != nullptr) {
        size++;
        temp = temp->next;
    }
    return size;
}

void DequeT::print() const{
    Node* h = head;
    
    while(h != nullptr){
        cout << h->value << endl;
        h = h->next;
    }
}

class QueueT{
private:
    DequeT quee;
public:
    QueueT() {} 
    void enqueue(const int &val) {quee.insertBack(val);}
    int dequeue() {return quee.removeFront();}
    bool empty() const {return quee.empty();}
    int size() const {return quee.size();}
    void print();
};
void QueueT::print() {
    quee.print();
}


int main() {
    
    DequeT test;
    test.insertFront(03);
    test.insertFront(02);
    test.insertFront(01);
    
    cout << "Printing Test Before: " << endl;
    test.print();
    
    test.removeBack();
    cout << "Testing: " << endl;
    test.print();
    cout << test.peekBack() << endl;
   
    return 0;
}
