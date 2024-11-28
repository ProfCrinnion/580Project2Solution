#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <iomanip>

class Person {
private:
    std::string name;
    int age;
public:
    Person();
    Person(std::string n, int a);
    void setName(std::string n);
    void setAge(int n);
    std::string getName() const;
    int getAge() const;
    void print() const;     
    static bool equivalent(const Person &p1, const Person &p2);
    static bool compare(const Person &p1, const Person &p2, bool comparator);    
};

#endif