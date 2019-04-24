//
// Created by Tomasz Piechocki on 30/03/2019.
//

#ifndef PO_C_ORGANISM_H
#define PO_C_ORGANISM_H

#ifdef __linux__
    #include <caca_conio.h>
    #define KEY_UP CACA_KEY_UP
    #define KEY_DOWN CACA_KEY_DOWN
    #define KEY_LEFT CACA_KEY_LEFT
    #define KEY_RIGHT CACA_KEY_RIGHT
#else
    #include <conio.h>
    #define KEY_UP 72
    #define KEY_DOWN 80
    #define KEY_LEFT 75
    #define KEY_RIGHT 77
#endif

#include <fstream>

#include "../World/World.h"

class World;
class Animal;

enum Kind {
    HUMAN, SHEEP, WOLF, FOX, ANTELOPE, TORTOISE, GRASS, DANDELION, GUARANA, BELLADONNA, HOGWEED
};

class Organism {
protected:
    int strength{}, initiative{}, x_coord, y_coord, age, direction;

    // Poprzednie koordynaty mogą się przydać przy odbiciu żółwia.
    int previous_x{}, previous_y{};

    Kind kind{};

    World *world;

    virtual Organism * createNewInstance(int x, int y, World *world) = 0;

    virtual void randomDirection();

public:
    Organism(int x, int y, World *world);

    bool operator<(const Organism &rhs) const;

    bool operator>(const Organism &rhs) const;

    bool operator<=(const Organism &rhs) const;

    bool operator>=(const Organism &rhs) const;

    /**
     * Wykonanie ruchu
     */
    virtual void move() = 0;

    /**
     * Ruch na sąsiednie puste pole. Tylko dla zwierząt.
     */
    virtual void moveToSafe() {};

    void setPreviousXY();

    /**
     * @return aktualna pozycja x
     */
    int getX() const;

    /**
     * @return aktualna pozycja y
     */
    int getY() const;

    int getInitiative() const;

    int getAge() const;

    int getStrength() const;

    Kind getKind();

    void setWorld(World *world);

    /**
     * Zmiana wieku o 1 w góre, wywołane dla każdego w każdej turze.
     */
    void addOneAge();

    /**
    * Change organism strange by int value.
    */
    void changeStrength(int);

    /**
     * Kolizja z innym organizmem
     * @param attacker - atakujący
     * @return - prawda jeśli zabity został poruszający się organizm lub zabity organizm był wcześniej już ruszony
     *      Wtedy wszystkie eleementy wektora się przesuwają, więc trzbea zmniejszyć inedks pętli tury.
     */
    virtual bool collision(Organism *attacker);

    /**
     * Rozmnażanie się, ważne przy zwierzętach.
     * @return wskaźnik na nowo urodzony obiekt jeśli takowy się pojawi
     */
    virtual Organism *breed(Animal *);

    virtual /**
     * Prawda jeśli może zginąć, fałsz gdy jest nieśmiertelny (specjalna umijętność człowieka)
     */
    bool canBeKilled();

    /**
     * @return Zwraca znak charakterystyczny dla gatunku
     */
    virtual char draw() = 0;

    /**
     * @return słowna nazwa gatunku
     */
    virtual std::string getKindString() = 0;

    /**
     * Zapis zawartości obiektu do pliku lub odczytanie zawartości do pliku
     * @param write - prawda jeśli zapis, fałsz jeśli odczytywanie
     */
    void Serialise(std::fstream &file, bool write);

    friend class File;

    virtual ~Organism();
};


#endif //PO_C_ORGANISM_H
