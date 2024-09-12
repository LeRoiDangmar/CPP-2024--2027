#include <iostream>

using namespace std;


void SetScore(int win, int& ref){

    if(win >= 3 ){
        ref = 40;
    }else if(win = 2){
        ref = 30;
    }else if(win = 1){
        ref = 15;
    }else if(win = 0){
        ref = 0;
    }

}


string CheckScore(int a, int b){
    if(a == b){
        return "Il y a égalité";
    }else if(a+b < 4){
        return "Il n'y a ni égalité, ni avantage";
    }else if(a > b && a - b >= 2){
        return "Le joueur A à gagné la partie";
    }else if(a > b && a - b < 2){
        return "Le joueur A a l'avantage";
    }else if(b > a && b - a >= 2){
        return "Le joueur B à gagné la partie";
    }else if(b > a && b - a < 2){
        return "Le joueur B a l'avantage";
    }

    return "erreur";
}



int main(){



    int winJoueurA = 0;
    int winJoueurB = 0;

    int scoreA = 0;
    int scoreB = 0;

    int& refA = scoreA;
    int& refB = scoreB;

    cout << "Entrez le nombre d'echange gagné par joueur A : " << endl;
    cin >> winJoueurA;

    cout << "Entrez le nombre d'echange gagné par joueur B : " << endl;
    cin >> winJoueurB;

    SetScore(winJoueurA, refA);
    SetScore(winJoueurB, refB);



    cout << "Les scores sont : " << endl << "Joueur A : " << refA << endl << "Joueur B : " << refB << endl << CheckScore(winJoueurA, winJoueurB) << endl;
    

}


