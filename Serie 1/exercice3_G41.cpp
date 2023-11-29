#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Article{
private:
    string id;
    string nom;
    string desc;
    int qte;
    double prix;
public:
    Article(){
        id = "";
        nom = "";
        desc = "";
        qte = 0;
        prix = 0;
    }
    Article(string id, string nom, string desc, int qte, double prix)
    :id(id), nom(nom), desc(desc), qte(qte), prix(prix){}
    string getId(){
        return id;
    }
    void setId(string id){
        this->id = id;
    }
    string getNom(){
        return nom;
    }
    void setNom(string nom){
        this->nom = nom;
    }
    string getDesc(){
        return desc;
    }
    void setDesc(string desc){
        this->desc = desc;
    }
    int getQte(){
        return qte;
    }
    void setQte(int qte){
        this->qte = qte;
    }
    double getPrix(){
        return prix;
    }
    void setPrix(double prix){
        this->prix = prix;
    }
};

class Minimarche{
private:
    string nom;
    vector <Article> stock;
public:
    Minimarche(){
        nom = "";
    }
    Minimarche(string nom){
        this->nom = nom;
    }
    void ajouterArticle(){
        string id;
        string nom;
        string desc;
        int qte;
        double prix;
        cout<<"Donner l'id: ";
        cin.ignore();
        getline(cin, id);
        cout<<"Donner le nom: ";
        getline(cin, nom);
        cout<<"Donner la description: ";
        getline(cin, desc);
        cout<<"Donner la qte: ";
        cin>>qte;
        cout<<"Donner le prix: ";
        cin>>prix;
        Article a(id,nom, desc, qte, prix);
        stock.push_back(a);
    }
    void majQte(){
        string id;
        cout<<"Donner l'id: ";
        cin.ignore();
        getline(cin, id);
        
        for(auto &e: stock){
            if(e.getId().compare(id) == 0){
                
                int qte;
                cout<<"Ancienne valeur de qte: "<<e.getQte()<<endl;
                cout<<"Donner la qte: ";
                cin>>qte;
                e.setQte(qte);
                break;
            }
        }
    }
    void afficher(){
        cout<<"Le nom du mini merche est: "<<nom<<endl<<endl;
        for(auto &e: stock){
            cout<<"Id: "<<e.getId()<<endl;
            cout<<"Nom: "<<e.getNom()<<endl;
            cout<<"Description: "<<e.getDesc()<<endl;
            cout<<"Quantite: "<<e.getQte()<<endl;
            cout<<"Prix: "<<e.getPrix()<<endl;
        }
    }
};
int main() {
    Minimarche m("My store");
    int choix;
menu:
    cout<<endl<<endl<<"   Menu   "<<endl<<endl;
    cout<<"1. Ajouter "<<endl;
    cout<<"2. MAJ la qte "<<endl;
    cout<<"3. Afficher "<<endl;
    cout<<"4. Quitter "<<endl;
    cout<<">> ";
    cin>>choix;
    switch (choix) {
        case 1:
            m.ajouterArticle();
            goto menu;
            break;
        case 2:
            m.majQte();
            goto menu;
            break;
        case 3:
            m.afficher();
            goto menu;
            break;
        case 4:
            cout<<endl<<"Au revoir"<<endl;
            break;
        default:
            cout<<"Reessayer"<<endl;
            goto menu;
            break;
    }
    
    
    return 0;
}
