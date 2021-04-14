#include <string>
#include <iostream>
#include "Monstre.cpp"
#include "Mage.cpp"

using namespace std;

Monstre monstre_1 = Monstre("Chevalier", 3, 10);
Monstre monstre_2 = Monstre("Démon", 5, 5);

Mage mage_1 = Mage("Leeroy Jenkins", 50);
Mage mage_2 = Mage("Nicolas Loth", 40);

int main(){
    //monstre_1.affiche();
    //monstre_2.affiche();
    
    /*monstre_1.affiche();
    monstre_1.attaque(monstre_2);
    monstre_2.affiche();
    monstre_2.attaque(monstre_1);
    */

    mage_1.nouveauMonstre();
    mage_2.nouveauMonstre();
   //mage_1.affiche();
    //cout << mage_2.getPv() << endl;
    //mage_1.attaqueDirecte(mage_2);
    mage_1.attaqueMonstre(mage_2);
    //cout << mage_2.getPv() << endl;
    mage_2.affiche();
}