#ifndef TEAM_HPP
#define TEAM_HPP

#include "Point.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include <vector>
#include "Character.hpp"

namespace ariel {
    class Team {
    private:
        std::vector<Character*> members;
        Character* leader;

    public:
        explicit Team(Character* leader);
        // ~Team();

        void add(Character* character);
        void attack(Team* enemyTeam);
        int stillAlive();
        
        std::string print();
    };
}

#endif
