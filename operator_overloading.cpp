//C++ operator overloading 

//prefix,postfix - increment and decrement oeprators
struct X
{
    // prefix increment
    X& operator++()
    {
        // actual increment takes place here
        return *this; // return new value by reference
    }
 
    // postfix increment
    X operator++(int)
    {
        X old = *this; // copy old value
        operator++();  // prefix increment
        return old;    // return old value
    }
 
    // prefix decrement
    X& operator--()
    {
        // actual decrement takes place here
        return *this; // return new value by reference
    }
 
    // postfix decrement
    X operator--(int)
    {
        X old = *this; // copy old value
        operator--();  // prefix decrement
        return old;    // return old value
    }
};

//operator []
class MyContainer {
private:
    int* data; // Pointer to store integers
    size_t size; // Size of the container

public:
    // Constructor
    MyContainer(size_t size) : size(size), data(new int[size]) {}

    // Destructor
    ~MyContainer() { delete[] data; }

    // Overload [] operator
    int& operator[](size_t index) {
        return data[index];
    }
};

//operator - 
#include <iostream>
using namespace std;

class Complex
{
    private:
      float real;
      float imag;
    public:
       Complex(): real(0), imag(0){ }
       void input()
       {
           cout << "Enter real and imaginary parts respectively: ";
           cin >> real;
           cin >> imag;
       }

       // Operator overloading
       Complex operator - (Complex c2)
       {
           Complex temp;
           temp.real = real - c2.real;
           temp.imag = imag - c2.imag;

           return temp;
       }

       void output()
       {
           if(imag < 0)
               cout << "Output Complex number: "<< real << imag << "i";
           else
               cout << "Output Complex number: " << real << "+" << imag << "i";
       }
};

int main()
{
    Complex c1, c2, result;

    cout<<"Enter first complex number:\n";
    c1.input();

    cout<<"Enter second complex number:\n";
    c2.input();

    // In case of operator overloading of binary operators in C++ programming, 
    // the object on right hand side of operator is always assumed as argument by compiler.
    result = c1 - c2;
    result.output();

    return 0;
}

//operator +
#include <iostream>
using namespace std;

class Complex {
    private:
        float real;
        float img;

    public:
         // constructor to initialize real and img to 0
         Complex() : real(0), img(0) {}
         Complex(float real, float img) : real(real), img(img){}

       // overload the + operator
         friend Complex operator + (const Complex& obj1, const Complex& obj2) {
             Complex temp;
              temp.real = obj1.real + obj2.real;
              temp.img = obj1.img + obj2.img;
              return temp;
    }

    void display() {
        if (img < 0)
            cout << "Output Complex number: " << real << img << "i";
      else
           cout << "Output Complex number: " << real << "+" << img << "i";
    }
};

int main() {
    Complex c1(1.0f, 2.0f);
    Complex c2(1.0f, 3.0f);

    // calls the overloaded + operator
    Complex result = c1 + c2;
    result.display();

    return 0;
}

//operator ()
#include <iostream>

class MyFunctionObject {
private:
    int count; // Stores the number of times the object has been called

public:
    // Constructor initializes count to 0
    MyFunctionObject() : count(0) {}

    // Overload () operator
    void operator()(int value) {
        ++count;
        std::cout << "Called " << count << " times." << std::endl;
    }
};

int main() {
    MyFunctionObject myFuncObj;

    // Directly invoking the overloaded () operator
    myFuncObj(5);
    myFuncObj(10);

    return 0;
}
