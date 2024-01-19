#include <iostream>
#include <string>
using namespace std;

// 6 exercices

// ================== EXERCICE 1 ==================
/*
Écrire un programme en C++ qui permet d’afficher les n termes d'une série harmonique et leur
somme.
1 + 1/2 + 1/3 + 1/4 + 1/5 ... jusqu'à 1/n termes.
Exemple de sortie :
Entrez le nom2bre de termes : 5
1/1 + 1/2 + 1/3 + 1/4 + 1/5
La somme de la série jusqu'à 5 termes : 2.28333
*/

int Exercice1(){
    int n;
    float somme = 0;
    cout << "Entrez le nombre de termes : ";
    cin >> n;
    cout << "1";
    for (int i = 2; i <= n; i++)
    {
        cout << " + 1/" << i;
        somme += 1.0 / i;
    }
    cout << endl;
    cout << "La somme de la serie jusqu'a " << n << " termes : " << somme + 1 << endl;
    return 0;

}

// ================== EXERCICE 2 ==================
/*
Écrire un programme C++ qui permet de :
1. déclarer un entier a;
2. déclarer une référence vers cet entier ref_a;
3. déclarer un pointeur vers cet entier p_a;
4. afficher les variables, leurs adresses, la valeur pointée (*p_a)
*/
int Exercice2(){
    int a = 5;
    int &ref_a = a;
    int *p_a = &a;
    cout << "a = " << a << endl;
    cout << "ref_a = " << ref_a << endl;
    cout << "p_a = " << p_a << endl;
    cout << "*p_a = " << *p_a << endl;
    return 0;
}

// ================== EXERCICE 3 ==================
/*
1. Écrire une fonction swap_1 qui a comme paramètres deux paramètres de référence qui
échange le contenu des deux entiers.
2. Écrire une fonction swap_2 qui a comme paramètres deux pointeurs vers des entiers et
qui échange le contenu des deux entiers pointés.
Tester ces deux fonctions en écrivant un programme qui échange deux fois le contenu de deux
entiers a et b en appelant ces deux fonctions.
*/
int swap_1(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
    return 0;
}

int swap_2(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

int Exercice3()
{
    int a = 5;
    int b = 10;
    cout << "a = " << a << " b = " << b << endl;
    swap_1(a, b);
    cout << "swap_1" << endl; // "a = 10 b = 5"
    cout << "a = " << a << " b = " << b << endl;
    swap_2(&a, &b);
    cout << "swap_2" << endl; // "a = 5 b = 10"
    cout << "a = " << a << " b = " << b << endl;
    return 0;
}

// ================== EXERCICE 4 ==================
/*
Écrire une fonction qui a pour paramètre un tableau A d'entiers et sa taille. Cette fonction doit
ranger les éléments du tableau A dans l’ordre inverse. La fonction utilisera deux pointeurs P1
et P2 pour le parcours du tableau.
*/

void inverse(int *A, int size){
    int *P1 = A;
    int *P2 = A + size - 1;
    while (P1 < P2)
    {
        swap_2(P1, P2);
        P1++;
        P2--;
    }
}

int Exercice4()
{
    int A[5] = {1, 2, 3, 4, 5};
    int size = 5;
    inverse(A, size);
    cout << "A = { ";
    for (int i = 0; i < size-1; i++)
    {
        cout << A[i] << ", ";
    }
    cout << A[size-1] << " }" << endl;
    return 0;
}

// ================== EXERCICE 5 ==================
/*
Écrire un programme qui à partir d’un tableau d’entiers, construit deux tableaux alloués
dynamiquement, l’un contenant les valeurs négatives, l’autre les valeurs positives ou nulles.
*/

int sign_split(int *A, int size, int *A_pos, int *A_neg){
    //return size of A_pos
    int size_pos = 0;
    int size_neg = 0;
    for (int i = 0; i < size; i++)
    {
        if (A[i] >= 0)
        {
            A_pos[size_pos] = A[i];
            size_pos++;
        }
        else
        {
            A_neg[size_neg] = A[i];
            size_neg++;
        }
    }
    // arrays with the correct size
    int *A_pos_final = new int[size_pos];
    int *A_neg_final = new int[size_neg];
    for (int i = 0; i < size_pos; i++)
    {
        A_pos_final[i] = A_pos[i];
    }
    for (int i = 0; i < size_neg; i++)
    {
        A_neg_final[i] = A_neg[i];
    }

    return size_pos;
}

int Exercice5()
{
    int size = 20;
    int A[20] = {1, 2, 3, -4, -5, 6, 7, 8, 9, 10, -11, 12, 13, 14, 15, -16, 17, 18, 19, 20};
    //int size = sizeof(A) / sizeof(A[0]);
    cout << "A = { ";
    for (int i = 0; i < 19; i++)
    {
        cout << A[i] << ", ";
    }
    cout << A[19] << " }" << endl;
    int size_neg;
    int size_pos;
    int *A_pos = new int[size];
    int *A_neg = new int[size];
    size_pos = sign_split(A, size, A_pos, A_neg);
    size_neg = size - size_pos;
    cout << "A_pos = { ";
    for (int i = 0; i < size_pos-1; i++)
    {
        cout << A_pos[i] << ", ";
    }
    cout << A_pos[size_pos-1] << " }" << endl;
    cout << "A_neg = { ";
    for (int i = 0; i < size_neg-1; i++)
    {
        cout << A_neg[i] << ", ";
    }
    cout << A_neg[size_neg-1] << " }" << endl;
    return 0;

}

// ================== EXERCICE 6 ==================
/*
Implémenter une classe représentant un compteur entier. Un tel objet est caractérisé par les
éléments suivants :
1. Il possède une valeur entière, initialement nulle, qui peut être positive ou nulle.
2. La valeur du compteur ne peut être modifiée qu'en incrémentant ou en décrémentant
d'une unité (la décrémentation d'un compteur nul n'a aucun effet).
Exemple de sortie :
Valeur initiale du compteur : 100
Valeur apres incrementation : 110
Valeur apres decrementation : 90
*/

class Compteur
{
private:
    int value;

public:
    Compteur(int value = 0)
    {
        if (value >= 0)
        {
            this->value = value;
        }
        else
        {
            this->value = 0;
        }
    }
    void increment(int value = 1)
    {
        this->value += value;
    }
    void decrement(int value = 1)
    {
        this->value -= value;
        if (this->value < 0)
        {
            this->value = 0;
        }
    }
    int getValue()
    {
        return this->value;
    }
};

int Exercice6()
{
    Compteur c(100);
    cout << "Valeur initiale du compteur : " << c.getValue() << endl;
    c.increment(10);
    cout << "Valeur apres incrementation : " << c.getValue() << endl;
    c.decrement(20);
    cout << "Valeur apres decrementation : " << c.getValue() << endl;
    return 0;
}

// ================== MAIN ==================

    

int main()
{
    int choix;
    cout << "Choisissez l'exercice : ";
    cin >> choix;
    // Array of pointers to functions
    switch (choix)
    {
    case 1:
        Exercice1();
        break;
    case 2:
        Exercice2();
        break;
    case 3:
        Exercice3();
        break;
    case 4:
        Exercice4();
        break;
    case 5:
        Exercice5();
        break;
    case 6:
        Exercice6();
        break;
    default:
        Exercice1();
        Exercice2();
        Exercice3();
        Exercice4();
        Exercice5();
        Exercice6();
        break;
    }
}