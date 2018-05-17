//
// Created by Mohammad Moeinfar on 5/15/2018.
//

#ifndef PERIODICREPORT_H
#define PERIODICREPORT_H

#include "cocos2d.h"
#include "AppMacros.h"
#include "ui/CocosGUI.h"
#include "MainMenuScene.h"

using namespace cocos2d::ui;

class PeriodicReport : public Scene {

public:
    PeriodicReport();
    ~PeriodicReport();

    static Scene* createScene();
    static PeriodicReport* initPeriodicReport();
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent);

    Size visibleSize;
    Vec2 origin;

    CREATE_FUNC(PeriodicReport);
};


#endif //PERIODICREPORT_H
