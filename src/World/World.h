//
// Created by Tomasz Piechocki on 28/03/19.
//

#ifndef PO_C_WORLD_H
#define PO_C_WORLD_H

#include <vector>

#include "Field.h"
#include "../Organisms/Organism.h"
#include "../Renderer/Renderer.h"



class Field;
class Organism;
class Renderer;
class Human;


class World {
private:
    int size_x, size_y;

    Field** board;

    std::vector<Organism *> entities;

    Human *player;

    /**
     * Generowanie losowych wspolrzednych
     */
    int randomX();

    int randomY();

    /**
     * Losowe ustawinie organizmów na początku gry
     */
    void randomOrganisms();

    /**
     * Renderer wyświetlający świat oraz powiadomienia
     */
    Renderer* renderer;
protected:
    /**
     * Sprawdza czy pole na którym wylądował organizm jest pełny, jeśli tak to wykonuję odpowiednią kolizję
     * @return true - jeśli elementy w wektorze od co najmniej badanego organizmu się przesunęły w stronę początku
     */
    bool makeCollision(Organism *);
public:
    /**
     * @param x - szerokość
     * @param y - wysokość
     * @param new_board - prawda, jeśli mają się pojawić losowe organizmy
     */
    World(int x, int y, bool new_board);

    int getSizeX() const;

    int getSizeY() const;

    Renderer *getRenderer() const;

    Human *getPlayer();

    int getEntititesSize() const;

    void newMessage(const std::string&);

    void newPriorityMessage(const std::string&);

    /**
     * Na potrzebę kolizji.
     * @return Wskaźnik do organizmu znajdującego się na polu (x,y)
     */
    Organism *getOrganismFromBoard(int x, int y);

    void setOrganismOnBoard(Organism *org);

    /**
     * @return znak reprezuntujący organizm na polu (x,y)
     */
    char getFieldChar(int x, int y);

    /**
     * Dodanie organismu do wektora wszystkich organizmów w odpowiednie miejsce
     */
    void addOrganism(Organism *);

    /**
     * Usunięcie organizmu z wektora wszystkich organizmów
     */
    void removeOrganism(Organism *);

    /**
     * Wykonanie tury
     */
    void makeTurn();

    /**
     * Zapis zawartości obiektu do pliku lub odczytanie zawartości do pliku
     * @param write - prawda jeśli zapis, fałsz jeśli odczytywanie (odczytywanie nic nie robi)
     */
    void Serialise(std::fstream &file, bool write);

    ~World();
};

#endif //PO_C_WORLD_H