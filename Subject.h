//
// Created by Radu Ursu on 14/11/23.
//

#ifndef LABORATORIODIPROGRAMMAZIONE_SUBJECT_H
#define LABORATORIODIPROGRAMMAZIONE_SUBJECT_H
#include "Observer.h"


class Subject {
public:
    virtual ~Subject() {};
    virtual void subscribe(Observer* o) = 0;
    virtual void unsubscribe(Observer* o) = 0;
    virtual void notify() = 0;

};


#endif //LABORATORIODIPROGRAMMAZIONE_SUBJECT_H
