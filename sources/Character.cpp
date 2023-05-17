#include "Character.hpp"
#include "Point.hpp"
#include <iostream>

using namespace std;

namespace ariel {
    Character::Character(const Point& location, int hitPoints, const string& name)
        : location(location), hitPoints(hitPoints), name(name) {}

    bool Character::isAlive() const {
        return hitPoints > 0;
    }

    double Character::distance(Character* other) {
        return location.distance(other->getLocation());
    }

    void Character::hit(int damage) {
        hitPoints -= damage;
        if (hitPoints < 0) {
            hitPoints = 0;
        }
    }

    string Character::getName() const {
        return name;
    }

    Point Character::getLocation() const {
        return location;
    }

    void Character::setLocation(const Point& loca) {
        location = loca;
    }

    string Character::print() {
        cout << name << " - Hit Points: " << hitPoints << ", Location: ";
        location.print();
    }

}
