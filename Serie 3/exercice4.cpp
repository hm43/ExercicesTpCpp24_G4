#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Figure
{
protected:
    double x, y, z;

public:
    Figure(double x = 0, double y = 0, double z = 0) : x(x), y(0), z(0) {}
    Figure(const Figure &f) : x(f.x), y(f.y), z(f.z) {}
    virtual void afficher()
    {
        cout << x << " " << y << " " << z << " ";
    }
    virtual string description()
    {
        return "Figure";
    }
};
class Triangle : public Figure
{
protected:
    double base, cote1, cote2, hauteur;

public:
    Triangle(double x = 0, double y = 0, double z = 0, double base = 0, double cote1 = 0, double cote2 = 0, double hauteur = 0) : Figure(x, y, z), base(base), cote1(cote1), cote2(cote2), hauteur(hauteur) {}
    Triangle(const Triangle &t) : Figure(t.x, t.y, t.z), base(t.base), cote1(t.cote1), cote2(t.cote2), hauteur(t.hauteur) {}
    void afficher()
    {
        Figure::afficher();
        cout << base << " " << hauteur << endl;
    }
    string description()
    {
        return "Triangle";
    }
};
class Carre : public Figure
{
protected:
    double largeur;

public:
    Carre(double x = 0, double y = 0, double z = 0, double largeur = 0) : Figure(x, y, z), largeur(largeur) {}
    Carre(const Carre &c) : Figure(c.x, c.y, c.z), largeur(c.largeur) {}
    void afficher()
    {
        Figure::afficher();
        cout << largeur << endl;
    }
    string description()
    {
        return "Carre";
    }
};
void afficherInfos(Figure &f)
{
    cout << "Je suis un(e) " << f.description() << endl;
    cout << "Mes attributs sont: ";
    f.afficher();
    cout << endl;
}
int main()
{
    Triangle t(0, 0, 0, 5, 2, 3, 8);
    Carre c(0, 0, 0, 4);
    afficherInfos(t);
    afficherInfos(c);
    return 0;
}