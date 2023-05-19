#include "Ninja.hpp"
#include "Character.hpp"
#include "Point.hpp"
#include <iostream>

using namespace std;

namespace ariel {

    Ninja::Ninja(std::string name, const Point& location, int hitPoints, int speed)
    :Character(name,location, hitPoints) ,speed(speed) {}


    void Ninja::move(Character* enemy) {
        return;
        // double distanceToEnemy = distance(enemy);
        // if (distanceToEnemy <= speed) {
        //     location = enemy->getLocation();
        // } else {
        //     Point direction = enemy->getLocation() - getLocation();
        //     direction = direction * (speed / distanceToEnemy);
        //     setLocation (getLocation() + direction);
        // }
    }

    void Ninja::slash(Character* enemy) {
        if (isAlive() && distance(enemy) < 1) {
            enemy->hit(40);
        }
    }

    string Ninja::print() {
        return "";
    }
}
