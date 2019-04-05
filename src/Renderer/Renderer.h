//n
// Created by Tomasz Piechocki on 31/03/2019.
//

#ifndef PO_C_RENDERER_H
#define PO_C_RENDERER_H

#include <src/World/World.h>
#include "Notifications.h"

class World;

class Renderer {
private:
    World& world;

    // thread for notifications
    pthread_t notifThread;

    // double sided list of messages for notifications
    std::deque<std::string> messages;

public:
    explicit Renderer(World& World);

    /**
     * Dodanie wiadomości na końcu listy
     */
    void newMessage(const std::string&);

    /**
     * Wyświetlenie planszy świata
     */
    void displayWorld() const;

    /**
     * Wyświetlenia powiadomień z listy co jakiś określony czas(inny wątek)
     */
    void displayNotifications();

    virtual ~Renderer();
};

#endif //PO_C_RENDERER_H
