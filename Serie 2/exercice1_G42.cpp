
#include <iostream>
#include <string>
using namespace std;

class Livre{
private:
    string titre;
    string auteur;
    static int nombreExemplaires;
public:
    Livre(){
        titre = "";
        auteur = "";
        nombreExemplaires++;
        cout<<"Constr "<<nombreExemplaires<<endl;
    }
    Livre(string titre, string auteur){
        this->titre = titre;
        this->auteur = auteur;
        nombreExemplaires++;
        cout<<"Constr "<<nombreExemplaires<<endl;
    }
    ~Livre(){
        nombreExemplaires--;
        cout<<"Destr "<<nombreExemplaires<<endl;
    }
    static void afficherNombreExemplaires(){
        cout<<nombreExemplaires<<endl;
    }
    
};
int Livre::nombreExemplaires = 0;
int main() {
    Livre l1;
    Livre l2("T", "A");
    Livre::afficherNombreExemplaires();
    
    return 0;
}
