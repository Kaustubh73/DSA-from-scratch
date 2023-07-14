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

class line2D {
    public:
        double a, b, c;
        line2D(double a, double b, double c): a(a), b(b), c(c) {}
};

double e = 1e-9;
double det(double a, double b, double c, double d){
    return a*d - b*c;
}

bool intersect(line2D m, line2D n, point2D& res)
{
    double den = det(m.a, m.b, n.a, n.b);
    if (abs(den) < e) return false;
    res = point2D(-det(m.c, m.b, n.c, n.b) / den, -det(m.a,m.c,n.a,n.c)/ den);
    return true;
}

bool parallel(line2D m, line2D n)
{
    return abs(det(m.a,m.b,n.a,n.b)) < e;
}

bool equivalent(line2D m, line2D n)
{
    return (abs(det(m.a, m.b, n.a, n.b)) < e && abs(det(m.a, m.c, n.a, n.c)) < e && abs(det(m.b, m.c, n.b, n.c)) < e);

}

int main() 
{
    line2D m(1,2,1);
    line2D n(2,3,5);
    point2D res;
    intersect(m,n,res);

    cout << res.getX() << " " << res.getY() << endl;
    return 0;
}