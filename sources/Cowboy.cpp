#include "Cowboy.hpp"

namespace ariel {
    Cowboy::Cowboy(const Point& location, int hitPoints, const std::string& name, int bullets)
        : Character(location, hitPoints, name), bullets(bullets) {}

    void Cowboy::shoot(Character* enemy) {
        if (isAlive() && hasBullets()) {
            enemy->hit(10);
            bullets--;
        }
    }

    bool Cowboy::hasBullets() const {
        return bullets > 0;
    }

    void Cowboy::reload() {
        bullets = 6;
    }

    void Cowboy::print() const {
        std::cout << "C - ";
        Character::print();
        std::cout << ", Bullets: " << bullets << std::endl;
    }
}
