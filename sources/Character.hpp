#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <string>

namespace ariel {
    class Character {
    private:
        Point location;
        int hitPoints;
        std::string name;

    public:
        Character(const Point& location, int hitPoints, const std::string& name);

        bool isAlive() const;

        double distance(Character* other);

        void hit(int damage);

        std::string getName() const;

        Point getLocation() const;

        void setLocation(const Point& loca);

        std::string print();
    };
}

#endif
