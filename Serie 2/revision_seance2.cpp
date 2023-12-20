#include <iostream>
using namespace std;

class Mclass{
    int a;
    int b;
    static int cpt;
    double *tab;
    int taille;
public:
    Mclass():a(0), b(0){
        cpt++;
        taille = 5;
        tab = new double[taille];
        cout<<"par default: "<<this<<endl;
    }
    Mclass(int a, int b, int taille):a(a), b(b){
        cpt++;
        this->taille = taille;
        tab = new double[taille];
        cout<<"par param: "<<this<<endl;
    }
    Mclass(const Mclass &c){
        a = c.a;
        b = c.b;
        cpt++;
        taille = c.taille;
        tab = new double[taille];
        for(int i = 0; i< taille; i++){
            tab[i] = c.tab[i];
        }
        cout<<"de copie: "<<this<<endl;
    }
    ~Mclass(){
        cpt--;
        delete [] tab;
        cout<<"Destructeur: "<<cpt<<" "<<this<<endl;
    }
    friend istream& operator>>(istream &i, Mclass &c){
        cout<<"a: ";
        i>>c.a;
        cout<<"b: ";
        i>>c.b;
        cout<<"La taille: ";
        i>>c.taille;
        cout<<"Les valeurs: "<<endl;
        for(int j = 0; j< c.taille; j++){
            i>>c.tab[j];
        }
        return i;
    }
    friend ostream& operator<<(ostream &o, const Mclass &c){
        o<<c.a<<endl;
        o<<c.b<<endl;
        for(int j = 0; j< c.taille; j++){
            o<<c.tab[j]<<",";
        }
        o<<endl;
        return o;
    }
};
int Mclass::cpt = 0;
int main(){
    Mclass c1;
    Mclass c2(1, 2, 3);
    Mclass c3 = c2;
    cin>>c1;
    
    cout<<"c1:"<<endl<<c1;
    cout<<"c2:"<<endl<<c2;
    cout<<"c3:"<<endl<<c3;
    return 0;
}
