#include "Person.h"

Person::Person(): name("Unknown"), age(0) {  
}
Person::Person(std::string n, int a): name(n), age(a) {
}
void Person::setName(std::string n)
{
    name = n;
}
void Person::setAge(int a)
{
    age = a;
}
std::string Person::getName() const
{
    return name;
}
int Person::getAge() const
{
    return age;
}
void Person::print() const {
    std::cout << std::left << std::setw(25) << name << std::setw(4) << age << "\n";
}
bool Person::equivalent(const Person &p1, const Person &p2)
{
    return p1.name == p2.name && p1.age == p2.age;
}
bool Person::compare(const Person &p1, const Person &p2, bool comparator)
{
    if(comparator == true) {
        return p1.age <= p2.age; 
    } else {
        return p1.age > p2.age; 
    }    
}