#include<iostream>
#include <string>
#include <vector>

using namespace std;

class Camion {
public:
    string idc;
    string modele;
    double capacite;
    double km;
    string statut;
public:
    Camion(){
        idc = "";
        modele = "";
        capacite = 0;
        km = 0;
        statut = "";
    }
    Camion(string idc, string modele){
        this->idc = idc;
        this->modele = modele;
        capacite = 0;
        km = 0;
        statut = "";
    }
    Camion(string idc, string modele, double capacite, double km, string statut){
        this->idc = idc;
        this->modele = modele;
        this->capacite = capacite;
        this->km = km;
        this->statut = statut;
    }
    string getIdc(){
        return idc;
    }
    void setIdc(string idc){
        this->idc = idc;
    }
    string getStatut(){
        return statut;
    }
    void setStatut(string statut){
        this->statut = statut;
    }
    // Les autres ici
    
    void afficher(){
        cout<<"L'id: "<<idc<<endl;
        cout<<"Le modele: "<<modele<<endl;
        cout<<"La capacite: "<<capacite<<endl;
        cout<<"Le kilometrage: "<<km<<endl;
        cout<<"Le statut: "<<statut<<endl;
    }
};

class GestionnaireDeFlotte{
private:
    string nom;
    vector<Camion> flotte;
public:
    GestionnaireDeFlotte(){
        nom = "";
    }
    GestionnaireDeFlotte(string nom){
        this->nom = nom;
    }
    void ajouterCamion(){
        string idc, modele, statut;
        double capacite, km;
        int choix;
        cout<<"1. Pas d'information."<<endl;
        cout<<"2. Pour l'id et modele."<<endl;
        cout<<"3. Pour toutes les informations."<<endl;
        cin>>choix;
        switch (choix) {
            case 1:
                {
                    Camion c;
                    flotte.push_back(c);
                    break;
                }
            case 2:
            {
                cout<<"Donner l'id: ";
                cin.ignore();
                getline(cin, idc);
                cout<<"Donner le modele: ";
                getline(cin, modele);
                Camion c2(idc, modele);
                flotte.push_back(c2);
                break;
            }
            case 3:
            {
                cout<<"Donner l'id: ";
                cin.ignore();
                getline(cin, idc);
                cout<<"Donner le modele: ";
                getline(cin, modele);
                cout<<"Donner la capacite: ";
                cin>>capacite;
                cout<<"Donner le kilometrage: ";
                cin>>km;
                cout<<"Donner le statut: ";
                cin.ignore();
                getline(cin, statut);
                Camion c3(idc, modele, capacite, km, statut);
                flotte.push_back(c3);
                break;
            }
            default:
                cout<<"Mauvais choix."<<endl;
                break;
        }
    }
    void majStatut(){
        string idc;
        cout<<"Donner l'id: ";
        cin.ignore();
        getline(cin, idc);
        
        for(Camion &c: flotte){
            if(c.getIdc().compare(idc) == 0){
                string statut;
                cout<<"Donner le statut: ";
                getline(cin, statut);
                c.setStatut(statut);
                break;
            }
        }
    }
    void afficher(){
        cout<<"Le nom: "<<nom<<endl;
        for(Camion &c: flotte){
            c.afficher();
        }
    }
};

int main2(){
    GestionnaireDeFlotte g("X");
    int choix;
    do{
        cout<<"     Menu"<<endl;
        cout<<"1. Enregistrer un nouveau camion dans la flotte."<<endl;
        cout<<"2. Mettre à jour le statut d'un camion existant."<<endl;
        cout<<"3. Afficher les camions."<<endl;
        cout<<"4. Quitter."<<endl;
        cout<<">> ";
        cin>>choix;
        switch (choix) {
            case 1:
                g.ajouterCamion();
                break;
            case 2:
                g.majStatut();
                break;
            case 3:
                g.afficher();
                break;
            case 4:
                cout<<"Au revoir!"<<endl;
                break;
            default:
                cout<<"Mauvais choix."<<endl;
                break;
        }
    }while(choix != 4);
    
    return 0;
}
