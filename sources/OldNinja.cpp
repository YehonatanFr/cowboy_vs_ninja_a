#include "OldNinja.hpp"

using namespace std;

namespace ariel {
    OldNinja::OldNinja(const Point& location)
        : Ninja(location, 150, "Old Ninja", 8) {}

    void OldNinja::print(){
        cout << "Old Ninja - ";
        Ninja::print();
    }
}
