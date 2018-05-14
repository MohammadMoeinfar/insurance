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

#define MAINFONT "fonts/IRAN Sans.ttf"

#define DAILY_OPERATION 1001
#define PERIODIC_REPORT 1002
#define INSURANCE_REPORT 1003
#define CAR_HEALTH_REPORT 1004
#define CAR_POSITION 1005
#define NEAR_DISTANCE_SERVICE_POSITION 1006

#define TITLELOGINBUTTON "ورود"

#define TITLE_DAILY_OPERATION "عملکرد روزانه"
#define TITLE_PERIODIC_REPORT "گزارش دوره ای"
#define TITLE_INSURANCE_REPORT "گزارش بیمه"
#define TITLE_CAR_HEALTH_REPORT "گزارش سلامت خودرو"
#define TITLE_CAR_POSITION "موقعیت خودرو"
#define TITLE_NEAR_DISTANCE_SERVICE_POSITION "فاصله تا نزدیکترین سرویس"

#define MILEAGE "مسافت طی شده"
#define MILEAGE_UNIT "واحد مسافت طی شده"
#define DRIVE_TIME "مدت زمان رانندگی"
#define SCORE "امتیاز"
#define SPEED_LIMIT "محدودیت سرعت"
#define HARSH_DRIVE "درایو سخت"
#define UNSAFE_FIELD_DRIVE "فیلد درایو ناامن"

#endif //APPMACROS_H
