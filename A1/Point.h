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
        double getX() const;
        double getY() const;
        double getZ() const;

        // Setters
        double setX(double x);
        double setY(double y);
        double setZ(double z);
};

#endif // POINT_H