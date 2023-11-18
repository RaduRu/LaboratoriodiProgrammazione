//
// Created by Radu Ursu on 14/11/23.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_OBSERVER_H
#define LABORATORIODIPROGRAMMAZIONE_OBSERVER_H
#include "Subject.h"


class Observer {
public:

    virtual ~Observer() {};
    virtual void update();



};


#endif //LABORATORIODIPROGRAMMAZIONE_OBSERVER_H
