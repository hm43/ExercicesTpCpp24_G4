#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Article {
    int id;
    string nom;
    string description;
    int qte;
    double prix;
};

struct MiniMarche {
    string nom;
    vector<Article> stock;
};

void ajouterArticle(MiniMarche &marche) {
    Article article;
    cout << "Entrez l'ID de l'article: ";
    cin >> article.id;
    cin.ignore(); // Pour éviter que getline ne lise la fin de ligne de la saisie précédente
    cout << "Entrez le nom de l'article: ";
    getline(cin, article.nom);
    cout << "Entrez la description de l'article: ";
    getline(cin, article.description);
    cout << "Entrez la quantité de l'article: ";
    cin >> article.qte;
    cout << "Entrez le prix de l'article: ";
    cin >> article.prix;

    marche.stock.push_back(article);
}

void mettreAJourQuantite(MiniMarche &marche) {
    int id;
    cout << "Entrez l'ID de l'article à mettre à jour: ";
    cin >> id;

    for (Article &article : marche.stock) {
        if (article.id == id) {
            cout << "Entrez la nouvelle quantité: ";
            cin >> article.qte;
            return;
        }
    }
    cout << "Article non trouvé." << endl;
}

void afficherArticles(const MiniMarche &marche) {
    for (const Article &article : marche.stock) {
        cout << "ID: " << article.id << ", Nom: " << article.nom << ", Description: " << article.description
             << ", Quantité: " << article.qte << ", Prix: " << article.prix << endl;
    }
}

int main() {
    MiniMarche marche;
    marche.nom = "Mini-Marché Central";

    int choix;
    do {
        afficherArticles(marche);
        cout << "1. Ajouter un article" << endl;
        cout << "2. Mettre à jour un article" << endl;
        cout << "3. Afficher tous les articles" << endl;
        cout << "0. Quitter" << endl;
        cout << "Entrez votre choix: ";
        cin >> choix;

        switch (choix) {
            case 1:
                ajouterArticle(marche);
                break;
            case 2:
                mettreAJourQuantite(marche);
                break;
            case 3:
                afficherArticles(marche);
                break;
            case 0:
                cout << "Au revoir!" << endl;
                break;
            default:
                cout << "Choix invalide." << endl;
        }
    } while (choix != 0);

    return 0;
}
