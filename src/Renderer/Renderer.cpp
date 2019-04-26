//
// Created by Tomasz Piechocki on 31/03/2019.
//


#include <chrono>
#include <ctime>
#include <thread>
#include <iostream>

#include "Renderer.h"
#include "Notifications.h"

using namespace std;

Renderer::Renderer(World& world) : world(world) {
    messages = std::deque<std::string>();
    finish_notif_status = false;
    notif_working = false;
}

void Renderer::newMessage(const std::string& msg) {
    messages.push_back(msg);
}

void Renderer::newPriorityMessage(const std::string &msg) {
    messages.push_front(msg);
}

void Renderer::clearMessages() {
    endNotifications();
    messages.clear();
}

void Renderer::displayWorld() const {
    for (int i = 0; i < 100; ++i) {
        cout  << endl;
    }

    cout << "Tomasz Piechcoki, 175690" << endl;

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
    endNotifications();

    // run new thread
    std::thread notif([&]() {
        Notifications::run(messages, &finish_notif_status, &notif_working);
    });
    notif_working = true;
    notif.detach();
}

void Renderer::endNotifications() {
    // end previous thread if working
    finish_notif_status = true;
    if (notif_working) {
        while (finish_notif_status || notif_working) {
            // void
        }
    }
    finish_notif_status = false;
}

Renderer::~Renderer() = default;
