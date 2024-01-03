#include<iostream>
#include <string>
using namespace std;

class Employe{
    string nom;
    int age;
    double salaire;
public:
    Employe(): nom(""), age(0), salaire(0){}
    Employe(string n, int a, double s): nom(n), age(a), salaire(s){}
    Employe(const Employe &e){
        nom = e.nom;
        age = e.age;
        salaire = e.salaire;
    }
    void afficherInformation(){
        cout<<"Nom: "<<nom<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Salaire: "<<salaire<<endl;
    }
    
};
class Manager: public Employe{
    int nbrEmployees;
public:
    Manager(string nom, int age, double salaire, int nbr):Employe(nom, age, salaire), nbrEmployees(nbr){}
};
class Technicien: public Employe{
    string competence;
public:
    Technicien(string nom, int age, double salaire, string c):Employe(nom, age, salaire), competence(c){}
};
class Directeur: public Employe{
    string strategie;
public:
    Directeur(string nom, int age, double salaire, string s):Employe(nom, age, salaire), strategie(s){}
};

int main() {
    // Création des instances d'employés
    Manager manager("Alice", 42, 80000, 5);
    Technicien technicien("Bob", 35, 55000, "Informatique");
    Directeur directeur("Charlie", 50, 120000, "Expansion Globale");

    // Affichage des informations des employés
    manager.afficherInformation();
    technicien.afficherInformation();
    directeur.afficherInformation();

    return 0;
}
