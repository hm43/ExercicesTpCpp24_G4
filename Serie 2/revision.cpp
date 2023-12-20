#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Etudiant{
private:
    string nom;
    double *notes;
    int taille;
    vector<double> newNotes;
public:
    Etudiant(){
        nom = "";
        taille = 5;
        notes = new double[taille];
    }
    Etudiant(string nom, int taille){
        this->nom = nom;
        notes = new double[taille];
    }
    Etudiant(const Etudiant &e){
        this->nom = e.nom;
        notes = new double[e.taille];
        for(int i = 0; i< e.taille; i++){
            notes[i] = e.notes[i];
        }
    }
    ~Etudiant(){
        delete [] notes;
    }
    string getNom(){
        return nom;
    }
    void setNom(string nom){
        this->nom = nom;
    }
    double* getNotes(){
        return notes;
    }
    void setNotesMemeTaille(double notes[]){
        // meme taille
        for(int i = 0; i< taille; i++){
            this->notes[i] = notes[i];
        }
    }
    void setNotesDiffTaille(double notes[], int taille){
        delete [] this->notes;
        this->notes = new double[taille];
        this->taille = taille;
        for(int i = 0; i< taille; i++){
            this->notes[i] = notes[i];
        }
    }
    int getTaille(){
        return taille;
    }
};
int main() {
    vector<Etudiant> etudiants;
    etudiants.resize(4);
    for(Etudiant &e: etudiants){
        e.setNom("un etudiant");
        cout<<e.getNom()<<endl;
        double* newNotes = new double[3];
        newNotes[0] = 1;
        newNotes[1] = 2;
        newNotes[2] = 3;
        e.setNotesDiffTaille(newNotes, 3);
        int taille = e.getTaille();
        double * notes = e.getNotes();
        for(int i = 0 ; i< taille; i++){
            cout<<notes[i]<<endl;
        }
    }
    return 0;
}
