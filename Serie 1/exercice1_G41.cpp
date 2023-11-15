#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Point
{
private:
    float x;
    float y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    float getX()
    {
        return x;
    }
    void setX(float x)
    {
        this->x = x;
    }
    float getY()
    {
        return y;
    }
    void setY(float y)
    {
        this->y = y;
    }
    string afficher()
    {
        string str = "(" + to_string(x) + "," + to_string(y) + ")";
        return str;
    }
    float distance(Point &p)
    {
        float d = sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
        return d;
    }
};
int main()
{
    Point p1;
    Point p2(2, -3);
    cout << "La distance entre " << p1.afficher() << " et " << p2.afficher();
    cout << " est: " << p1.distance(p2) << endl;
    return 0;
}