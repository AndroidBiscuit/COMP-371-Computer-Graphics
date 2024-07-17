#ifndef POINT_H
#define POINT_H

class Point {
    private:
        double x, y, z;
    
    public:
        // Constructors for the pointer class
        Point();
        Point(double x, double y, double z);

        // Getters
        double getX();
        double getY();
        double getZ();

        // Setters
        void setX(double x);
        void setY(double y);
        void setZ(double z);

        // Other functions
        int translate(int d, char axis);
        double distanceFromPoint(Point& nextPoint);
};

#endif // POINT_H