#include <bits/stdc++.h>
using namespace std;

class point2D {
    private:
        double x,y;
    public:
        point2D() {}
        point2D(double x, double y): x(x), y(y) {}

        double getX() { return x; }
        double getY() { return y; }
        point2D& operator+=(const point2D &t) {
            x += t.x;
            y += t.y;
            return *this;
        }
        point2D& operator-=(const point2D &t) {
            x -= t.x;
            y -= t.y;
            return *this;
        }
        point2D& operator*=(double t) {
            x *= t;
            y *= t;
            return *this;
        }
        point2D& operator/=(double t) {
            x /= t;
            y /= t;
            return *this;
        }
        point2D operator+(const point2D &t) { return point2D(*this) += t;}
        point2D operator-(const point2D &t) { return point2D(*this) -= t;}
        point2D operator*(double t) const { return point2D(*this) *= t;}
        point2D operator/(double t) const { return point2D(*this) /= t;}

};

point2D operator*(double a, point2D b) {
    return b * a;
}

class lineSeg {
    public:
        point2D p1, p2;
        lineSeg(point2D& p1, point2D& p2) : p1(p1), p2(p2) {}

        double length() {
            double dx = p1.getX() - p2.getX();
            double dy = p1.getY() - p2.getY();
            return sqrt(dx*dx + dy*dy);
        }

        bool isParallelTo(lineSeg& other) {
            double dx1 = p1.getX() - p2.getX();
            double dy1 = p1.getY() - p2.getY();
            double dx2 = other.p1.getX() - other.p2.getX();
            double dy2 = other.p1.getY() - other.p2.getY();

            return (dx1 * dy2 == dx2 * dy1);
        }

        bool isPerpendicularTo(lineSeg& other) {
            double dx1 = p1.getX() - p2.getX();
            double dy1 = p1.getY() - p2.getY();
            double dx2 = other.p1.getX() - other.p2.getX();
            double dy2 = other.p1.getY() - other.p2.getY();

            return (dx1 * dx2 + dy1 * dy2 == 0);
        }

        double dotProduct(lineSeg& other) {
            double dx1 = p1.getX() - p2.getX();
            double dy1 = p1.getY() - p2.getY();
            double dx2 = other.p1.getX() - other.p2.getX();
            double dy2 = other.p1.getY() - other.p2.getY();

            return dx1 * dx2 + dy1 * dy2;
        }
        double angleWith(lineSeg& other) {
            double len1 = length();
            double len2 = other.length();
            double dot = dotProduct(other);

            double cosAngle = dot / (len1 * len2);
            double angleRad = acos(cosAngle);
            double angleDeg = angleRad * 180.0 / M_PI;

            return angleDeg;
        }
};


int main() {
    point2D p1(1.0, -1.0);
    point2D p2(-1.0, 0.0);
    point2D p3(1.0, 1.0);
    point2D p4(2.0, -3.0);

    lineSeg line1(p1, p2);
    lineSeg line2(p3, p4);

    std::cout << "Line 1 length: " << line1.length() << std::endl;
    std::cout << "Line 2 length: " << line2.length() << std::endl;

    if (line1.isParallelTo(line2)) {
        std::cout << "Line 1 is parallel to Line 2" << std::endl;
    } else {
        std::cout << "Line 1 is not parallel to Line 2" << std::endl;
    }

    if (line1.isPerpendicularTo(line2)) {
        std::cout << "Line 1 is perpendicular to Line 2" << std::endl;
    } else {
        std::cout << "Line 1 is not perpendicular to Line 2" << std::endl;
    }

    double angle = line1.angleWith(line2);

    std::cout << "Angle between Line 1 and Line 2: " << angle << " degrees" << std::endl;

    return 0;
}