#include <iostream>
//using namespace std;


class Base {
public:
    virtual void function1() {
        std::cout << "Base::function1" << std::endl;
    }

    virtual void function2() {
        std::cout << "Base::function2" << std::endl;
    }

    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void function1() override {
        std::cout << "Derived::function1" << std::endl;
    }

    void function3() {
        std::cout << "Derived::function3" << std::endl;
    }
};

int main() {
    Base* obj = new Derived(); // create a Derived object and assign a pointer of type Base*
    obj->function1(); // calls Derived::function1, due to dynamic polymorphism
    obj->function2(); // calls Base::function2

    //obj->function3();//This gives compilation error saying base class has no member function3
    
    Derived* derived = dynamic_cast<Derived*>(obj); // downcast the Base pointer to a Derived pointer
    derived->function3();

    void **vptr = reinterpret_cast<void**>(obj);
    std::cout << "VTable address: " << vptr << std::endl;
    std::cout << "First Virtual function address in vtbl: " << vptr[0] << std::endl;
    std::cout << "Second Virtual function address in vtbl: " << vptr[1] << std::endl;

    typedef void (*FuncPtr)(Base*);
    FuncPtr funcPtr = reinterpret_cast<FuncPtr>(vptr[0]);
    //funcPtr(obj); //This call gives access violation
    /*
    If you're encountering an access violation even when attempting to correctly pass the this pointer,
     it's crucial to remember that this technique is fraught with risks due to its reliance on undefined
      behavior and assumptions about compiler-specific details. However, for educational purposes, let's
       explore some potential reasons and adjustments you might consider:

Correct Virtual Function Index: Ensure you're accessing the correct index in the vtable for the function 
you intend to call. The first entry (vptr[0]) is typically the top-most virtual function declared in the 
class, but the actual order can vary based on multiple factors, including class inheritance and the order
 of declaration of virtual functions.
Virtual Destructor: If your class has a virtual destructor (which is a good practice when dealing with 
inheritance and polymorphism), it might be occupying the first slot in the vtable. This would 
shift the indices of other virtual functions.
Compiler Optimizations and Security Features: Compiler optimizations or security features 
(like Data Execution Prevention (DEP) or Address Space Layout Randomization (ASLR)) could interfere with
 this kind of direct vtable manipulation. Try disabling optimizations and security features for this 
 experiment (not recommended for production code).
Correct Class Instance: Ensure that the object instance (obj) is of a type that actually has the virtual
 method you're trying to invoke. Using a base class instance when you've overridden the method in a derived
  class, but the instance is not of the derived class, could lead to issues.
Calling Convention: The way functions are called (the calling convention) can affect how parameters are
 passed and might differ between free functions and member functions. This difference can cause problems
  when trying to invoke a member function as if it were a free function.
Given the risks and complexities involved, here's a reminder that this method should only be used for
 learning or debugging purposes. If you're still interested in proceeding, I recommend using a debugger
  to inspect the vtable layout directly and ensure that your assumptions about the layout and function
   indices are correct.

If you continue to face difficulties, consider focusing on compiler documentation or resources specific
 to your development environment for guidance on how virtual functions and vtables are implemented and 
 managed. This can offer insights that are more tailored to the specific behavior you're observing.
    
    */

    delete obj;
    return 0;
}

