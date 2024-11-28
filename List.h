#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Node.h"
#include "Iterator.h"
#include "Person.h"

class List {       
private:                                        
    Node *head;  
    Node *tail;
public:                                             
    int size;
    List();
    ~List();
    bool empty(); 
    void clear();
    int getSize(); 
    void push_front(const Person &p);
    void push_back(const Person &p);
    void pop_front();  
    Iterator insertAfter(Iterator it, const Person &p);
    Iterator eraseAfter(Iterator it);                      
    Iterator begin();
    Iterator end();       
    Person& front();
    Person& back();     
    void print();
    Iterator find(Person &p);

    static void sortedInsert(List &list, Person &p, bool comparator);
    static Iterator binarySearch(List &list, Person &p, bool comparator);
    static void merge(List &s1, List &s2, List &list, bool comparator);
    static void mergeSort(List &list, bool comparator);
    static void reverse(List &list);
};

#endif