#include <iostream>
#include <memory>


/* 
weak_ptr must always be initialized from a shared_ptr.

Why weak_ptr exists?
To break cyclic references and observe an object without owning it.

*/

class Animal {
    public:
        void speak()  {
            std::cout << "Animal Speak!!" << std::endl;
        }

        ~Animal() {
            std::cout << "Animal object destroyed!!" << std::endl;
        }
    
    
};

int main(int argc, char *argv[]) {

    // create weak pointer
    std::weak_ptr<Animal> wptr;

    {
        std::shared_ptr<Animal> sptr = std::make_shared<Animal>();
        std::cout << "Address managed by sptr -> " << sptr.get() << std::endl;
        std::cout << "use_count of sptr = " << sptr.use_count() <<  std::endl;
        wptr = sptr;

        // weak_ptr dosent increase reference count
        std::cout << "use_count of sptr after  wptr = sptr:  " << sptr.use_count() <<  std::endl;

        // lock() return shared_ptr is the object is still alive else nullptr
        if(auto lock = wptr.lock()) {
            std::cout <<  "object is still alive" <<  std::endl;
            lock->speak();
        }


        // Clears the weak_ptr manually
        //wptr.reset();
    } // going out of scope now share_ptr is destroyed

    
    if(wptr.expired()) {
        std::cout << "After scope:  shared_ptr(sptr) is destroyed, weak_ptr(wptr) expired!" << std::endl;
    }
    else {
        std::cout << "Animal object is still alive" << std::endl;
    }

    
    return 0;

}