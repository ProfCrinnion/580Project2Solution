#include "List.h"

List::List(): head(nullptr), tail(nullptr), size(0)
{

}
List::~List()
{
    Node *n = head;                         
    Node *backup = nullptr;
    while(n != nullptr) {                   
        backup = n;                         
        n = n->next;                        
        delete backup;                      
    }
} 
bool List::empty()
{
    return head == nullptr;
}
void List::clear()
{
    Node *n = head;
    Node *backup;
    while(n != nullptr) {
        backup = n;
        n = n->next;
        delete backup;
    }
    head = tail = nullptr;
    size = 0;
} 
int List::getSize()
{
    return size;
}
Iterator List::begin() 
{
    return Iterator(head);
} 
Iterator List::end() 
{
    return Iterator(nullptr);
}     
Person& List::front() {
    return head->data;
}
Person& List::back() {
    return tail->data;
}
void List::push_front(const Person &p)                   
{
    Node *n = new Node(p);                                  
    n->next = head;                          
    head = n;                              

    if(tail == nullptr) { tail = n; }
    ++size;
}
void List::push_back(const Person &p)                    
{
    if( empty() ) {                        
        push_front(p);
        return;
    }
    
    Node *n = new Node(p);                      
    tail->next = n;                                            
    tail = n;                              
    ++size;                                        
}
void List::pop_front() 
{
    if( empty() ) {                         
        return; 
    }

    Node *n = head;                        
    head = head->next;                
    delete n;                                   

    if(head == nullptr) {                  
        tail = nullptr; 
    } 
    --size; 
}
Iterator List::insertAfter(Iterator it, const Person &p) 
{
    if( empty() || it.current == nullptr) { 
        return it;                              
    }

    Node *n = new Node(p);                      
    n->next = it.current->next;                 
    it.current->next = n;                       

    if(n->next == nullptr) { tail = n; }   
    ++size;
    return Iterator(n); 
}
Iterator List::eraseAfter(Iterator it)           
{
    if( empty() || it.current == nullptr || it.current->next == nullptr) { 
        return it;                                          
    }                                            

    Node *n = it.current->next;                 
    it.current->next = n->next;                 

    if( n->next == nullptr ) { tail = n; } 

    delete n;                                   
    --size;
    return Iterator(it.current->next);                                        
}
void List::print() 
{                              
    Iterator it = begin();                  
    while( it.hasNext() ) {                      
        it.getData().print();   
        it.next();                             
    }   
    std::cout << "\n";  
}
Iterator List::find(Person &p) 
{
    Iterator it = begin();
    while( it.hasNext() ) {
        if( Person::equivalent(it.getData(), p) ) { return it; }
        it.next();
    }   
    return Iterator(nullptr);     
}

// static functions
void List::sortedInsert(List &list, Person &p, bool comparator)
{
    Node *current = list.head;
    if( list.empty() || Person::compare(p, current->data, comparator)) {
        list.push_front(p);
        return;
    }
    while( current->next != nullptr && Person::compare(current->next->data, p, comparator) ) {
        current = current -> next;
    }
    Node *temp = new Node(p);
    temp->next = current->next;
    current->next = temp;
    if(temp->next == nullptr) { list.tail = temp; }
    ++list.size;
}
Iterator List::binarySearch(List &list, Person &p, bool comparator) 
{
    if(list.head == nullptr) { return Iterator(nullptr); }                              

    Node *start = list.head;                                                            
    Node *end = nullptr;                                                                

    do {

        Node *mid = start;                                                              
        Node *last = start->next;                                                        
                                                                                        
        while( last != end ) {                                                           
            last = last->next;                                                            
            if( last != end ) {                                                          
                mid = mid->next;                                                        
                last = last->next;                                                        
            }
        }  
        if( Person::equivalent(mid->data, p) ) {                                        
            return Iterator(mid);
        } else if( Person::compare(mid->data, p, comparator) ) {                        
            start = mid->next;
        } else {                                                                       
            end = mid;
        }  

    } while( end != start );                                                            
    return Iterator(nullptr);                                                           
}

void List::merge(List &s1, List &s2, List &list, bool comparator) 
{
    Iterator it1 = s1.begin();
    Iterator it2 = s2.begin();
    while(it1.hasNext() && it2.hasNext()) {
        if( Person::compare( it1.getData(), it2.getData(), comparator ) ) {
            list.push_back( it1.getData() );
            it1.next();
        } else { 
            list.push_back( it2.getData() );
            it2.next();
        }
    }
    while( it1.hasNext() ) {
        list.push_back( it1.getData() );
        it1.next();       
    }
    while( it2.hasNext() ) {
        list.push_back( it2.getData() );
        it2.next();    
    }
}

void List::mergeSort(List &list, bool comparator) 
{
    int n = list.getSize();
    if( n<=1 ) { return; }

    List s1, s2;
    Iterator itr = list.begin();

    for(int i=0; i<n/2; ++i) { 
        s1.push_back(itr.getData());
        itr.next();
    }
    for(int i=n/2; i<n; ++i) {
        s2.push_back(itr.getData());
        itr.next();
    }
    list.clear();

    mergeSort(s1, comparator);
    mergeSort(s2, comparator);
    merge(s1, s2, list, comparator);
}

void List::reverse(List &list) {
    Node *temp = nullptr;
    Node *prev = nullptr;
    Node *current = list.head;
    while( current != nullptr ) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    list.head = prev;
}