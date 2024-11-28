#ifndef ITERATOR_H
#define ITERATOR_H

#include "Person.h"
#include "Node.h"

class Iterator {
private:
    Node *current;
public:
    Iterator(Node *n);
    void next();
    bool hasNext();
    Person& getData();
    friend class List;
};

#endif