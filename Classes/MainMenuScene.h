//
// Created by Mohammad Moeinfar on 5/13/2018.
//

#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include "cocos2d.h"
#include "AppMacros.h"
#include "ui/CocosGUI.h"
#include "DailyOperation.h"
#include "PeriodicReport.h"
#include "InsuranceReport.h"
#include "CarHealthReport.h"
#include "CarLocation.h"
#include "NearDistanceServicePosition.h"
#include "Login.h"

using namespace cocos2d::ui;

class MainMenuScene : public Scene {

public:
    MainMenuScene();
    ~MainMenuScene();

    static Scene* createScene();
    static MainMenuScene* initMainMenuScene();

    void textFieldEvent(Ref *pSender, TextField::EventType type);
    void buttonEvent(Ref* pSender, Widget::TouchEventType type);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent);
    void readData();

    Size visibleSize;
    Vec2 origin;

    CREATE_FUNC(MainMenuScene);

};


#endif //MAINMENUSCENE_H
