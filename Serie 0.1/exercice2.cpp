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
    getline(cin,a.id);
    cout<<"Donner le nom: ";
    getline(cin, a.nom);
    cout<<"Donner description: ";
    getline(cin, a.desc);
    cout<<"Donner la qte: ";
    cin>>a.qte;
    cout<<"Donner le prix: ";
    cin>>a.prix;
    m.stock.push_back(a);
}

void majqte(Minimarche &m){
    string nvid;
    cout<<"Donner l'id de l'article: ";
    cin.ignore();
    getline(cin, nvid);
    for(auto &e: m.stock){
        if(e.id.compare(nvid) == 0){
            cout<<"La qte actuelle: "<<e.qte<<endl;
            cout<<"Donner la nouvelle: ";
            cin>>e.qte;
        }
    }
}
void afficherStock(Minimarche &m){
    for(Article &e: m.stock){
        cout<<"L'article: "<<e.nom<<"; qte: "<<e.qte<<endl;
    }
}

int main(){
    Minimarche *m = new Minimarche;
    m->nom = "Minimarche";
    ajouterArticle(*m);

    int choix;
    bool quitter = false;

    do{
    cout<<"Menu:"<<endl;
    cout<<"1. ajouter un article"<<endl;
    cout<<"2. mettre à jour la qte d'un article"<<endl;
    cout<<"3. Afficher le stock"<<endl;
    cout<<"4. Quitter"<<endl;
    cin>>choix;

    switch (choix)
    {
    case 1:
        ajouterArticle(*m);
        break;
    case 2:
        majqte(*m);
        break;
    case 3: 
        afficherStock(*m);
        break;
    case 4: 
        cout<<"AU revoir!";
        quitter = true;
        break;
    default:
        cout<<"Resaisir un choix valide: "<<endl;
        break;
    }
    }while(!quitter);
    return 0;
}