#include<iostream>
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
    Article(string id, string nom, string desc, int qte, double prix){
        this->id = id;
        this->nom = nom;
        this->desc = desc;
        this->qte = qte;
        this->prix = prix;
    }
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
    int getQte(){
        return qte;
    }
    void setQte(int qte){
        this->qte = qte;
    }
    // Les autres
    
};
class Minimarche{
private:
    string nom;
    vector<Article> stock;
public:
    Minimarche(){
        nom = "";
    }
    Minimarche(string nom){
        nom = nom;
    }
    void ajouterArticle(){
        string id, nom, desc = "";
        int qte;
        double prix = 0;
        cout<<"Donner l'id de l'article: ";
        getline(cin, id);
        cout<<"Donner le nom de l'article: ";
        getline(cin, nom);
        cout<<"Donner la qte de l'article: ";
        cin>>qte;
        Article a(id, nom, desc, qte, prix);
        stock.push_back(a);
    }
    void modifierQte(){
        string id;
        cout<<"Donner l'id de l'article a modifier: ";
        getline(cin,id);
        for(Article &a: stock){
            if(a.getId().compare(id) == 0){
                cout<<"Donner la nouvelle qte: ";
                int qte;
                cin>>qte;
                a.setQte(qte);
                break;
            }
        }
    }
};
int main(){
    return 0;
}
