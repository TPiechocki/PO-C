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

#include "src/World/World.h"
#include "src/Organisms/Human/Human.h"
#include "src/Organisms/Animals/Sheep.h"
#include "src/Organisms/Animals/Wolf.h"

int main() {
    srand(time(nullptr));
    int x,y;

#ifdef TEST
    x=20, y=20;
#else
    cout << "Podaj szerokosc planszy: ";
    cin >> x;
    cout << "Podaj wysokosc planszy: ";
    cin >> y;
#endif

    auto *world = new World(x, y);
    Renderer* renderer = world->getRenderer();

    auto *player = new Human(0, 0, world);
    world->addOrganism(player);
    world->addOrganism(new Sheep(0,1, world));
    world->addOrganism(new Wolf(0,2, world));

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