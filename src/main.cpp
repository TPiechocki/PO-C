//
// Created by Tomasz Piechocki on 28/03/19.
//

#include <iostream>
#include <random>

//#define TEST

using namespace std;

#ifdef __linux__
    #include <caca_conio.h>
#else
    #include <conio.h>
#endif

#include "World/World.h"
#include "Organisms/Human/Human.h"
#include "Utils/File.h"

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

        // Wyczyszczenie buforu cin przy znakach innych niż liczba.
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << endl << "Wymiary musza byc liczbami! " << endl;
            continue;
        }

        if (x*y < 100)
            cout << endl << "Plansza musi miec conajmniej 100 pol. " << endl;
        if (y > 50)
            cout << endl << "Wysokosc planszy nie moze byc wieksza niz 50. " << endl;
         if (x > 100)
             cout << endl << "Szerokosc planszy nie moze byc wieksza niz 150. " << endl;
        if (x <= 0 || y <= 0)
            cout << endl << "Wymiar planszy musi byc wiekszy od 0 " << endl;

    } while (!(x*y >= 100 && x <= 150 && y <= 50 && x > 0 && y > 0));
#endif
    auto *file = new File();
    auto *world = new World(x, y, true);
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
				if (player)
					renderer->newPriorityMessage(player->setDirection(ch));
				else
					renderer->newPriorityMessage("Nie mozna zmienic kierunku.");
                renderer->displayNotifications();
                break;
            // zapis pliku
            case 's':
				renderer->clearMessages();
                file->save(world);
                renderer->newPriorityMessage("Zapisano do pliku.");
                renderer->displayWorld();
                renderer->displayNotifications();
                break;
            // odczyt z pliku
            case 'l':
                renderer->clearMessages();
                World *temp_world;
                temp_world = file->read();
                if (temp_world) {
                    delete world;
                    world = temp_world;
                    renderer = world->getRenderer();
                    player = world->getPlayer();
                    renderer->displayWorld();
                }
                break;
            default:
                break;
        }
    }

	delete file;
	delete world;
    return 0;
}
catch (const std::exception& e) {
    cerr << endl << "Error: " << e.what() << endl;
    return 1;
}
catch(...) {
    std::cout << "Unexpected error!" << std::endl;
}