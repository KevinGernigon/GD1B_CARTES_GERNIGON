#ifndef MAGE_H
#define MAGE_H

#include <string>
#include <vector>
#include "Monstre.h"

class Mage{

    private:
        std::string _name;
        std::vector<Monstre> _zoneDeJeu;
        int _scorePv;
        bool _isAlive = true;

    public:
        std::string getName();
        std::vector<Monstre> getZone();
        int getPv();
        bool getStatus();
        void nouveauMonstre();
        void attaqueDirecte(Mage mage_defenseur);
        void attaqueMonstre(Mage mage_defenseur);
        void affiche();
        //void setPv(int valeur);

        Mage();
        Mage(std::string name, int scorePv);
};

#endif