#include "Ninja.hpp"
#include "Character.hpp"
#include "Point.hpp"
#include <iostream>

using namespace std;

namespace ariel {
    Ninja::Ninja(const Point& location, int hitPoints, const string& name, int speed)
        : Character(location, hitPoints, name), speed(speed) {}

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
        cout << "Ninja - ";
        Character::print();
        std::cout << ", Speed: " << speed << endl;
    }
}
