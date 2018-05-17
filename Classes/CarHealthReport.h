//
// Created by Mohammad Moeinfar on 5/15/2018.
//

#ifndef CARHEALTHREPORT_H
#define CARHEALTHREPORT_H

#include "cocos2d.h"
#include "AppMacros.h"
#include "ui/CocosGUI.h"
#include "MainMenuScene.h"

using namespace cocos2d::ui;

class CarHealthReport : public Scene {

public:
    CarHealthReport();
    ~CarHealthReport();

    static Scene* createScene();
    static CarHealthReport* initCarHealthReport();
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent);

    Size visibleSize;
    Vec2 origin;

    CREATE_FUNC(CarHealthReport);

};


#endif //CARHEALTHREPORT_H
