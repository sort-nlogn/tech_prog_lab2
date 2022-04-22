#pragma once

class Queue{
    private:
        struct Node{
            Node(int val);
            int data;
            Node *next;
        };

        Node *head, *tail;

        int size;

    public:
        Queue();

        Queue(const Queue &other);

        void operator=(const Queue &other);

        friend Queue &operator+=(Queue &q, int value);

        friend Queue &operator+(Queue &q1, Queue &q2);

        friend Queue &operator-=(Queue &q, int value);

        friend Queue &operator-(Queue &q1, Queue &q2);
        
        friend Queue &operator*(Queue &q1, Queue &q2);

        friend Queue &operator/(Queue &q, int value);

        void enqueue(int val);

        int dequeue();

        bool is_empty();

        void display();

        void dealloc_nodes();
};