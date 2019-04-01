//
// Created by Tomasz Piechocki on 28/03/19.
//

#ifndef PO_C_FIELD_H
#define PO_C_FIELD_H

#include <src/Organisms/Organism.h>

class Organism;

class Field {
private:
    Organism* organism;

public:
    /**
     * Ustawienie wskaźnika na organizm z vectora obiektu World
     * @param organism
     */
    void setOrganism(Organism *organism);

    /**
     * Set pointer for null which means empty
     * Ustawienie wskaźnika na pusty
     */
    void setNull();

    Field();

    /**
     * @return Znak, który ma być narysowany na planszy dla danego pola
     */
    char draw() const;

    ~Field();
};


#endif //PO_C_FIELD_H
