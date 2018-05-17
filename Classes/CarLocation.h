//
// Created by Mohammad Moeinfar on 5/16/2018.
//

#ifndef CARLOCATION_H
#define CARLOCATION_H

#include "cocos2d.h"
#include "AppMacros.h"
#include "ui/CocosGUI.h"
#include "MainMenuScene.h"

using namespace cocos2d::ui;


class CarLocation : public Scene {

public:
    CarLocation();
    ~CarLocation();

    static Scene* createScene();
    static CarLocation* initCarLocation();

    void mapEvent(Ref* pSender, Widget::TouchEventType type);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent);

    Size visibleSize;
    Vec2 origin;
    vector<double> points;

    CREATE_FUNC(CarLocation);

};


#endif //CARLOCATION_H
