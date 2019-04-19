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

int main() try {
    srand(static_cast<unsigned int>(time(nullptr)));
    int x,y;

#ifdef TEST
    x=20, y=20;
#else       // TODO world size limits
     do {
        cout << "Podaj szerokosc planszy: ";
        cin >> x;
        cout << "Podaj wysokosc planszy: ";
        cin >> y;
    } while (!(x*y < 100 || x < 50 || y < 50 || x>0 || y>0));
#endif

    auto *world = new World(x, y);
    Renderer* renderer = world->getRenderer();

    Human *player = world->getPlayer();

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
            // aktywowanie specjalnej umiejętności
            case 'u':
                player->activateImmortality();
                renderer->displayNotifications();
                break;
            // kontrolowanie kierunku ruchu gracza strzałkami
            case KEY_UP:
            case KEY_DOWN:
            case KEY_LEFT:
            case KEY_RIGHT:
                renderer->newPriorityMessage(player->setDirection(ch));
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
    std::cout << "Unexpected error!" << std::endl;
}