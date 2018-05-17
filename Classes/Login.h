//
// Created by Mohammad Moienfar on 5/13/2018.
//

#ifndef LOGIN_H
#define LOGIN_H

#include "cocos2d.h"
#include "AppMacros.h"
#include "ui/CocosGUI.h"
#include "MainMenuScene.h"

using namespace cocos2d::ui;

class Login : public Scene {

public:
    Login();
    ~Login();

    static Scene* createScene();
    static Login* initLogin();

    void textFieldEvent(Ref *pSender, TextField::EventType type);
    void buttonEvent(Ref* pSender, Widget::TouchEventType type);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent);

    Size visibleSize;
    Vec2 origin;
    TextField* textFieldPassword;
    TextField* textFieldUsername;

    CREATE_FUNC(Login);

};


#endif //LOGIN_H
