#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Ninja.hpp"

namespace ariel {
    class OldNinja : public Ninja {
    public:
        OldNinja(const Point& location);

        void print();
    };
}

#endif
