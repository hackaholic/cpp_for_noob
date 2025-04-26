/*
Modifier  | Accessible inside class? | Accessible outside class? | Accessible in derived class?
private   | ✅ Yes                  | ❌ No                     | ❌ No
protected | ✅ Yes                  | ❌ No                     | ✅ Yes
public    | ✅ Yes                  | ✅ Yes                    | ✅ Yes


🔹 What is protected?

It’s like private, but subclasses (derived classes) can also access it.
Real-Life Analogy:

    private = secret diary (only you can open it)

    protected = family recipe (only your kids can use it, not outsiders)

    public = social media post (everyone sees it)
*/

#include <iostream>

class Box {
    private:
        int length;
    
    public:
        void setLength(int l) {
            this->length = l;
        }
    
        int getLength() {
            return length;
        }
    };

// protected usage
class Base {
    protected:
        int x;
    
    public:
        Base() { x = 100; }
    };
    
class Derived : public Base {
    public:
      void showX() {
        std::cout <<  "x = " << this->x << std::endl;
      }
};

int main(int argc, char *argv[]) {
    Box *b = new Box();   // Dynamic Object Creation, new returns a pointer. Use -> to access members
    b->setLength(10);
    std::cout << b->getLength() << std::endl;

    Derived d;
    d.showX();
    return 0;
}
