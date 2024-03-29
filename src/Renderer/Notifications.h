//
// Created by Tomasz Piechocki on 01/04/19.
//

#ifndef PO_C_NOTIFICATIONS_H
#define PO_C_NOTIFICATIONS_H


#include <string>
#include <deque>
#include <future>

class Notifications {
public:
    /**
     * Metoda dla wątka do wyświetlania powiadomień
     * @param messages - lista wiadomości do wyświetlenia
     */
    static void run(std::deque<std::string> &messages, bool *finish, bool *working);
};


#endif //PO_C_NOTIFICATIONS_H
