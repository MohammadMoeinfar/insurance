//
// Created by Mohammad Moeinfar on 5/15/2018.
//

#include "CarHealthReport.h"

CarHealthReport::CarHealthReport() {

}

CarHealthReport::~CarHealthReport() {

}

Scene *CarHealthReport::createScene() {
    Scene* scene = Scene::create();

    CarHealthReport* layer = CarHealthReport::initCarHealthReport();

    scene->addChild(layer);

    return scene;
}

CarHealthReport *CarHealthReport::initCarHealthReport() {
    CarHealthReport* carHealthReport = new CarHealthReport();

    if(carHealthReport && carHealthReport->init())
    {
        carHealthReport->visibleSize = Director::getInstance()->getVisibleSize();
        carHealthReport->origin = Director::getInstance()->getVisibleOrigin();

        auto layerColor = LayerColor::create(Color4B(245, 247, 249, 255));
        carHealthReport->addChild(layerColor);

        auto mainTitle = LabelTTF::create(TITLE_CAR_HEALTH_REPORT, MAINFONT, 30);
        mainTitle->setPosition(Vec2(carHealthReport->visibleSize.width - 20, carHealthReport->visibleSize.height - mainTitle->getContentSize().height - 50));
        mainTitle->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
        mainTitle->setColor(Color3B::BLACK);
        carHealthReport->addChild(mainTitle);

        ListOfCarHealth initListOfCarHealth;

        initListOfCarHealth.theUnitEngine.EcuName = "Engine";
        initListOfCarHealth.theUnitEngine.p001 = "Some where is faulty!!!";
        initListOfCarHealth.theUnitEngine.u034 = "Some where else is faulty!!!";

        initListOfCarHealth.theUnitABS.EcuName = "ABS";
        initListOfCarHealth.theUnitABS.p001 = "Some where is faulty!!!";
        initListOfCarHealth.theUnitABS.u034 = "Some where else is faulty!!!";

        initListOfCarHealth.theUnitBSI.EcuName = "BSI";
        initListOfCarHealth.theUnitBSI.p001 = "Some where is faulty!!!";
        initListOfCarHealth.theUnitBSI.u034 = "Some where else is faulty!!!";

        auto arrTitlesCarHealth = initCarHealth();

        std::vector<string> temp;
        int padding = 0;
        Vec2 lastPosition = Vec2::ZERO;

        for(int i = 0; i < arrTitlesCarHealth.size(); i++)
        {
            temp = arrTitlesCarHealth.at(i);

            for(int j = 0; j < temp.size(); j++)
            {
                auto titles = LabelTTF::create(temp.at(j), MAINFONT, 25);
                titles->setPosition(Vec2(mainTitle->getPositionX(), mainTitle->getPositionY() - 100 - padding - (titles->getContentSize().height / 1.5 * j)));
                titles->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
                titles->setColor(Color3B::BLACK);
                carHealthReport->addChild(titles);

                auto backField = ImageView::create("backField.png");
                backField->setContentSize(Size(200, 25));
                backField->setScale9Enabled(true);
                backField->setPosition(Vec2(backField->getContentSize().width - 80, mainTitle->getPositionY() - 100 - padding - (titles->getContentSize().height / 1.5 * j)));
                carHealthReport->addChild(backField);

                auto values = LabelTTF::create();
                values->setPosition(Vec2(backField->getPositionX(), backField->getPositionY()));
                values->setColor(Color3B::BLACK);
                values->setFontName(MAINFONT);
                values->setFontSize(15);
                carHealthReport->addChild(values);

                switch (i)
                {
                    case 0:
                    {
                        switch (j)
                        {
                            case 0: values->setString(ENGINE);
                                break;
                            case 1: values->setString(initListOfCarHealth.theUnitBSI.p001);
                                break;
                            case 2: values->setString(initListOfCarHealth.theUnitBSI.u034);
                                break;
                        }
                    }
                        break;
                    case 1:
                    {
                        switch (j)
                        {
                            case 0: values->setString(ABS_BRAKES);
                                break;
                            case 1: values->setString(initListOfCarHealth.theUnitBSI.p001);
                                break;
                            case 2: values->setString(initListOfCarHealth.theUnitBSI.u034);
                                break;
                        }
                    }
                        break;
                    case 2:
                    {
                        switch (j)
                        {
                            case 0: values->setString(BSI);
                                break;
                            case 1: values->setString(initListOfCarHealth.theUnitBSI.p001);
                                break;
                            case 2: values->setString(initListOfCarHealth.theUnitBSI.u034);
                                break;
                        }
                    }
                        break;
                }

            }
            padding += (30 * 8 - 50);
        }

        return carHealthReport;
    }

    CC_SAFE_DELETE(carHealthReport);
    return nullptr;
}