#include "Team2.hpp"

using namespace std;

namespace ariel{

    Team2::Team2(Character *leader) 
    : leader(leader) {}

    // Team2::~Team2() {
    //     destroy();
    // }

    void Team2::add(Character* character) {
        members.push_back(character);
    }

    void Team2::attack(Team2* enemyTeam) {
        // Implement the attack logic
    }

    int Team2::stillAlive() const {
        int count = 0;
        for (const auto& member : members) {
            if (member->isAlive()) {
                count++;
            }
        }
        return count;
    }

    string Team2::print() {
        string output;
        for (const auto& member : members) {
            output += member->print() + "\n";
        }
        return output;
    }

    // void Team2::destroy() {
    //     for (auto& member : members) {
    //         delete member;
    //     }
    //     members.clear();
    //     leader = nullptr;
    // }
}
