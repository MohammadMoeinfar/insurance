//
// Created by Mohammad Moeinfar on 5/13/2018.
//

#ifndef SPLASHSCENE_H
#define SPLASHSCENE_H

#include "cocos2d.h"
#include "AppMacros.h"
#include "Login.h"

USING_NS_CC;

class SplashScene : public Scene {

public:
    SplashScene();
    ~SplashScene();

    static Scene* createScene();
    static SplashScene* initSplashScene();

    CREATE_FUNC(SplashScene);

};


#endif //SPLASHSCENE_H
