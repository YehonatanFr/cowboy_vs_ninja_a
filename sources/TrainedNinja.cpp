#include "TrainedNinja.hpp"

using namespace std;

namespace ariel {
    TrainedNinja::TrainedNinja(const Point& location)
    : Ninja(location, 120, "Trained Ninja", 12) {}

    void TrainedNinja::print(){
        cout << "Trained Ninja - ";
        Ninja::print();
    }

}