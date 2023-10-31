#include<iostream>
using namespace std;
/*
Exercice 5:
------------
Écrire une fonction qui permet de rechercher dans un tableau d’entiers tab une valeur A. 
void chercherVal (int tab[], int n, int A, int *pos, int *nb_occ); 
Dans pos, la fonction sauvegarde l’indice de la dernière apparition et -1 si la valeur n’a pas été trouvée. 
Dans nb_occ, elle sauvegarde le nombre d’occurence de A dans tab.
*/



void chercherVal (int tab[], int n, int A, int *pos, int *nb_occ){
    *pos = -1;
    *nb_occ = 0;
    for(int i = 0; i < n ; i++){
        if(tab[i] == A){
            *pos = i;
            (*nb_occ)++;
        }
    }
}

int main(){
    int taille, *tab;
    int pos, nb_occ, valeur;
    do{
        cout<<"Donner la taille du tableau: ";
        cin>>taille;
    }while (taille<=0);
    tab = new int[taille];
    cout<<"Entrer les valeurs du tableau: "<<endl;
    for(int i = 0; i < taille ; i++){
        cin>>tab[i];
    }

    // appel de la fonction recherche

    cout<<"Donner la valeur a chercher: ";
    cin>>valeur;
    chercherVal(tab, taille, valeur, &pos, &nb_occ);
    cout<<"derniere position: "<<pos<<" nombre de repetition: "<<nb_occ<<endl;

    
    return 0;
}