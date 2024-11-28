#include <iostream>
#include <fstream>
#include <sstream>
#include "List.h"

void read(std::string file, List &list, bool comparator) 
{
    std::ifstream myFile;
    myFile.open(file);
    std::string line, token;                        
    while( getline(myFile, line) ) {                
        std::string name;                            
        int age;  
        std::istringstream parser(line);                          

        getline(parser, token, ',');
        name = token;

        getline(parser, token, ',');
        std::istringstream converter(token);    
        converter >> age;

        Person p{name, age};
        List::sortedInsert(list, p, comparator);   
    }
    myFile.close();                                 
}

int main() {
    std::cout << std::endl;

    std::string file = "data.csv";
    List list;
 
    Person p1{"Aidan Newman", 16};    
    Person p2{"Jesse Salazar", 25};  
    Person p3{"Zahir Alvarez", 56}; 
    Person p4{"Pericles Georgiou", 23};        
    Person p5{"Ramon Perez", 42}; 
    Person p6{"Tim Robbins", 58};
    Person p7{"Kate Williams", 74};  
                 
    std::cout << "READ/SIZE: SMALL TO LARGE" << std::endl;
    read(file, list, true);
    std::cout << std::left << std::setw(25) << "Name" << std::setw(4) << "Age\n\n";
    list.print(); 

    std::cout << "SIZE" << std::endl;
    std::cout << list.getSize() << " nodes\n\n"; 

    std::cout << "READ/SIZE: LARGE TO SMALL" << std::endl;
    list.clear();
    read(file, list, false);
    std::cout << std::left << std::setw(25) << "Name" << std::setw(4) << "Age\n\n";
    list.print(); 
    std::cout << list.getSize() << " nodes\n\n";     

    std::cout << "MERGE SORT: SMALL TO LARGE" << std::endl;
    List::mergeSort(list, true); 
    std::cout << std::left << std::setw(25) << "Name" << std::setw(4) << "Age\n\n";
    list.print(); 

    std::cout << "FRONT/BACK" << std::endl;
    list.front().print( );
    list.back().print( );
    std::cout << "\n";

    std::cout << "BINARY SEARCH: (first, middle, last)" << std::endl;
    Iterator it = List::binarySearch(list, p1, true);   
    if(it.hasNext())  { it.getData().print(); }
    it = List::binarySearch(list, p2, true);   
    if(it.hasNext())  { it.getData().print(); }    
    it = List::binarySearch(list, p3, true);   
    if(it.hasNext())  { it.getData().print(); }       
    std::cout << "\n";  

    std::cout << "PUSH BACK/FRONT: PERICLES GEORGIOU 23, RAMON PEREZ 42" << std::endl;
    list.push_front( p4 );
    list.push_back( p5 );
    list.print(); 

    std::cout << "POP FRONT" << std::endl;
    list.pop_front();
    list.print();    

    std::cout << "INSERTAFTER: TIM ROBBINS 58 (second), KATE WILLIAMS 74 (last)" << std::endl;     
    it = list.begin();              
    it = list.insertAfter( it, p6 ); 
    it = list.find( p5 ); 
    it = list.insertAfter( it, p7 );      
    list.print(); 

    std::cout << "ERASEAFTER: TIM ROBBINS (second), STELLA HORNE (middle), KATE WILLIAMS (last)" << std::endl; 
    it = list.begin();
    it = list.eraseAfter( it );  
    it = list.find( p2 );              
    it = list.eraseAfter( it );   
    it = list.find( p5 );              
    it = list.eraseAfter( it );           
    list.print(); 

    std::cout << "MERGE SORT: LARGE TO SMALL" << std::endl;
    List::mergeSort(list, false); 
    std::cout << std::left << std::setw(25) << "Name" << std::setw(4) << "Age\n\n";
    list.print(); 

    Person p8{"Jonas Yung", 84};
    Person p9{"Kim Jeane", 10};
    Person p10{"Atticus Weller", 28};   

    std::cout << "SORTED INSERT/SIZE LARGE TO SMALL: Kim Jeane (first), Atticus Weller (middle), Jonas Yung (last)" << std::endl;
    List::sortedInsert(list, p8, false);
    List::sortedInsert(list, p9, false);
    List::sortedInsert(list, p10, false);
    list.print(); 

    std::cout << "REVERSE" << std::endl;
    List::reverse(list);
    list.print();  
    
    std::cout << "REVERSE BACK" << std::endl;
    List::reverse(list);
    list.print();   

    std::cout << std::endl;
    return 0;
}