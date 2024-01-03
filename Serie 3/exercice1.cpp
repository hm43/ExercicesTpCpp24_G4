#include<iostream>
#include <string>
using namespace std;
class Cryptomonnaie{
private:
    string nom;
    double valeur;
public:
    Cryptomonnaie(string n, double v): nom(n), valeur(v){}
    void setNom(string n){
        nom = n;
    }
    void setValeur(double v){
        valeur = v;
    }
    friend class Transaction;
};

class Portefeuille{
private:
    double solde;
    string proprietaire;
public:
    Portefeuille(double s, string p): solde(s), proprietaire(p){}
    void afficherSolde(){
        cout<<"Le solde de: "<<proprietaire<<" est: "<<solde<<endl;
    }
    friend class Transaction;
};
class Transaction{
public:
    void effectuerTransaction(Portefeuille &p1, Portefeuille &p2, double montant, const Cryptomonnaie &c){
        if( montant <= p1.solde ){
            cout<<"Avant transaction: "<<endl;
            p1.afficherSolde();
            p2.afficherSolde();
            
            p1.solde -= montant;
            p2. solde += montant * c.valeur;
            
            cout<<"Apres transaction: "<<endl;
            p1.afficherSolde();
            p2.afficherSolde();
        }else{
            cout<<endl<<"Solde insuffisant."<<endl;
        }
    }
};

int main() {
    Cryptomonnaie USD_MAD("USD_MAD", 10);
    Portefeuille p1 (10000, "x");// USD
    Portefeuille p2 (1000, "y");// MAD
    Transaction t;
    t.effectuerTransaction(p1, p2, 5000, USD_MAD);
    
    return 0;
}
