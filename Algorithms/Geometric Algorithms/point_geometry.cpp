#include <bits/stdc++.h>
using namespace std;

class point2D {
    private:
        double x,y;
    public:
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

class point3D {
    private:
        double x,y,z;
    public:
        point3D(double x, double y, double z): x(x), y(y), z(z) {}

        double getX() { return x; }
        double getY() { return y; }
        double getZ() { return z; }
        point3D& operator+=(const point3D &t) {
            x += t.x;
            y += t.y;
            z += t.z;
            return *this;
        }
        point3D& operator-=(const point3D &t) {
            x -= t.x;
            y -= t.y;
            z -= t.z;
            return *this;
        }
        point3D& operator*=(double t) {
            x *= t;
            y *= t;
            z *= t;
            return *this;
        }
        point3D& operator/=(double t) {
            x /= t;
            y /= t;
            z /= t;
            return *this;
        }
        point3D operator+(const point3D &t) { return point3D(*this) += t;}
        point3D operator-(const point3D &t) { return point3D(*this) -= t;}
        point3D operator*(double t) const { return point3D(*this) *= t;}
        point3D operator/(double t) const { return point3D(*this) /= t;}

};

point3D operator*(double a, point3D b) {
    return b * a;
}

double dot(point2D a, point2D b) {
    return a.getX() * b.getX() + a.getY() * b.getY();
}

double dot(point3D a, point3D b) {
    return a.getX() * b.getX() + a.getY() * b.getY() + a.getZ() * b.getZ();
}

double norm(point2D a) {
    return dot(a, a);
}

double abs(point2D a) {
    return sqrt(norm(a));
}

double proj(point2D a, point2D b) {
    return dot(a, b) / abs(b);
}

double angle(point2D a, point2D b) {
    return acos(dot(a, b) / abs(a) / abs(b));
}

double cross(point2D a, point2D b) {
    return a.getX() * b.getY() - a.getY() * b.getX();
}
point3D cross(point3D a, point3D b) {
    return point3D(a.getY() * b.getZ() - a.getZ() * b.getY(), a.getZ() * b.getX() - a.getX() * b.getZ(), a.getX() * b.getY() - a.getY() * b.getX());
}

double triple(point3D a, point3D b, point3D c)
{
    return dot(a, cross(b,c));
}

point2D intersect(point2D a1, point2D d1, point2D a2, point2D d2) {
    return a1 + cross(a2 - a1, d2) / cross(d1,d2) * d1;
}

point3D intersect(point3D a1, point3D n1, point3D a2, point3D n2, point3D a3, point3D n3) {
    point3D x(n1.getX(), n2.getX(), n3.getX());
    point3D y(n1.getY(), n2.getY(), n3.getY());
    point3D z(n1.getZ(), n2.getZ(), n3.getZ());
    point3D d(dot(a1, n1), dot(a2,n2), dot(a3,n3));
    return point3D(triple(d,y,z), triple(x,d,z), triple(x,y,d)) / triple(n1,n2,n3);

}

int main()
{
    point2D p1(12,0);
    point2D p2(43,0);
    p1 -= p2;
    point2D p3 = p1 * 43;
    cout << p1.getX() << " " << p1.getY() << endl;
    cout << p3.getX() << " " << p3.getY() << endl;
    point3D g1(12,0,0);
    point3D g2(43,0,41);
    g1 -= g2;
    point3D g3 = g1 * 43;
    cout << g1.getX() << " " << g1.getY() << g1.getZ() << endl;
    cout << g3.getX() << " " << g3.getY() << g3.getZ() << endl;
    cout << dot(p1, p2) << endl;
    cout << cross(p1, p2) << endl;
    point3D g4 = cross(g1, g2);
    cout << g4.getX() << " " << g4.getY() << " " << g4.getZ() << endl; 
}