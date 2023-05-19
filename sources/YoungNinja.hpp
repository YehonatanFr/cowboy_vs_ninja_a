#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#include "Ninja.hpp"

namespace ariel {
    class YoungNinja : public Ninja {
    public:

        YoungNinja(std::string name, const Point& location);

        std::string print();
    };
}

#endif
