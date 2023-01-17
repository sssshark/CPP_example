#include <iostream>
#include "class_factory/class_factory.h"
#include "singleton_mode/singleton_mode.h"

class TestClassFactory {
public:
    void print() {
        std::cout<<"Test ClassFactory"<<std::endl;
    }
};


REGISTER(TestClassFactory);

int main() 
{
    TestClassFactory* test = (TestClassFactory*)ClassFactory::getInstance().getClassByName("TestClassFactory");
    test->print();
    
    Singleton::getInstance().Print();
    return 0;
}