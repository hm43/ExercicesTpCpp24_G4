#include<iostream>
#include<string>
#include<cmath>

using namespace std;
class Point{
    private:
        double x;
        double y;
    public:
        Point(){
            cout<<"constructeur par default."<<endl;
            x = 0;
            y = 0;
        }
        Point(double x, double y){
            cout<<"constructeur d'initialisation."<<endl;
            this->x = x;
            this->y = y;
        }
        double getX(){
            return x;
        }
        void setX(double x){
            this->x = x;
        }
        double getY(){
            return y;
        }
        void setY(double y){
            this->y = y;
        }
        string coord(){
            string str = "("+to_string(x)+","+to_string(y)+")";
            return str;
        }

        float distance(Point &p){
            float d = sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
            return d;
        }

};


int main(){
    Point p;
    Point p2(7.9, -4);
    
    cout<<"La distance entre "<<p.coord()<<" et "<<p2.coord();
    cout<<" est: "<<p.distance(p2)<<endl;
    return 0;
}