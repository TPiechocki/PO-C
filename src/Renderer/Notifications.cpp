//
// Created by Tomasz Piechocki on 01/04/19.
//

#include <chrono>
#include <ctime>
#include <iostream>
#include "Notifications.h"

using namespace std::chrono;

void Notifications::run(std::deque<std::string> &messages, bool *finish, bool *working) {
    *working = true;
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

        auto start = system_clock::now();
        auto end = system_clock::now();
        auto delta = end - start;

        while (delta < seconds{2} && !(*finish)) {
            delta = end - start;
            end = system_clock::now();
        }

        std::cout << "\r";
        for (int j = 0; j < msg.length(); ++j) {
            std::cout << " ";
        }
        std::cout << "\r";

        // if thread has signal to finish, change signal to false and end this thread
        if (*finish) {
            *finish = false;
            break;
        }
    }
    *working = false;
    *finish = false;
}

