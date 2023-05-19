#include "Character.hpp"
#include "Point.hpp"
#include <iostream>

using namespace std;

namespace ariel {

    Character::Character(string name, const Point& location, int hitPoints)
    : name(name), location(location), hitPoints(hitPoints) {}


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
        return name + " - Hit Points: " + std::to_string(hitPoints) + ", Location: " + location.print();
    }


}
