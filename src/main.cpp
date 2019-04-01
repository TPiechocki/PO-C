//
// Created by Tomasz Piechocki on 28/03/19.
//

#include <iostream>

using namespace std;

#include <src/World/World.h>
#include <src/Organisms/Human/Human.h>

#ifdef __linux__
    #include <caca_conio.h>
#else
    #include <conio.h>
#endif


int main() {
    int x,y;
    cout << "Podaj szerokosc planszy: ";
    cin >> x;
    cout << "Podaj wysokosc planszy: ";
    cin >> y;

    auto *world = new World(x, y);

    Human player = Human(0, 0, world);
    world->addOrganism(&player);

    // TODO message renderer
    world->renderer->displayWorld();

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
                world->renderer->displayWorld();
                break;
            // kontrolowanie kierunku ruchu gracza strzałkami
            case KEY_UP:
            case KEY_DOWN:
            case KEY_LEFT:
            case KEY_RIGHT:
                player.setDirection(ch);
                world->renderer->newMessage("Zmieniono kierunek");
                world->renderer->displayNotifications();
                break;
            default:
                break;
        }
    }
    return 0;
}