#include<iostream>

using namespace std;

class Pilechar{
private:
    int max;
    int sommet;
    char *pile;
public:
    Pilechar(){
        max = 50;
        sommet = 0;
        pile = new char[50];
    }
    Pilechar(int max){
        this->max = max;
        sommet = 0;
        pile = new char[max];
    }
    ~Pilechar(){
        delete [] pile;
    }
    void empiler(char c){
        if(sommet < max){
            pile[sommet] = c;
            sommet++;
        }else{
            cout<<"Pas d'espace."<<endl;
        }
    }
    char depiler(){
        if(sommet > 0){
            return pile[sommet--];
        }
        return ' ';
    }
    int taille(){
        return max;
    }
    int compter(){
        return sommet;
    }
    void afficher(){
        cout<<"[";
        for(int i = 0; i< sommet; i++){
            cout<<pile[i];
            if(i < sommet-1)
                cout<<",";
        }
        cout<<"]"<<endl;
    }
};


int main(){
    Pilechar p(3);
    p.empiler('a');
    p.empiler('b');
    p.empiler('c');
    p.depiler();
    p.empiler('d');
    
    p.afficher();
    cout<<"La taille est: "<<p.taille()<<endl;
    cout<<"Il y a: "<<p.compter()<<" caracteres."<<endl;
    
    return 0;
}
