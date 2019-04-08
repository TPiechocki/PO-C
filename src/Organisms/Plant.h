//
// Created by Tomasz Piechocki on 07/04/19.
//

#ifndef PO_C_PLANT_H
#define PO_C_PLANT_H


#include "Organism.h"

class Plant : public Organism {
protected:
    double scatter_possibility;

public:
    /**
     * Wszystkie rośliny mają takie same pola oprócz inicjatywy i gatunku
     */
    Plant(int x, int y, World *world);

    /**
     * Możliwość rozprzestrzeniania się z pewnym prawdopodobieństwem, jeśli wylosowane pole jest puste
     * Zatem realne prawdopobieństwo jest mniejsze, bo wylosowane pole może być zajęty i wtedy nic się nie dzieje.
     */
    void move() override;

    ~Plant() override;
};


#endif //PO_C_PLANT_H
