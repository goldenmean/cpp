
#include <iostream>
#include <typeinfo>
#include <ctime>

class Base { virtual void dummy() {} };
class Derived : public Base { /* ... */ };
class C { virtual void dummy() {} };

int main() {

    Base* basePtr = dynamic_cast<Base*>(new Derived);
    Base* basePtr2 = dynamic_cast<Base*>(new C);

    if (basePtr)
    {
        std::cout << "Dynamic cast successful , so Derived class is derived from Base class\n";
    }

    if (basePtr2)
    {
        std::cout << "Dynamic cast successful , so C class is derived from Base class\n";
    }
    else
    {
        std::cout << "Dynamic cast failed , so C class is not derived from Base class\n";
    }

    Base* ptr3 = static_cast<Base*>(new Derived);

    if (ptr3)
    {
        std::cout << "Static cast successful , so Derived class is derived from Base class\n";
    }
    else 
    {
        std::cout << "Static cast failed \n";
    }

    Base* ptr4 = static_cast<Base*>(new Base);

    if (ptr4) 
    {   
        std::cout << "ptr4 Static cast successful \n";  
    }
    else
    {
        std::cout << "ptr4 Static cast failed \n";
    }   

    Derived *ptr5 = static_cast<Derived*>(new Base);
    if (ptr5)   
    {
        std::cout << "ptr5 Static cast successful \n";  
    }
    else
    {
        std::cout << "ptr5 Static cast failed \n";
    }

    Base* b = new Base;
    //Derived* d = static_cast<Derived*>(b); //This static cast is successful ! 
    Derived* d = dynamic_cast<Derived*>(b); //This dynamic_cast fails as object b's dynamic type is not Derived class
    if (d)   
    {
        std::cout << "d Static cast successful \n";  
    }
    else
    {
        std::cout << "d Static cast failed \n";
    }

    /*****
    Base* base_ptr = new Derived;
    Derived *ptr1 = new Derived;

    // Using typeid to get the type of the object
    std::cout << "Dynamic Type of base_ptr: " << typeid(*base_ptr).name() << '\n';
    std::cout << "Dynamic Type of ptr1: " << typeid(*ptr1).name() << '\n';
    //std::cout << "Bases of ptr1: " << typeid(*ptr1).bases() << '\n';

    delete base_ptr;
    delete ptr1;
    */
    return 0;
}

