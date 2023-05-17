#include "Point.hpp"

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
    Point& Point::moveTowards(Point& current, Point& target, double distance) {
        double dx = target.Xco - current.Xco;
        double dy = target.Yco - current.Yco;
        double totalDistance = sqrt(dx * dx + dy * dy);

        if (totalDistance <= distance) {
            // The target point is within or at the desired distance
            current = target;
        } else {
            double ratio = distance / totalDistance;
            double newX = current.Xco + dx * ratio;
            double newY = current.Yco + dy * ratio;
            current.Xco = newX;
            current.Yco = newY;
        }

        return current;
    }

    // Print the coordinates of the point
    std::string Point::print() {
        return "(" + std::to_string(Xco) + ", " + std::to_string(Yco) + ")";
    }
}
