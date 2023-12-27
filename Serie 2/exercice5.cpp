
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Livre{
    string titre;
    string auteur;
    int nombrePages;
public:
    Livre(){
        titre = "";
        auteur = "";
        nombrePages = 0;
    }
    Livre(string t, string a, int n){
        titre = t;
        auteur = a;
        nombrePages = n;
    }
    Livre(const Livre &l){
        titre = l.titre;
        auteur = l.auteur;
        nombrePages = l.nombrePages;
    }
    friend ostream& operator <<(ostream & out, const Livre &l){
        out<<endl<<l.titre<<" de "<<l.auteur<<" nbr de pages: "<<l.nombrePages<<endl;
        return out;
    }
    void afficherInfos(){
        cout<<*this;
    }
    friend istream& operator>>(istream &in, Livre &l){
        cout<<"Titre: ";
        in.ignore();
        getline(in, l.titre);
        cout<<"Auteur: ";
        getline(in, l.auteur);
        cout<<"Nombre de pages: ";
        in>>l.nombrePages;
        return in;
    }
    friend void comparerLivres(const Livre&, const Livre &);
    friend void ajouterPages(Livre&, int);
    
    
};
void comparerLivres(const Livre &l1, const Livre &l2){
    if(l1.nombrePages >= l2.nombrePages){
        cout<<l1.titre<<endl;
    }else{
        cout<<l2.titre<<endl;
    }
}
void ajouterPages(Livre &l, int pages){
    l.nombrePages += pages;
}
int main(){
    // Créez des objets Livre
       Livre livre1("Harry Potter", "J.K. Rowling", 400);
       Livre livre2("Le Seigneur des Anneaux", "J.R.R. Tolkien", 600);
       // Affichez les informations des livres
       livre1.afficherInfos();
       livre2.afficherInfos();
       // Comparez les livres et affichez le titre du livre avec le plus de pages
       comparerLivres(livre1, livre2);
       // Ajoutez 50 pages au premier livre et affichez les nouvelles informations
       ajouterPages(livre1, 50);
       livre1.afficherInfos();
    return 0;
}
