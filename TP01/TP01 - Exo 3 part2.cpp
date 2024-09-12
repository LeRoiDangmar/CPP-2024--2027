#include <iostream>
#include <random>

using namespace std;

int GenererNombre(int max , int min){

    srand(time(0));

    return rand()%(max - min + 1) + min;
}

int GenererNombreOrdi(int max , int min){

    return (max - min)/2 + min;
}

int main(){

    int max = 1000;
    int min = 0;

    int nombre = GenererNombre(max, min);

    int estimation = 0;

    int compteur = 0;

    cout << "Imagine que quelqu'un veuille tester lol : "<< nombre << endl;

    do{
        cout << "Entrez une estimation" << endl;

        cin >> estimation;

        compteur++;

        if(estimation > nombre){
            cout<<"C'est moins !" << endl;
        }else if(estimation < nombre){
            cout<<"C'est plus !" << endl;
        }else if(estimation == nombre){
            cout << "Bravo !! Tu as reussis en " << compteur << " essais" << endl;
        }
    }while(estimation != nombre);




    int nombreOrdi= 0 ;
    int compteurOrdi = 0;
    int estimationOrdi = 0;
    int maxOrdi = 1000;
    int minOrdi = 0;
    int reponse = 0;

    cout << "Inversons les roles, fais moi devinez un nombre entre 0 et 1000. Entre ton nombre :" << endl;

    cin >> nombreOrdi;

    do{
        estimationOrdi = GenererNombreOrdi(maxOrdi, minOrdi);
        cout << "Voici mon estimation : " << estimationOrdi << endl;

        compteurOrdi++;

        cout << "Est ce que c'est le nombre cherché c'est 1) Plus , 2) Moins 3) J'ai trouvé ?" << endl;

        cin >> reponse;

        if(reponse == 1) {
            minOrdi = estimationOrdi;
            cout << "D'accord c'est plus " << endl;
        }else if(reponse == 2){
            maxOrdi = estimationOrdi;
            cout << "D'accord c'est moins " << endl;
        }else if(reponse == 3){
            if(estimationOrdi == nombreOrdi){
                cout << "YESS, j'ai reussi en" << compteurOrdi << " essais" << endl;
            }else {
                cout << "Tu te fiche de moi ?" << endl;
            }
        }
    }while(nombreOrdi != estimationOrdi);
}