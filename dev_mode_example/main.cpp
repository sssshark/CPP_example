#include <iostream>
#include "class_factory/class_factory.h"


class TestClass {
public:
    void print() {
        std::cout<<"Test Class"<<std::endl;
    }
};


REGISTER(TestClass);

int main() 
{
    TestClass* test = (TestClass*)ClassFactory::getInstance().getClassByName("TestClass");
    test->print();
    
    return 0;
}