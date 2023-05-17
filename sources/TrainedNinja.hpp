#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#include "Ninja.hpp"

namespace ariel {
    class TrainedNinja : public Ninja {
    public:
        TrainedNinja(const Point& location);

        void print();
    };
}

#endif
