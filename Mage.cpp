#ifndef MAGE_CPP
#define MAGE_CPP

#include <string>
#include <iostream>
#include "Monstre.h"
#include "Mage.h"

/*private:
        std::string _name;
        std::string _zoneDeJeu;
        int _scorePv = 30;
        bool _isAlive = true;

    public:
        std::string getName();
        std::string getZone();
        int getPv();
        bool getStatus();
        void nouveauMonstre(std::string name, int scorePv, int scoreAtk);
        void attaqueDirecte(Monstre monstre_attaquant, Mage mage_defenseur);
        void attaqueMonstre(Monstre monstre_attaquant, Monstre monstre_defenseur);
        void affiche();

        Mage();
        Mage(std::string name, std::string zoneDeJeu);
*/

    Mage::Mage(){}
    Mage::Mage(std::string name, int scorePv): _name(name), _scorePv(scorePv){}

    std::string Mage::getName(){
        return _name;
    }

    std::vector<Monstre> Mage::getZone(){
        return _zoneDeJeu;
    }

    int Mage::getPv(){
        return _scorePv;
    }

    bool Mage::getStatus(){
        return _isAlive;
    }

    /*void Mage::setPv(int valeur){
        _scorePv = _scorePv - valeur;
    }*/

    void Mage::nouveauMonstre(){
        std::string nomChoisi;
        int atkChoisie;
        int pvChoisi;
        std::cout << "Veuillez entrez le nom du monstre." << std::endl;
        std::cin >> nomChoisi;
        std::cout << "Veuillez entrez le nombre de points de vie du monstre." << std::endl;
        std::cin >> pvChoisi;
        std::cout << "Veuillez entrez la valeur d'attaque du monstre." << std::endl;
        std::cin >> atkChoisie;
        Monstre nouveauMonstre = Monstre(nomChoisi, atkChoisie, pvChoisi);
        _zoneDeJeu.push_back(nouveauMonstre);
    }

    void Mage::attaqueDirecte(Mage mage_defenseur){
        int choix_monstre;
        int tailleTableau = _zoneDeJeu.size();
        std::cout << "Veuillez choisir le numéro à partir de 0 du monstre avec lequel vous voulez attaquer. Pour rappel, vous avez actuellement ";
        std::cout << tailleTableau;
        std::cout << " monstres sur votre terrain." << std::endl;
        std::cin >> choix_monstre;
        int attaqueMonstreAttaquant = _zoneDeJeu[choix_monstre].getAtk();
        std::cout << attaqueMonstreAttaquant << std::endl; //MAIS POURQUOI CA MARCHE PAAAAAS
        //if (_zoneDeJeu[choix_monstre].getUse() == true && _zoneDeJeu[choix_monstre].getPv() > 0 && mage_defenseur._scorePv > 0){
        mage_defenseur._scorePv = mage_defenseur._scorePv + attaqueMonstreAttaquant;
        //}
    }

    void Mage::attaqueMonstre(Mage mage_defenseur){
        int choix_monstre_attaquant;
        int choix_monstre_defenseur;
        int tailleTableau = _zoneDeJeu.size();
        int tailleTableauAdverse = mage_defenseur._zoneDeJeu.size();
        std::cout << "Veuillez choisir le numéro à partir de 0 du monstre avec lequel vous voulez attaquer. Pour rappel, vous avez actuellement ";
        std::cout << tailleTableau;
        std::cout << " monstres sur votre terrain." << std::endl;
        std::cin >> choix_monstre_attaquant;

        std::cout << "Veuillez choisir le numéro à partir de 0 du monstre que vous souhaitez attaquer. Pour rappel, votre adversaire a actuellement ";
        std::cout << tailleTableauAdverse;
        std::cout << " monstres sur son terrain." << std::endl;
        std::cin >> choix_monstre_defenseur;

        _zoneDeJeu[choix_monstre_attaquant].attaque(mage_defenseur._zoneDeJeu[choix_monstre_defenseur]);
    }

    void Mage::affiche(){
        std::cout << "Ce mage est nommé " + _name << std::endl;
        std::cout << "Il possède actuellement : ";
        std::cout << _scorePv;
        std::cout << " points de vie." << std::endl;
        if (_zoneDeJeu.size() > 0){
            for (int i = 0; i <= _zoneDeJeu.size() -1; i++){
                if (_zoneDeJeu[i].getStatus() == true){
                    _zoneDeJeu[i].affiche();
                }
            }
        }
    }

#endif