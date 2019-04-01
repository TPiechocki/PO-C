//
// Created by tomaszek on 01/04/19.
//

#include <chrono>
#include <iostream>
#include "Notifications.h"
using namespace std::chrono;
using namespace std::this_thread;

void Notifications::run(std::deque<std::string> &messages) {
    std::string msg;

    std::cout << "\r";
    for (int j = 0; j < msg.length(); ++j) {
        std::cout << " ";
    }
    std::cout << "\r";

    while (!(messages.empty())) {
        msg = messages.front();
        std::cout << messages.front() << std::flush;
        messages.pop_front();

        sleep_for(seconds(2));
        std::cout << "\r";
        for (int j = 0; j < msg.length(); ++j) {
            std::cout << " ";
        }
        std::cout << "\r";
    }
}

