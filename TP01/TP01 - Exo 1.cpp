#include <iostream>
#include <string>
#include <random>

using namespace std;

int AdditionEntier(int nb1, int nb2){
    return nb1+nb2;
}

void AdditionEntierPointeur(int nb1, int nb2, int* nb3){

    *nb3 = nb1 + nb2;

}

void AdditionEntierReference(int nb1, int nb2, int nb3){
    nb3 = nb1 + nb2;
}


void AffichageTableau(int* tableau, const int nbValeur){
    for(int i = 0; i < nbValeur; i++){
        cout << "Table [" << i << "] = "  << tableau[i] << endl;
    }

    cout << endl << endl;
}

void Swap(int& a, int& b){

    int c;
    c = a;
    a = b;
    b = c;

}

void TrieTableau(int* tab, const int nbValeures, bool sens = true, bool relancer = true){

    if(relancer){
        cout << "1 pour croissant 0 pour décroissant : " << endl;

        cin >> sens;
    }
    
    if(sens){

    for(int i = 0; i < nbValeures; i++){

        for(int j = 0; j < nbValeures; j++){

            if(tab[i] < tab[j]){

                Swap(tab[i],tab[j]);

            }
        }      
    }
    AffichageTableau(tab, nbValeures);
    if(relancer)
    TrieTableau(tab, nbValeures, false, false);

    }else{
        for(int i = 0; i < nbValeures; i++){

            for(int j = 0; j < nbValeures; j++){

                if(tab[i] > tab[j]){

                    Swap(tab[i],tab[j]);

                }
            }      
        }

    AffichageTableau(tab, nbValeures);
    if(relancer)
    TrieTableau(tab, nbValeures, true, false);
    }

    
}



void TableauAleatoire(const int nbValeur){
    
    int tableau[nbValeur];
    
    srand(time(0));
    for(int i = 0 ; i < nbValeur; i++){
        tableau[i] = rand() %100;
    }

    AffichageTableau(tableau, nbValeur);

    TrieTableau(tableau, nbValeur);

    
}


 

int main(){
    int nb1 = 0;
    int nb2 = 0;

    int nb3 = 0;

    int& nb3Ref = nb3;

    int* nb3Point = &nb3;

    cout << "Entrez un premier entier" << endl;
    cin >> nb1;

    cout << "Entrez un second entier" << endl;
    cin >> nb2;

    cout << "Le resultat de l'addition de ces deux nombre est : " << AdditionEntier(nb1, nb2) << endl;

    AdditionEntierPointeur(nb1, nb2, &nb3);

    cout << "Le resultat de l'addition de ces deux nombre en utlisant les pointeurs est : " << *&nb3 << endl;

    AdditionEntierReference(nb1, nb2, nb3Ref);

    cout << "Le resultat de l'addition de ces deux nombre en utlisant les references est : " << nb3 << endl;

    int nbValeur = 0;

    

    cout << "Choisissez la taille de votre tableau" << endl;

    cin >> nbValeur;

    TableauAleatoire(nbValeur);
    
}