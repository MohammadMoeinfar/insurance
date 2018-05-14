//
// Created by Mohammad Moeinfar on 5/14/2018.
//

#include "DailyOperation.h"

DailyOperation::DailyOperation() {

}

DailyOperation::~DailyOperation() {

}

Scene *DailyOperation::createScene() {
    Scene* scene = Scene::create();

    DailyOperation* layer = DailyOperation::initDailyOperation();

    scene->addChild(layer);

    return scene;
}

DailyOperation *DailyOperation::initDailyOperation() {
    DailyOperation* dailyOperation = new DailyOperation();

    if(dailyOperation && dailyOperation->init())
    {
        dailyOperation->visibleSize = Director::getInstance()->getVisibleSize();
        dailyOperation->origin = Director::getInstance()->getVisibleOrigin();

        auto layerColor = LayerColor::create(Color4B(245, 247, 249, 255));
        dailyOperation->addChild(layerColor);

        auto mainTitle = LabelTTF::create(TITLE_DAILY_OPERATION, MAINFONT, 30);
        mainTitle->setPosition(Vec2(dailyOperation->visibleSize.width - 20, dailyOperation->visibleSize.height - mainTitle->getContentSize().height - 50));
        mainTitle->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
        mainTitle->setColor(Color3B::BLACK);
        dailyOperation->addChild(mainTitle);

        string textArray [] = {MILEAGE,
                               MILEAGE_UNIT,
                               DRIVE_TIME,
                               SCORE,
                               SPEED_LIMIT,
                               HARSH_DRIVE,
                               UNSAFE_FIELD_DRIVE};

        for(int i = 0; i < 7; i++)
        {
            auto titles = LabelTTF::create(textArray[i], MAINFONT, 30);
            titles->setPosition(Vec2(mainTitle->getPositionX(), mainTitle->getPositionY() - 150 - (titles->getContentSize().height * i)));
            titles->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
            titles->setColor(Color3B::BLACK);
            dailyOperation->addChild(titles);

            auto backField = ImageView::create("backField.png");
            backField->setContentSize(Size(200, 35));
            backField->setScale9Enabled(true);
            backField->setPosition(Vec2(backField->getContentSize().width - 80, mainTitle->getPositionY() - 150 - (titles->getContentSize().height * i)));
            dailyOperation->addChild(backField);
        }

        return dailyOperation;
    }

    CC_SAFE_DELETE(dailyOperation);
    return nullptr;
}