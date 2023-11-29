#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Article
{
private:
    string id;
    string nom;
    string desc;
    int qte;
    double prix;

public:
    Article()
    {
        id = "";
        nom = "";
        desc = "";
        qte = 0;
        prix = 0;
    }
    Article(string id, string nom, string desc, int qte, double prix)
    {
        this->id = id;
        this->nom = nom;
        this->desc = desc;
        this->qte = qte;
        this->prix = prix;
    }
    string getId()
    {
        return id;
    }
    void setId(string id)
    {
        this->id = id;
    }

    string getNom()
    {
        return nom;
    }
    void setNom(string nom)
    {
        this->nom = nom;
    }
    string getDesc()
    {
        return desc;
    }
    void setDesc(string desc)
    {
        this->desc = desc;
    }
    int getQte()
    {
        return qte;
    }
    void setQte(int qte)
    {
        this->qte = qte;
    }
    double getPrix()
    {
        return prix;
    }
    void setprix(double prix)
    {
        this->prix = prix;
    }
};
class Minimarche
{
private:
    string nom;
    vector<Article> stock;

public:
    Minimarche()
    {
        nom = "";
    }
    Minimarche(string nom)
    {
        this->nom = nom;
    }
    void ajouterArticle()
    {
        string id, nom, desc;
        int qte;
        double prix;
        cout << "Donner l'id de l'article: ";
        cin.ignore();
        getline(cin, id);
        cout << "Donner le nom de l'article: ";
        getline(cin, nom);
        cout << "Donner la description de l'article: ";
        getline(cin, desc);
        cout << "Donner la qte de l'article: ";
        cin >> qte;
        cout << "Donner le prix de l'article: ";
        cin >> prix;
        Article a(id, nom, desc, qte, prix);
        stock.push_back(a);
    }
    void modifierQte()
    {
        string id;
        cout << "Donner l'id de l'article a modifier: ";
        cin.ignore();
        getline(cin, id);
        for (Article &a : stock)
        {
            if (a.getId().compare(id) == 0)
            {
                cout << "Donner la nouvelle qte: ";
                int qte;
                cin >> qte;
                a.setQte(qte);
                break;
            }
        }
    }
    void afficher()
    {
        cout << "le nom: " << nom << endl;
        for (Article &e : stock)
        {
            cout << "Id: " << e.getId() << endl;
            cout << "Nom: " << e.getNom() << endl;
            cout << "Description: " << e.getDesc() << endl;
            cout << "Qte: " << e.getQte() << endl;
            cout << "Prix: " << e.getPrix() << endl;
        }
    }
};
int main()
{
    Minimarche m("Marche");
    int choix;
    do
    {
        cout << endl
             << endl
             << "   Menu   " << endl
             << endl;
        cout << "1. Ajouter " << endl;
        cout << "2. MAJ la qte " << endl;
        cout << "3. Afficher " << endl;
        cout << "4. Quitter " << endl;
        cout << ">> ";

        cin >> choix;

        switch (choix)
        {
        case 1:
            m.ajouterArticle();
            break;
        case 2:
            m.modifierQte();
            break;
        case 3:
            m.afficher();
            break;
        case 4:
            cout << "Au revoir." << endl;
            break;
        default:
            cout << "Reessayer." << endl;
            break;
        }
    } while (choix != 4);
    return 0;
}
