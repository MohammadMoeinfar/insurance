//
// Created by Mohammad Moeinfar on 5/13/2018.
//

#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include "cocos2d.h"
#include "AppMacros.h"
#include "ui/CocosGUI.h"
#include "DailyOperation.h"

using namespace cocos2d::ui;

class MainMenuScene : public Scene {

public:
    MainMenuScene();
    ~MainMenuScene();

    static Scene* createScene();
    static MainMenuScene* initMainMenuScene();

    void textFieldEvent(Ref *pSender, TextField::EventType type);
    void buttonEvent(Ref* pSender, Widget::TouchEventType type);
    void readData();

    Size visibleSize;
    Vec2 origin;

    CREATE_FUNC(MainMenuScene);

};


#endif //MAINMENUSCENE_H
