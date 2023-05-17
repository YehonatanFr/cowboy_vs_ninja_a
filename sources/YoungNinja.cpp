#include "YoungNinja.hpp"

using namespace std;

namespace ariel {
    YoungNinja::YoungNinja(const Point& location)
        : Ninja(location, 100, "Young Ninja", 14) {}

    void YoungNinja::print(){
        cout << "Young Ninja - ";
        Ninja::print();
    }
}
