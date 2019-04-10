//
// Created by Tomasz Piechocki on 28/03/19.
//

#include <iostream>
#include <random>

#define TEST

using namespace std;

#ifdef __linux__
    #include <caca_conio.h>

#else
    #include <conio.h>
#endif

#include "World/World.h"
#include "Organisms/Human/Human.h"
#include "Organisms/Animals/Sheep.h"
#include "Organisms/Animals/Wolf.h"
#include "Organisms/Animals/Fox.h"
#include "Organisms/Plants/Grass.h"
#include "Organisms/Plants/Dandelion.h"
#include "Organisms/Plants/Guarana.h"

int main() try {
    srand(static_cast<unsigned int>(time(nullptr)));
    int x,y;

#ifdef TEST
    x=20, y=20;
#else
     do {
        cout << "Podaj szerokosc planszy: ";
        cin >> x;
        cout << "Podaj wysokosc planszy: ";
        cin >> y;
    } while (!(x*y < 100 || x < 50 || y < 50 || x>0 || y>0));
#endif

    auto *world = new World(x, y);
    Renderer* renderer = world->getRenderer();

    auto *player = new Human(0, 0, world);
    world->addOrganism(player);
    world->addOrganism(new Sheep(0,10, world));
    world->addOrganism(new Sheep(0,11, world));
    world->addOrganism(new Sheep(0,12, world));
    world->addOrganism(new Wolf(0,5, world));
    world->addOrganism(new Fox(1,0, world));
    world->addOrganism(new Grass(19, 19, world));
    world->addOrganism(new Dandelion(0, 18, world));
    world->addOrganism(new Guarana(0, 1, world));


    renderer->displayWorld();

    int ch = 0;
    while (ch != 'q') {
        ch = getch();
        switch (ch) {
            // wyjście
            case 'q':
                break;
            // wykonanie tury
            case 't':
                world->makeTurn();
                renderer->displayWorld();
                renderer->displayNotifications();
                break;
            // kontrolowanie kierunku ruchu gracza strzałkami
            case KEY_UP:
            case KEY_DOWN:
            case KEY_LEFT:
            case KEY_RIGHT:
                player->setDirection(ch);
                renderer->newMessage("Zmieniono kierunek");
                renderer->displayNotifications();
                break;
            default:
                break;
        }
    }
    return 0;
}
catch (const std::exception& e) {
    cerr << endl << "Error: " << e.what() << endl;
    return 1;
}
catch(...) {
    std::cout << "whoops!" << std::endl;
}