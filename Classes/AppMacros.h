//
// Created by Mohammad Moeinfar on 5/13/2018.
//

#ifndef APPMACROS_H
#define APPMACROS_H

#include "cocos2d.h"
#include <fstream>
#include "external/json/document.h"
#include "external/json/writer.h"
#include "external/json/stringbuffer.h"

USING_NS_CC;
using namespace std;
using namespace rapidjson;

static Size visibleSize = Director::getInstance()->getVisibleSize();
static Vec2 origin = Director::getInstance()->getVisibleOrigin();

#define MAINFONT "fonts/arial.ttf"

#endif //APPMACROS_H
