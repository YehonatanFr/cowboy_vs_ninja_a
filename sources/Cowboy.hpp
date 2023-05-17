#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"

namespace ariel {
    class Cowboy : public Character {
    private:
        int bullets;

    public:
        Cowboy(const Point& location, int hitPoints, const std::string& name, int bullets);

        void shoot(Character* enemy);

        bool hasBullets() const;

        void reload();

        void print() const override;
    };
}

#endif
