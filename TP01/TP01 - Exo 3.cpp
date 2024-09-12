#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<string> Noms(){

    string input;

    cout << "Entrez votre nom complet séparé par un espace" << endl;

    getline(cin, input); //avec ca je prend toute la ligne avec les espace

    istringstream stream(input); //la je créer un flux stream qui prend input

    vector<string> noms; // vecteur pour stocker les noms

    string nom;

    while (stream >> nom) {
        noms.push_back(nom); // chaque nous va dans le vecteur
    }


    for(string& nom : noms){ // Je passe tous les mots sous le format "Jules"
        bool premiereLettre = true;
        for (auto & c: nom){
            if(premiereLettre == true){
                c = toupper(c);
                premiereLettre = false;
            }else {
                c = tolower(c);
            }
        }
    }

    for (auto & c: noms.back()) c = toupper(c); // On converti le dernier element du vecteur (le nom) en majuscules

    return noms;
}


void Bonjour(vector<string> noms){
    cout << "Bonjour et bienvenu sur ce programme, ";
    
    for(string& i : noms){
        cout << i << " " ;
    }

    cout << endl;
}


int main(){

    vector<string> noms = Noms();

    Bonjour(noms);
    

}