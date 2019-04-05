//
// Created by Tomasz Piechocki on 30/03/2019.
//

#include "Organism.h"


void Organism::addOneAge() {
 age++;
}

int Organism::getX() const {
    return x_coord;
}

int Organism::getY() const {
    return y_coord;
}

int Organism::getVectorPos() const {
    return vector_pos;
}

int Organism::getInitiative() const {
    return initiative;
}

int Organism::getAge() const {
    return age;
}

Organism *Organism::collision(Organism* other) {
    std::string msg;
    if (other->strength < this->strength) {
        msg = this->getGatunek() + " zabija " + other->getGatunek();
        world->newMessage(msg);

        world->removeOrganism(other);
        free(other);
        return this;
    }
    else {      // jeśli siła równa dla obu to wygrywa atakujący
        msg = other->getGatunek() + " zabija " + this->getGatunek();
        world->newMessage(msg);

        world->removeOrganism(this);
        free(this);
        return other;
    }
}

