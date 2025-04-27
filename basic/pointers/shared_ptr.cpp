#include <iostream>
#include <memory>

using namespace std;

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

    std::shared_ptr<Animal> sptr1 = std::make_shared<Animal>();

    std::cout << "Address managed by sptr1 -> " << sptr1.get() << std::endl;
    
    // use_count
    std::cout << "use_count = " << sptr1.use_count() <<  std::endl;

    std::shared_ptr<Animal> sptr2 = sptr1;

    std::cout << "Address managed by sptr1 -> " << sptr1.get() << std::endl;
    std::cout << "Address managed by sptr2 -> " << sptr2.get() << std::endl;

    std::cout << "use_count = " << sptr1.use_count() <<  std::endl;

    // reset decreses reference count
    sptr2.reset();
    std::cout << "After reset use_count of sptr1 = " << sptr1.use_count() <<  std::endl;
    std::cout << "After reset use_count of sptr2 = " << sptr2.use_count() <<  std::endl;

    if(!sptr2) {
        std:: cout << "After reset sptr2 is empty, null pointer " << std::endl;
    }

    std::shared_ptr<Animal> sptr3(new Animal());
    
    std::cout << "Address managed by sptr1 -> " << sptr1.get() << std::endl;
    std::cout << "Address managed by sptr3 -> " << sptr3.get() << std::endl;

    sptr3.swap(sptr1);
    std::cout << "Address managed by sptr1 -> " << sptr1.get() << std::endl;
    std::cout << "Address managed by sptr3 -> " << sptr3.get() << std::endl;


    return 0;

}