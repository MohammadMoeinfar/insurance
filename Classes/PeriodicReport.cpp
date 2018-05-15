//
// Created by Mohammad Moeinfar on 5/15/2018.
//

#include "PeriodicReport.h"

PeriodicReport::PeriodicReport() {

}

PeriodicReport::~PeriodicReport() {

}

Scene *PeriodicReport::createScene() {
    Scene* scene = Scene::create();

    PeriodicReport* layer = PeriodicReport::initPeriodicReport();

    scene->addChild(layer);

    return scene;
}

PeriodicReport *PeriodicReport::initPeriodicReport() {
    PeriodicReport* periodicReport = new PeriodicReport();

    if(periodicReport && periodicReport->init())
    {
        periodicReport->visibleSize = Director::getInstance()->getVisibleSize();
        periodicReport->origin = Director::getInstance()->getVisibleOrigin();

        auto layerColor = LayerColor::create(Color4B(245, 247, 249, 255));
        periodicReport->addChild(layerColor);

        auto mainTitle = LabelTTF::create(TITLE_PERIODIC_REPORT, MAINFONT, 30);
        mainTitle->setPosition(Vec2(periodicReport->visibleSize.width - 20, periodicReport->visibleSize.height - mainTitle->getContentSize().height - 50));
        mainTitle->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
        mainTitle->setColor(Color3B::BLACK);
        periodicReport->addChild(mainTitle);

        string textArray [] = {MILEAGE,
                               MILEAGE_UNIT,
                               DRIVE_TIME,
                               SCORE,
                               SPEED_LIMIT,
                               HARSH_DRIVE,
                               UNSAFE_FIELD_DRIVE};

        ValueDailyOperation initValueDailyOperation;

        initValueDailyOperation.mileage = 36;
        initValueDailyOperation.driveTime = "01:08:46";
        initValueDailyOperation.score = 9.7;
        initValueDailyOperation.speedLimit = 0;
        initValueDailyOperation.harshDrive = 0.01;
        initValueDailyOperation.unsafeFieldDrive = 0.05;

        for(int i = 0; i < 7; i++)
        {
            auto titles = LabelTTF::create(textArray[i], MAINFONT, 30);
            titles->setPosition(Vec2(mainTitle->getPositionX(), mainTitle->getPositionY() - 150 - (titles->getContentSize().height * i)));
            titles->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
            titles->setColor(Color3B::BLACK);
            periodicReport->addChild(titles);

            auto backField = ImageView::create("backField.png");
            backField->setContentSize(Size(200, 35));
            backField->setScale9Enabled(true);
            backField->setPosition(Vec2(backField->getContentSize().width - 80, mainTitle->getPositionY() - 150 - (titles->getContentSize().height * i)));
            periodicReport->addChild(backField);

            auto values = LabelTTF::create();
            values->setPosition(Vec2(backField->getPositionX(), backField->getPositionY()));
            values->setColor(Color3B::BLACK);
            values->setFontName(MAINFONT);
            values->setFontSize(30);
            periodicReport->addChild(values);

            switch (i)
            {
                case 0:
                {
                    values->setString(StringUtils::format("%.3f", initValueDailyOperation.mileage));
                }
                    break;
                case 1:
                {
                    values->setString("Km");
                }
                    break;
                case 2:
                {
                    values->setString(initValueDailyOperation.driveTime);
                }
                    break;
                case 3:
                {
                    values->setString(StringUtils::format("%.3f", initValueDailyOperation.score));
                }
                    break;
                case 4:
                {
                    values->setString(StringUtils::format("%.3f", initValueDailyOperation.speedLimit));
                }
                    break;
                case 5:
                {
                    values->setString(StringUtils::format("%.3f", initValueDailyOperation.harshDrive));
                }
                    break;
                case 6:
                {
                    values->setString(StringUtils::format("%.3f", initValueDailyOperation.unsafeFieldDrive));
                }
                    break;
                default:
                    break;
            }
        }

        return periodicReport;
    }

    CC_SAFE_DELETE(periodicReport);
    return nullptr;
}