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

#define THIRDPARTY "شخص ثالث"
#define CARBODY "بدنه ماشین"
#define LIFE_HEALTH "زندگی و سلامت"

#define INSURANCE_TITLE "عنوان بیمه"
#define INSURANCE_ID "شناسه بیمه"
#define INSURANCE_START "شروع بیمه"
#define INSURANCE_END "پایان بیمه"
#define MORE_DESCRIPTION "توضیحات اضافی"

#define PART_TITLE "عنوان"
#define P001 "P001"
#define U034 "U034"

#define ENGINE "موتور"
#define ABS_BRAKES "ABS"
#define BSI "BSI"

struct ValueDailyOperation
{
    float mileage  = 0.0;
    string driveTime = "";
    float score = 0.0;
    float speedLimit = 0.0;
    float harshDrive = 0.0;
    float unsafeFieldDrive = 0.0;
};

struct ValuePeriodicReport
{
    float mileage  = 0.0;
    string driveTime = "";
    float score = 0.0;
    float speedLimit = 0.0;
    float harshDrive = 0.0;
    float unsafeFieldDrive = 0.0;
};

struct ListOfInsurances
{
    struct ThirdParty
    {
        string insuranceTitle = "";
        long long int insuranceID = 0;
        long long int insuranceStartUtc = 0;
        long long int insuranceEndUtc = 0;
        string someMoreInsuranceData = "";
    };

    struct CarBody
    {
        string insuranceTitle = "";
        long long int insuranceID = 0;
        long long int insuranceStartUtc = 0;
        long long int insuranceEndUtc = 0;
        string someMoreInsuranceData = "";
    };

    struct LifeAndHealth
    {
        string insuranceTitle = "";
        long long int insuranceID = 0;
        long long int insuranceStartUtc = 0;
        long long int insuranceEndUtc = 0;
        string someMoreInsuranceData = "";
    };

    ThirdParty theThirdParty;
    CarBody theCarBody;
    LifeAndHealth theLifeAndHealth;

};

struct ListOfCarHealth
{
    struct UnitEngine
    {
        string EcuName = "";
        string p001 = "";
        string u034 = "";
    };

    struct UnitABS
    {
        string EcuName = "";
        string p001 = "";
        string u034 = "";
    };

    struct UnitBSI
    {
        string EcuName = "";
        string p001 = "";
        string u034 = "";
    };

    UnitEngine theUnitEngine;
    UnitABS theUnitABS;
    UnitBSI theUnitBSI;

};

static std::vector <std::vector < std::string > > initInsurances()
{
    std::vector <std::vector < std::string > >arrTitlesInsuranceReport =
            {
                    {
                            {INSURANCE_TITLE},
                            {INSURANCE_ID},
                            {INSURANCE_START},
                            {INSURANCE_END},
                            {MORE_DESCRIPTION}
                    },
                    {
                            {INSURANCE_TITLE},
                            {INSURANCE_ID},
                            {INSURANCE_START},
                            {INSURANCE_END},
                            {MORE_DESCRIPTION}
                    },
                    {
                            {INSURANCE_TITLE},
                            {INSURANCE_ID},
                            {INSURANCE_START},
                            {INSURANCE_END},
                            {MORE_DESCRIPTION}
                    }
            };
    return arrTitlesInsuranceReport;
}

static std::vector <std::vector < std::string > > initCarHealth()
{
    std::vector <std::vector < std::string > >arrTitlesCarHealth =
            {
                    {
                            {PART_TITLE},
                            {P001},
                            {U034}
                    },
                    {
                            {PART_TITLE},
                            {P001},
                            {U034}
                    },
                    {
                            {PART_TITLE},
                            {P001},
                            {U034}
                    }
            };
    return arrTitlesCarHealth;
}

#endif //APPMACROS_H
