#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef struct Article{
    string id;
    string nom;
    string desc;
    int qte;
    float prix;
}Article;

typedef struct Minimarche{
    string nom;
    vector<Article> stock;
}Minimarche;

void ajouterArticle(Minimarche &m){

    
    Article a;
    cout<<"Donner l'id: ";
    getline(cin, a.id);
    cout<<"Donner le nom: ";
    getline(cin, a.nom);
    cout<<"Donner la description: ";
    getline(cin, a.desc);
    cout<<"Donner la qte: ";
    cin>>a.qte;
    cout<<"Donner le prix: ";
    cin>>a.prix;

    m.stock.push_back(a);
}

void majQte(Minimarche &m){
    string nvid;
    cout<<"Donner l'id de l'article: ";
    cin.ignore();
    getline(cin, nvid);
    for(Article &a: m.stock){
        if(a.id.compare(nvid) == 0){
            cout<<"La quantite est: "<<a.qte<<endl;
            cout<<"Donner la nouvelle qte:";
            cin>>a.qte;
        }
    }
}
void afficher(Minimarche &m){
    for(Article &a: m.stock){
        cout<<"Le nom: "<<a.nom<<" Qte: "<<a.qte<<endl;
    }
}

int main(){
    Minimarche * m = new Minimarche;
    m->nom = "My mini market";
    ajouterArticle(*m);
    int choix;
    do{
    cout<<"Menu: "<<endl;
    cout<<"1. ajouter un article"<<endl;
    cout<<"2. mettre à jour la qte d'un article"<<endl;
    cout<<"3. afficher tous les articles."<<endl;
    cout<<"4. Quitter"<<endl;
    cout<<">> ";
    cin>>choix;
    switch(choix){
        case 1:
            ajouterArticle(*m);
            break;
        case 2:
            majQte(*m);
            break;
        case 3:
            afficher(*m);
            break;
        case 4:
            cout<<"Au revoir!"<<endl;
            break;
        default:
            cout<<"Donner un choix valide."<<endl;
            break;
    }
    }while(choix != 4);


    return 0;
}