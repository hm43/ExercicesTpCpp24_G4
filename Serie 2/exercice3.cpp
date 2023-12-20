#include <iostream>
#include <string>
using namespace std;
class Livre{
private:
    string titre;
    string auteur;
    static int nombreExemplaires;
public:
    static int exemplairesLoues;
    Livre(){
        titre = "";
        auteur = "";
        nombreExemplaires++;
    }
    Livre(string titre, string auteur){
        this->titre = titre;
        this->auteur = auteur;
        nombreExemplaires++;
    }
    static void afficherNombreExemplaires(){
        cout<<nombreExemplaires<<endl;
    }
    static void afficherExemplairesLoues(){
        cout<<exemplairesLoues<<endl;
    }
    friend ostream& operator<<(ostream& o, Livre &l);
    friend istream& operator>>(istream &i, Livre &l);
};

ostream& operator<<(ostream &o, Livre &l){
    o<<l.titre<<" de "<<l.auteur<<endl;
    o<<Livre::nombreExemplaires<<endl;
    o<<Livre::exemplairesLoues<<endl;
    return o;
}
istream& operator>>(istream& i, Livre &l){
    cout<<"Donner le titre: ";
    getline(i, l.titre);
    cout<<"Donner l'auteur: ";
    getline(i, l.auteur);
    return i;
}
int Livre::nombreExemplaires = 0;
int Livre::exemplairesLoues = 0;
int main() {
    Livre livre1("Les Misérables", "Victor Hugo");
    Livre livre2("1984", "George Orwell");
    cout << "Informations initiales du livre 1 :"<<endl << livre1;
    Livre::exemplairesLoues++;
    cout << "Simulation de la location d'un exemplaire: "<<endl;
    Livre::afficherNombreExemplaires();
    Livre::afficherExemplairesLoues();
    cout << "livre 1 :" <<endl<< livre1;
    Livre livre3("Le Petit Prince", "Antoine de Saint-Exupéry");
    cin>>livre3;
    cout << "Nouveau livre ajouté :"<<endl << livre3;
        

    return 0;
}
