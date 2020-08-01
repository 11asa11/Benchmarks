#include "Insert_sequence.h"
#include "Erase_sequence.h"
#include "Find_sequence.h"

#include "Insert_associative.h"
#include "Erase_associative.h"
#include "Find_associative.h"

int main() {

    /*std::cout << "----------SEQUENCE CONTAINERS----------"<<std::endl;
    std::cout<<"----------INSERT TEST----------"<<std::endl;
    Insert_sequence::start_insert_test();
    std::cout<<"----------ERASE TEST----------"<<std::endl;
    Erase_sequence::start_erase_test();
    std::cout<<"----------FIND TEST----------"<<std::endl;
    Find_sequence::start_find_test();*/

    std::cout<<std::endl<<std::endl;

    std::cout << "----------ASSOCIATIVE CONTAINERS----------"<<std::endl;
    std::cout<<"----------INSERT TEST----------"<<std::endl;
    Insert_associative::start_insert_test();
    std::cout<<"----------ERASE TEST----------"<<std::endl;
    Erase_associative::start_erase_test();
    std::cout<<"----------FIND TEST----------"<<std::endl;
    Find_associative::start_find_test();

    return 0;
}
