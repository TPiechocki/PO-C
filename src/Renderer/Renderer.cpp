//
// Created by Tomasz Piechocki on 31/03/2019.
//

#include <thread>
#include <iostream>

#include "Renderer.h"
#include "Notifications.h"

using namespace std;

Renderer::Renderer(World& world) : world(world) {
    messages = std::deque<std::string>();
    notif_thread = 0;
}

void Renderer::newMessage(const std::string& msg) {
    messages.push_back(msg);
}

void Renderer::displayWorld() const {
    for (int i = 0; i < 100; ++i) {
        cout  << endl;
    }

    cout << "|";
    for (int i = 0; i < world.getSizeX() ; i++)
        cout << "-";
    cout << "|\n";

    for (int i = 0; i < world.getSizeY(); ++i) {
        cout << "|";
        for (int j = 0; j < world.getSizeX(); ++j) {
            cout << world.getFieldChar(j, i) << flush;
        }
        cout << "|\n";
    }

    cout << "|";
    for (int i = 0; i < world.getSizeX() ; i++)
        cout << "-";
    cout << "|\n";
}

void Renderer::displayNotifications() {
    if (notif_thread != 0) {
        pthread_cancel(notif_thread);
        notif_thread = 0;
    }

    Notifications notifications;

    std::thread notif([&]() {
        notifications.run(messages);
    });
    notif_thread = notif.native_handle();
    notif.detach();
}

Renderer::~Renderer() = default;
