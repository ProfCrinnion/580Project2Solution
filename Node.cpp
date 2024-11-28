#include "Node.h"

Node::Node(): data(), next(nullptr)
{
}                      
Node::Node(const Person &p): data(p), next(nullptr)
{
}