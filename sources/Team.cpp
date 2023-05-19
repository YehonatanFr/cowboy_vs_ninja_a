#include "Team.hpp"

using namespace std;

namespace ariel{

    Team::Team(Character *leader)
    : leader(leader){}

    void Team::add(Character* character)
    {
    }

    void Team::attack(Team* enemyTeam)
    {
    }

    int Team::stillAlive()
    {
        return 0;
    }

    string Team::print()
    {
        return "";
    }
}

