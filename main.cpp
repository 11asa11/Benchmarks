#include "Insert.h"
#include "Erase.h"
#include "Find.h"
#include <map>

int main() {
    std::cout<<"----------INSERT TEST----------"<<std::endl;
    Insert::start_insert_test();
    std::cout<<"----------ERASE TEST----------"<<std::endl;
    Erase::start_erase_test();
    std::cout<<"----------FIND TEST----------"<<std::endl;
    Find::start_insert_test();

    return 0;
}
