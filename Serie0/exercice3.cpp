#include <stdio.h>
/*
Exercice 3:
-----------
Créer un programme qui:
1. Demande de l'utilisateur la taille du tableau des entiers moins de 10.
2. Donne la main à l'utilisateur d'entrer les valeurs du tableau.
3. Affiche la somme des valeurs du tableau à l'aide d'une fonction.
4. Affiche la moyenne du tableau à l'aide d'une fonction.
5. Trier le tableau à l'aide d'une fonction (ordre croissant).
6. Afficher le tableau trier à l'aide d'une fonction.
*/
#define MAX 10

// Fonction pour question 3.
int somme(int T[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += T[i];
    }
    return s;
}

// Fonction pour question 4.
float moyenne(int T[], int n)
{
    return (float)somme(T, n) / n;
}

// Fonction pour question 5.
void triC(int T[], int n)
{
    int tmp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (T[i] > T[j])
            {
                tmp = T[i];
                T[i] = T[j];
                T[j] = tmp;
            }
        }
    }
}
// ordre croissant par reference
void triCR(int (&T)[MAX], int n)
{
    int tmp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (T[i] > T[j])
            {
                tmp = T[i];
                T[i] = T[j];
                T[j] = tmp;
            }
        }
    }
}
// Fonction pour question 6.
void afficher(int T[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nT[%d] =  %d", i, T[i]);
    }
}
int main()
{
    // Question 1: Demande de l'utilisateur la taille du tableau des entiers moins de 10.
    int T[MAX], n, i;
    do
    {
        printf("\nEntrer la taille du tableau: ");
        scanf("%d", &n);
    } while (n > 10 || n < 1);

    // Question 2: Donne la main à l'utilisateur d'entrer les valeurs du tableau.
    for (i = 0; i < n; i++)
    {
        printf("\nSaisi la valeur de T[%d]: ", i);
        scanf("%d", &T[i]);
    }

    // Question 3: Affiche la somme des valeurs du tableau à l'aide d'une fonction.
    printf("La somme est: %d\n", somme(T, n));

    // Question 4: Affiche la moyenne du tableau à l'aide d'une fonction.
    printf("La moyenne est: %.2f\n", moyenne(T, n));

    // Question 5: Trier le tableau à l'aide d'une fonction (ordre croissant).
    printf("\nOrdre Croissant: ");
    triCR(T, n);

    // Question 6: Afficher le tableau trier à l'aide d'une fonction.
    afficher(T, n);

    return 0;
}