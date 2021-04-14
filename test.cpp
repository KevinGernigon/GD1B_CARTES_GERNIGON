#include <string>
#include <iostream>
#include "Monstre.cpp"

using namespace std;

Monstre monstre_1 = Monstre("Chevalier", 3, 10);
Monstre monstre_2 = Monstre("Démon", 5, 5);

int main(){
    //monstre_1.affiche();
    //monstre_2.affiche();
    
    monstre_1.affiche();
    monstre_1.attaque(monstre_2);
    monstre_2.affiche();
    monstre_2.attaque(monstre_1);
}