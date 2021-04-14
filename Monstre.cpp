#ifndef MONSTRE_CPP
#define MONSTRE_CPP

#include <string>
#include <iostream>
#include "Monstre.h"

/*
private:
        std::string _name;
        int _scoreAtk;
        int _scorePV;
        bool _isNotUsed;
        bool _isAlive;

    public:
        std::string getName();
        int getAtk();
        int getPv();
        bool getUse();
        void attaque();
        void death();
        void affiche();

        Monstre();
        Monstre(std::string name, int scoreAtk, int scorePv);
*/

    Monstre::Monstre(){}
    Monstre::Monstre(std::string name, int scoreAtk, int scorePv): _name(name), _scoreAtk(scoreAtk), _scorePv(scorePv){}

    std::string Monstre::getName(){
        return _name;
    }

    int Monstre::getAtk(){
        return _scoreAtk;
    }

    int Monstre::getPv(){
        return _scorePv;
    }

    bool Monstre::getUse(){
        return _isNotUsed;
    }

    void Monstre::attaque(Monstre monstre_defenseur){
        if (_isNotUsed == false){
            std::cout << "Ce monstre a déjà été utilisé." << std::endl;
        }
        if (_isNotUsed && _isAlive && monstre_defenseur._isAlive){
            _isNotUsed = false;
            _scorePv = _scorePv - monstre_defenseur._scoreAtk;
            monstre_defenseur._scorePv = monstre_defenseur._scorePv - _scoreAtk;
            death();
            monstre_defenseur.death();
        } 
    }

    bool Monstre::getStatus(){
        if (_isAlive == false){
            return true;
        }
        return false;
    }

    void Monstre::death(){
        if (_scorePv <= 0){
            std::cout << "Le monstre " + _name + " a péri au combat." << std::endl;
            bool _isAlive = false;
        }
    }

    void Monstre::affiche(){
        if (_isAlive == true && _isNotUsed == true){
            std::cout << "Le monstre s'appelle " + _name + "." << std::endl;
            std::cout << "Ses points de vie sont de : ";
            std::cout << _scorePv;
            std::cout << std::endl;
            std::cout << "Ses points d'attaque sont de : ";
            std::cout << _scoreAtk;
            std::cout << std::endl;
            std::cout << "Il peut actuellement jouer." << std::endl;
        }
        if (_isAlive == true && _isNotUsed == false){
            std::cout << "Le monstre s'appelle " + _name + "." << std::endl;
            std::cout << "Ses points de vie sont de : ";
            std::cout << _scorePv;
            std::cout << std::endl;
            std::cout << "Ses points d'attaque sont de : ";
            std::cout << _scoreAtk;
            std::cout << std::endl;
            std::cout << "Il ne peut pas actuellement jouer." << std::endl;
        }
    }

#endif