//n
// Created by Tomasz Piechocki on 31/03/2019.
//

#ifndef PO_C_RENDERER_H
#define PO_C_RENDERER_H

#include <thread>

#include "../World/World.h"
#include "Notifications.h"

class World;

class Renderer {
private:
    World& world;

    // double sided list of messages for notifications
    std::deque<std::string> messages;

    bool finish_notif_status, notif_working;

    /**
     * Zakończenie obecnie działającego wątku z powiadomieniami
     */
    void endNotifications();
public:
    explicit Renderer(World& world);

    /**
     * Dodanie wiadomości na końcu listy
     */
    void newMessage(const std::string&);

    /**
     * Dodanie wiadomości na początek, żeby się wyswietliła w pierwszej kolejności
     */
    void newPriorityMessage(const std::string&);

    void clearMessages();

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
