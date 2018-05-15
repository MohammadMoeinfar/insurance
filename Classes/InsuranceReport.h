//
// Created by Mohammad Moeinfar on 5/15/2018.
//

#ifndef INSURANCEREPORT_H
#define INSURANCEREPORT_H

#include "cocos2d.h"
#include "AppMacros.h"
#include "ui/CocosGUI.h"

using namespace cocos2d::ui;

class InsuranceReport : public Scene {

public:
    InsuranceReport();
    ~InsuranceReport();

    static Scene* createScene();
    static InsuranceReport* initInsuranceReport();

    Size visibleSize;
    Vec2 origin;

    CREATE_FUNC(InsuranceReport);
};


#endif //INSURANCEREPORT_H
