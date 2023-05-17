#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"

namespace ariel {
    class Ninja : public Character {
    protected:
        int speed;

    public:
        Ninja(const Point& location, int hitPoints, const std::string& name, int speed);

        void move(Character* enemy);

        void slash(Character* enemy);

        std::string print();
    };
}

#endif
