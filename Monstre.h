#include <string>

class Monstre{

    private:
        std::string _name;
        int _scoreAtk;
        int _scorePv;
        bool _isNotUsed = true;
        bool _isAlive = true;

    public:
        std::string getName();
        int getAtk();
        int getPv();
        bool getUse();
        void attaque(Monstre monstre_defenseur);
        void death();
        void affiche();

        Monstre();
        Monstre(std::string name, int scoreAtk, int scorePv);
};