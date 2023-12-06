#include<iostream>
#include <vector>
#include <string>
using namespace std;
class Camion{
private:
    string idc;
    string modele;
    double cap;
    double km;
    string statut;
    
public:
    Camion(){
        idc = "";
        modele = "";
        cap = 0;
        km = 0;
        statut = "";
    }
    Camion(string idc, string modele){
        this->idc = idc;
        this->modele = modele;
        cap = 0;
        km = 0;
        statut = "";
    }
    Camion(string idc, string modele, double cap, double km, string statut){
        this->idc = idc;
        this->modele = modele;
        this->cap = cap;
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
    void afficher(){
        cout<<"L'id: "<<idc<<endl;
        cout<<"Le modele: "<<modele<<endl;
        cout<<"La capacite en ton: "<<cap<<endl;
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
        string idc;
        string modele;
        double cap;
        double km;
        string statut;
        int choix;
        
        cout<<"1. Pas d'information."<<endl;
        cout<<"2. Pour saisir l'id et le modele."<<endl;
        cout<<"3. Pour saisir toutes les informations."<<endl;
        cin>>choix;
        switch(choix){
            case 1:
            {
                Camion c1;
                flotte.push_back(c1);
                break;
            }
            case 2:
            {
                cout<<"Donner l'id: ";
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
                cin>>cap;
                cout<<"Donner le kilometrage: ";
                cin>>km;
                cout<<"Donner le statut: ";
                cin.ignore();
                getline(cin, statut);
                Camion c3(idc, modele, cap, km, statut);
                flotte.push_back(c3);
                break;
            }
            default:
                cout<<"Mauvais choix."<<endl;
        }
        
    }
    void majStatut(){
        string idc;
        cout<<"Donner l'id du camion a modifier: ";
        cin.ignore();
        getline(cin, idc);
        
        for(auto &e: flotte){
            if(e.getIdc().compare(idc) == 0){
                string statut;
                cout<<"Donner le nouveau statut: ";
                getline(cin, statut);
                e.setStatut(statut);
                break;
            }
        }
    }
    void afficher(){
        cout<<"Le nom: "<<nom<<endl;
        for(auto &e: flotte){
            e.afficher();
        }
    }
};

int main(){
    GestionnaireDeFlotte g("X");
    int choix;
    do{
        cout<<"    Menu  "<<endl;
        cout<<"1. Ajouter un camion."<<endl;
        cout<<"2. Modifier le statut d'un camion."<<endl;
        cout<<"3. Afficher les camions."<<endl;
        cout<<"4. Quitter."<<endl<<">> ";
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
                cout<<"AU revoir!"<<endl;
                break;
            default:
                cout<<"Mauvais choix."<<endl;
                break;
        }
    }while(choix != 4);
    
    return 0;
}
