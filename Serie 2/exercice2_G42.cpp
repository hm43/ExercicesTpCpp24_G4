
#include<iostream>
using namespace std;
class Complexe{
private:
    double reel;
    double imaginaire;
public:
    Complexe(){
        reel = 0;
        imaginaire = 0;
    }
    Complexe(double reel, double imaginaire){
        this->reel = reel;
        this->imaginaire = imaginaire;
    }
    Complexe operator+(const Complexe &a){
        double resultat_reel = this->reel + a.reel;
        double resultat_imaginaire = imaginaire + a.imaginaire;
        Complexe resultat(resultat_reel, resultat_imaginaire);
        return resultat;
    }
    Complexe operator-(const Complexe &a){
        double resultat_reel = this->reel - a.reel;
        double resultat_imaginaire = imaginaire - a.imaginaire;
        Complexe resultat(resultat_reel, resultat_imaginaire);
        return resultat;
    }
    Complexe operator*(const Complexe &a){
        double resultat_reel = reel * a.reel - imaginaire * a.imaginaire;
        double resultat_imaginaire = reel * a.imaginaire + imaginaire * a.reel;
        Complexe resultat(resultat_reel, resultat_imaginaire);
        return resultat;
    }
    bool operator==(const Complexe &a){
        if(reel == a.reel && imaginaire == a.imaginaire){
            return true;
        }else{
            return false;
        }
    }
    void afficher(){
        // Complexe c(1, -2) = 1 -2i
        // Complexe c(0, -2) = -2i
        // Complexe c(0, 2) = 2i
        // Complexe c(1, 0) = 1
        // c.afficher();
        if (reel != 0)
            cout<<reel;
        if(imaginaire > 0){
            if(reel != 0)
                cout<<"+";
            cout<<imaginaire<<"i";
        } else if(imaginaire < 0)
            cout<<imaginaire<<"i";
        
        cout<<endl;
    }
};
int main(){
    Complexe c1(1, -2);
    Complexe c2(2, -2);
    Complexe c3 = c1 + c2;
    Complexe c4 = c1 - c2;
    Complexe c5 = c1 * c2;
    c3.afficher();
    c4.afficher();
    c5.afficher();
    if(c1 == c2){
        cout<<"Egaux"<<endl;
    }else{
        cout<<"different."<<endl;
    }
    return 0;
}
