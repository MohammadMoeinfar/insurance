//
// Created by Mohammad Moeinfar on 5/14/2018.
//

#ifndef DAILYOPERATION_H
#define DAILYOPERATION_H

#include "cocos2d.h"
#include "AppMacros.h"
#include "ui/CocosGUI.h"
#include "MainMenuScene.h"

using namespace cocos2d::ui;

class DailyOperation : public Scene {

public:
    DailyOperation();
    ~DailyOperation();

    static Scene* createScene();
    static DailyOperation* initDailyOperation();
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent);
    void update(float dt);
    void repeatForever(Node* sender);

    Size visibleSize;
    Vec2 origin;
    Sprite* backScore;
    ListView* listView;
    std::vector<Layout*> listLayout;

    CREATE_FUNC(DailyOperation);

};


#endif //DAILYOPERATION_H
