#include "doctest.h"

#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/Point.hpp"
#include "sources/Character.hpp"
#include "sources/Cowboy.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/OldNinja.hpp"
#include "sources/Ninja.hpp"
#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace ariel;


TEST_CASE("Point - Constructor") {
    SUBCASE("Default Constructor") {
        Point p;
        CHECK(p.getX() == 0.0);
        CHECK(p.getY() == 0.0);
    }

    SUBCASE("Constructor with coordinates") {
        Point p(3.5, 2.0);
        CHECK(p.getX() == 3.5);
        CHECK(p.getY() == 2.0);
    }
}

TEST_CASE("Point - distance") {
    Point p1(0.0, 0.0);
    Point p2(3.0, 4.0);
    Point p3(1.0, 1.0);

    CHECK(p1.distance(p2) == 5.0);
    CHECK(p2.distance(p1) == 5.0);
    CHECK(p1.distance(p3) == 1.41421);
    CHECK(p3.distance(p2) == 3.60555);
}

TEST_CASE("Point - moveTowards") {
    Point p1(1.0, 1.0);
    Point p2(5.0, 5.0);
    Point p3(3.0, 3.0);
    double distance = 2.0;

    Point result = p1.moveTowards(p1, p2, distance);
    CHECK(result.getX() == 2.41421);
    CHECK(result.getY() == 2.41421);

    result = p1.moveTowards(p1, p3, distance);
    CHECK(result.getX() == 2.41421);
    CHECK(result.getY() == 2.41421);

    result = p1.moveTowards(p1, p2, 10.0);
    CHECK(result.getX() == 5.0);
    CHECK(result.getY() == 5.0);
}

TEST_CASE("Character - Constructor")
{
    SUBCASE("Valid inputs")
    {
        Point location(1.0, 2.0);
        Character character("John", location, 100);
        CHECK(character.getName() == "John");
        CHECK(character.getLocation().getX() == 1.0);
        CHECK(character.getLocation().getY() == 2.0);
        CHECK(character.isAlive());
    }

    SUBCASE("Empty name")
    {
        Point location(1.0, 2.0);
        Character character("", location, 100);
        CHECK(character.getName().empty());
        CHECK(character.getLocation().getX() == 1.0);
        CHECK(character.getLocation().getY() == 2.0);
        CHECK(character.isAlive());
    }
}

TEST_CASE("Character - isAlive")
{
    SUBCASE("Alive character")
    {
        Point location(1.0, 2.0);
        Character character("John", location, 100);
        CHECK(character.isAlive());
    }

    SUBCASE("Dead character")
    {
        Point location(1.0, 2.0);
        Character character("John", location, 0);
        CHECK_FALSE(character.isAlive());
    }
}

TEST_CASE("Character - distance")
{
    Point location1(1.0, 2.0);
    Point location2(4.0, 6.0);

    SUBCASE("Distance between two points")
    {
        Character character1("John", location1, 100);
        Character character2("Jane", location2, 100);
        double expectedDistance = location1.distance(location2);
        double distance = character1.distance(&character2);
        CHECK(abs(distance - expectedDistance) < 0.001); // Tolerance of 0.001

    }
}

TEST_CASE("Character - hit")
{
    Point location(1.0, 2.0);
    Character character("John", location, 100);

    SUBCASE("Hit with positive damage")
    {
        int damage = 20;
        character.hit(damage);
        CHECK(character.isAlive());
        CHECK(character.getHitPoints() == 80);
    }

    SUBCASE("Hit with zero damage")
    {
        int damage = 0;
        character.hit(damage);
        CHECK(character.isAlive());
        CHECK(character.getHitPoints() == 100);
    }

    SUBCASE("Hit with negative damage")
    {
        int damage = -10;
        character.hit(damage);
        CHECK(character.isAlive());
        CHECK(character.getHitPoints() == 100);
    }

    SUBCASE("Hit with damage exceeding hit points")
    {
        int damage = 150;
        character.hit(damage);
        CHECK_FALSE(character.isAlive());
        CHECK(character.getHitPoints() == 0);
    }
}

TEST_CASE("Character - getName")
{
    Point location(1.0, 2.0);
    Character character("John", location, 100);
    CHECK(character.getName() == "John");
}

TEST_CASE("Character - getLocation")
{
    Point location(1.0, 2.0);
    Character character("John", location, 100);
    CHECK(character.getLocation().getX() == 1.0);
    CHECK(character.getLocation().getY() == 2.0);
}

TEST_CASE("Character - setLocation")
{
    Point location(1.0, 2.0);
    Character character("John", location, 100);

    Point newLocation(3.0, 4.0);
    character.setLocation(newLocation);
    CHECK(character.getLocation().getX() == 3.0);
    CHECK(character.getLocation().getY() == 4.0);
}

TEST_CASE("Ninja class") {
    SUBCASE("Constructor") {
        Point location(1.0, 2.0);
        Ninja ninja("John", location, 100, 10);

        CHECK(ninja.getName() == "John");
        CHECK(ninja.getLocation().getX() == 1.0);
        CHECK(ninja.getLocation().getY() == 2.0);
        CHECK(ninja.getHitPoints() == 100);
    }

    SUBCASE("Move") {
        Point location(1.0, 2.0);
        Ninja ninja("John", location, 100, 10);

        Point enemyLocation(5.0, 6.0);
        Character enemy("Enemy", enemyLocation, 100);
        ninja.move(&enemy);

        CHECK(ninja.getLocation().getX() == 5.0);
        CHECK(ninja.getLocation().getY() == 6.0);
    }

    SUBCASE("Slash") {
        Point location(1.0, 2.0);
        Ninja ninja("John", location, 100, 10);

        Point enemyLocation(5.0, 6.0);
        Character enemy("Enemy", enemyLocation, 100);
        ninja.slash(&enemy);

        CHECK(enemy.getHitPoints() < 100);
    }

}


