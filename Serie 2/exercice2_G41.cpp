
#include <iostream>
#include <string>
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
    
    Complexe operator+(const Complexe &c){
        double resultat_reel = reel + c.reel;
        double resultat_imaginaire = imaginaire + c.imaginaire;
        Complexe resultat(resultat_reel, resultat_imaginaire);
        return  resultat;
    }
    Complexe operator-(const Complexe &c){
        double resultat_reel = reel - c.reel;
        double resultat_imaginaire = imaginaire - c.imaginaire;
        Complexe resultat(resultat_reel, resultat_imaginaire);
        return resultat;
    }
    Complexe operator*(const Complexe &c){
        double resultat_reel = reel * c.reel - imaginaire * c.imaginaire;
        double resultat_imaginaire = reel * c.imaginaire + c.reel * imaginaire;
        Complexe resultat(resultat_reel, resultat_imaginaire);
        return  resultat;
    }
    bool operator==(const Complexe &c){
        if(reel == c.reel && imaginaire == c.imaginaire){
            return true;
        }else{
            return false;
        }
    }
    void afficher(){
        if(reel != 0){
            cout<<reel;
            if(imaginaire>0)
                cout<<"+";
        }
        if(imaginaire>0){
            cout<<imaginaire<<"i"<<endl;
        }else if(imaginaire < 0){
            cout<<imaginaire<<"i"<<endl;
        }
        
        
    }
};

int main() {
    Complexe c1(0, 2), c2(1, -4);
    //Complexe c3 = c1.operator+(c2);
    Complexe c3 = c1+c2;
    c3.afficher();
   return 0;
}
