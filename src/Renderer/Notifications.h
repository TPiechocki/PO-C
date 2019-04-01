//
// Created by tomaszek on 01/04/19.
//

#ifndef PO_C_NOTIFICATIONS_H
#define PO_C_NOTIFICATIONS_H


#include <string>
#include <deque>
#include <future>

class Notifications {
public:
    /**
     * Thread method for displaying notifications
     * @param messages
     */
    void run(std::deque<std::string>& messages);
};


#endif //PO_C_NOTIFICATIONS_H
