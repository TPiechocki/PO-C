//
// Created by Tomasz Piechocki on 05/04/19.
//

#ifndef PO_C_ORGCOMP_H
#define PO_C_ORGCOMP_H


/**
 * Porównywanie organizmów według inicjatywy oraz wieku
 */
class OrgComp {
public:
    inline bool operator() (const Organism* orgL, const Organism* orgR) {
        return (orgL->getInitiative() > orgR->getInitiative()) ||
                ((orgL->getInitiative() == orgR->getInitiative()) && orgL->getAge() > orgR->getAge());
    }
};


#endif //PO_C_ORGCOMP_H
