#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Point.hpp"
#include "Character.hpp"
#include <vector>
#include <string>

namespace ariel {
    class Team2 {
    private:
        std::vector<Character*> members;
        Character* leader;

    public:
        explicit Team2(Character* leader);
        // ~Team2();

        void add(Character* character);
        void attack(Team2* enemyTeam);
        int stillAlive() const;
        std::string print();
        // void destroy();
    };
}

#endif
