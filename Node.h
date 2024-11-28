#ifndef NODE_H
#define NODE_H

#include "Person.h"

class Node {
private:
    Person data;                                              
    Node *next;
public:
    Node();                     
    Node(const Person &p);  
    friend class List;
    friend class Iterator;                           
};

#endif