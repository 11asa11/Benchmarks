#include "Insert_sequence.h"
#include "Erase_sequence.h"
#include "Find_sequence.h"

int main() {

    std::cout << "----------SEQUENCE CONTAINERS----------"<<std::endl;
    std::cout<<"----------INSERT TEST----------"<<std::endl;
    Insert_sequence::start_insert_test();
    std::cout<<"----------ERASE TEST----------"<<std::endl;
    Erase_sequence::start_erase_test();
    std::cout<<"----------FIND TEST----------"<<std::endl;
    Find_sequence::start_insert_test();

    std::cout<<std::endl<<std::endl;

    return 0;
}
