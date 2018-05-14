//
// Created by Mohammad Moeinfar on 5/14/2018.
//

#ifndef DAILYOPERATION_H
#define DAILYOPERATION_H

#include "cocos2d.h"
#include "AppMacros.h"
#include "ui/CocosGUI.h"

using namespace cocos2d::ui;

class DailyOperation : public Scene {

public:
    DailyOperation();
    ~DailyOperation();

    static Scene* createScene();
    static DailyOperation* initDailyOperation();

    Size visibleSize;
    Vec2 origin;

    CREATE_FUNC(DailyOperation);

};


#endif //DAILYOPERATION_H
