#include "Point.hpp"

using namespace std;

namespace ariel {
    // Default constructor
    Point::Point() : Xco(0), Yco(0) {}

    // Parameterized constructor
    Point::Point(double Xco, double Yco) : Xco(Xco), Yco(Yco) {}

    

    // Calculate the distance between two points
    double Point::distance(const Point& other) {
        double dx = Xco - other.Xco;
        double dy = Yco - other.Yco;
        return sqrt(dx * dx + dy * dy);
    }

    // Move towards a point by a given distance
    Point Point::moveTowards(Point current, Point target, double distance) {
        double currentDistance = current.distance(target);
        
        Point newPosition = current;

        if (currentDistance > distance) {
            double ratio = distance / currentDistance;
            double dx = target.getX() - current.getX();
            double dy = target.getY() - current.getY();
            newPosition.setX(current.getX() + dx * ratio);
            newPosition.setY(current.getY() + dy * ratio);
        } 
        else {
            newPosition = target;
        }

        return newPosition;
    }



    // Print the coordinates of the point
    string Point::print() {
        return "(" + to_string(Xco) + ", " + to_string(Yco) + ")";
    }
}
