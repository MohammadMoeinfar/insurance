//
// Created by Mohammad Moeinfar on 5/16/2018.
//

#ifndef NEARDISTANCESERVICEPOSITION_H
#define NEARDISTANCESERVICEPOSITION_H

#include "cocos2d.h"
#include "AppMacros.h"
#include "ui/CocosGUI.h"

using namespace cocos2d::ui;


class NearDistanceServicePosition : public Scene {

public:
    NearDistanceServicePosition();
    ~NearDistanceServicePosition();

    static Scene* createScene();
    static NearDistanceServicePosition* initNearDistanceServicePosition();

    void mapEvent(Ref* pSender, Widget::TouchEventType type);

    Size visibleSize;
    Vec2 origin;

    CREATE_FUNC(NearDistanceServicePosition);

};

#endif //NEARDISTANCESERVICEPOSITION_H
