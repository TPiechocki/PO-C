//
// Created by Tomasz Piechocki on 16/04/19.
//

#ifndef PO_C_BELLADONNA_H
#define PO_C_BELLADONNA_H

#include "../Plant.h"

class Belladonna : public Plant {
protected:
    Organism *createNewInstance(int x, int y, World *world) override;

public:
    Belladonna(int x, int y, World *world);

    char draw() override;

    std::string getKindString() override;

    /**
     * Wilcza jagoda zabija wszystkie organizmy, które ją zaatakowały.
     */
    bool collision(Organism *attacker) override;

    ~Belladonna() override;
};


#endif //PO_C_BELLADONNA_H
