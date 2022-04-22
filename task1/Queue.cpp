#include "Queue.hpp"
#include <iostream>
#include <math.h>

#define randint(a, b) (int)round(((float)rand() / RAND_MAX) * (b - a) + a)

Queue::Node::Node(int value): next(nullptr), data(value){

}

Queue::Queue(const Queue &other): tail(nullptr), head(nullptr), size(0){
    this->operator=(other);
}

void Queue::enqueue(int val){
    Queue::Node *n = new Queue::Node(val);
    size++;
    if(tail == nullptr){
        head = n;
        tail = n;
    }else{
        tail->next = n;
        tail = n;
    }
}

bool Queue::is_empty(){
    return size == 0;
}

int Queue::dequeue(){
    if(is_empty())
        throw std::runtime_error("Empty queue!");

    size--;
    int ans = head->data;
    Queue::Node *new_head = head->next;
    delete head;
    head = new_head;
    if(new_head == nullptr)
        tail = nullptr; 
    return ans;
}

Queue::Queue(): head(nullptr), tail(nullptr), size(0){
    std::cout << "Queue size: ";
    int q_size = 0;
    std::cin >> q_size;
    for(int i = 0; i < q_size; i++){
        enqueue(randint(10, 20));
    }
}

Queue &operator+=(Queue &q, int value){
    q.enqueue(value);
    return q;
}

Queue &operator+(Queue &q1, Queue &q2){
    Queue::Node *curr1 = q1.head, *curr2 = q2.head;
    for(int i = 0; i < std::min(q1.size, q2.size); i++){
        curr1->data += curr2->data;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return q1;
}

Queue &operator-=(Queue &q, int value){
    if(value < 0)
        throw std::runtime_error("Incorrect count of nodes!");
    if(q.size < value)
        throw std::runtime_error("Not enough nodes in queue!");
    for(int i = 0; i < std::min(q.size, value); i++){
        q.dequeue();
    }
    return q;
}

Queue &operator-(Queue &q1, Queue &q2){
    Queue::Node *curr1 = q1.head, *curr2 = q2.head;
    for(int i = 0; i < std::min(q1.size, q2.size); i++){
        curr1->data -= curr2->data;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return q1;
}

Queue &operator*(Queue &q1, Queue &q2){
    Queue::Node *curr1 = q1.head, *curr2 = q2.head;
    for(int i = 0; i < std::min(q1.size, q2.size); i++){
        curr1->data *= curr2->data;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return q1;
}

Queue &operator/(Queue &q, int value){
    if(value == 0)
        throw std::runtime_error("Division by zero!");
    Queue::Node *curr = q.head;
    for(int i = 0; i < q.size; i++){
        curr->data /= value;
        curr = curr->next;
    }
    return q;
}

void Queue::display(){
    std::cout << "head";
    Queue::Node *curr = head;
    while(curr != nullptr){
        std::cout << "->" << curr->data;
        curr = curr->next;
    }
    std::cout << std::endl;
}

void Queue::dealloc_nodes(){
    Node *curr = head, *nxt = nullptr;
    while(curr != nullptr){
        nxt = curr->next;
        delete curr;
        curr = nxt;
    }
    size = 0;
    head = nullptr, tail = nullptr;
}

void Queue::operator=(const Queue &other){
    dealloc_nodes();
    Node *curr = other.head;
    while(curr != nullptr){
        this->enqueue(curr->data);
        curr = curr->next;
    }
}