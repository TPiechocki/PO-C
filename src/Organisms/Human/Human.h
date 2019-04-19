//
// Created by Tomasz Piechocki on 30/03/2019.
//

#ifndef PO_C_HUMAN_H
#define PO_C_HUMAN_H

#include "../Animal.h"

class Animal;

class Human final : public Animal {
private:
    // zawiera wiek przy którym specjalna umiejętność(nieśmiertelność) będzie działać po raz ostatni dla poprzedniej aktywacji
    int immortalityEnd;

protected:
    /**
     * Brak losowego kierunku - pusta metoda
     */
    void randomDirection() override;

    Organism *createNewInstance(int x, int y, World *world) override;

public:
    Human(int x, int y, World* world);

    /**
     * Użytkownik może zmienić kierunek ruchu strzałkami.
     * @return - wiadomość powiadomienia
     */
    std::string setDirection(int);

    /**
     * Aktywacja nieśmiertelności
     */
    void activateImmortality();

    bool canBeKilled() override;

    char draw() override;

    std::string getKindString() override;

    ~Human() override;
};


#endif //PO_C_HUMAN_H
