#include "Cowboy.hpp"

using namespace std;

namespace ariel {

    Cowboy::Cowboy(std::string name, Point location) 
    :Character(name, location, 110), bullets(6){}


    void Cowboy::shoot(Character* enemy) {
        if (isAlive() && hasBullets()) {
            enemy->hit(10);
            bullets--;
        }
    }

    bool Cowboy::hasBullets(){
        return bullets > 0;

    }

    void Cowboy::reload() {
        bullets = 6;
    }

    string Cowboy::print(){
        return "" ;
        // std::cout << "C - ";
        // Character::print();
        // std::cout << ", Bullets: " << bullets << std::endl;
    }
}
