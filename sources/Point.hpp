#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>
#include <cmath>

namespace ariel{
    class Point{
        private:
            double Xco;
            double Yco;

        public:
            Point();
            
            Point(double Xco, double Yco);

            double distance(const Point& other);
            
            Point moveTowards(Point current, Point target, double distance);
            
            double getX() const{
                return Xco;
            }

            double getY() const{
                return Yco;
            }


            void setX(double x){
                Xco = x;
            }

            void setY(double y){
                Yco = y;
            }

            std::string print();
    };
}

#endif