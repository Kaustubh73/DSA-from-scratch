#include <bits/stdc++.h>

using namespace std;

class Point {
    public:
        int x, y;
        Point(int px = 0, int py = 0) {
            x = px;
            y = py;
        }
};

double distance(Point p1, Point p2)
{
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

double stripClosest(vector<Point>& strip, double d)
{
    int n = strip.size();
    sort(strip.begin(), strip.end(), [](const Point& p1, const Point& p2) {
        return p1.y < p2.y;
    });

    double minDist = d;

    for (int i = 0; i < n ; ++i)
    {
        for (int j = i + 1; j < n && (strip[j].y - strip[i].y) < minDist ; ++j) {
            minDist = min(minDist, distance(strip[i], strip[j]));
        }
    }
    return minDist;
}

double closestUtil(vector<Point>& points, int l, int r) {
    if (r - l <= 3) {
        double minDist = INT_MAX;
        for (int i = l ; i <= r; ++i) {
            for (int j = i + 1; j <= r ; ++j)
            {
                minDist = min(minDist, distance(points[i], points[j]));
            }
        }
        return minDist;
    }

    int mid = (l + r) / 2;
    Point midPoint = points[mid];

    double dl = closestUtil(points, l, mid);
    double dr = closestUtil(points, mid+1, r);
    double d = min(dl, dr);

    vector<Point> strip;
    for (int i = l ; i <= r ; ++i) {
        if (abs(points[i].x - midPoint.x) < d) {
            strip.push_back(points[i]);
        }
    }

    return min(d, stripClosest(strip, d));
}

double closestPair(vector<Point>& points) {
    sort(points.begin(), points.end(), [](const Point& p1, const Point& p2) {
        return p1.x < p2.x;
    });

    return closestUtil(points, 0, points.size() - 1);
}

int main() {
    vector<Point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};

    double minDist = closestPair(points);
    cout << "The closest pair of points distance is: " << minDist << endl;

    return 0;
}