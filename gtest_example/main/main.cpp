#include <iostream>
#include "module/func.h"




int main(int argc, char **argv) {
    Bird b(1, "k");
    std::cout<<b.GetBirdName()<<" "<<b.GetBirdSize()<<std::endl;
    return 0;
}