// https://blog.csdn.net/u013171226/article/details/121450408

#include <string>
#include <map>

#define REGISTER(className) 											\
	className* objectCreator##className(){     							\
        return new className();                                         \
    }                                                                  	\
    RegisterAction g_creatorRegister##className(                        \
		#className,(PTRCreateObject)objectCreator##className)

typedef void* (*PTRCreateObject)(void); 
// 工厂类的定义
class ClassFactory {
private:  
    std::map<std::string, PTRCreateObject> m_classMap ;  
	ClassFactory(){}; //构造函数私有化
	
public:   
    void* getClassByName(std::string className);  
    void registClass(std::string name, PTRCreateObject method) ;  
    static ClassFactory& getInstance() ;  
};
 

// 注册动作类
class RegisterAction {
public:
	RegisterAction(std::string className,PTRCreateObject ptrCreateFn) {
		ClassFactory::getInstance().registClass(className, ptrCreateFn);
	}
};
