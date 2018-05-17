//
// Created by Mohammad Moeinfar on 5/15/2018.
//

#include "InsuranceReport.h"

InsuranceReport::InsuranceReport() {

}

InsuranceReport::~InsuranceReport() {

}

Scene *InsuranceReport::createScene() {
    Scene* scene = Scene::create();

    InsuranceReport* layer = InsuranceReport::initInsuranceReport();

    scene->addChild(layer);

    return scene;
}

InsuranceReport *InsuranceReport::initInsuranceReport() {
    InsuranceReport* insuranceReport = new InsuranceReport();

    if(insuranceReport && insuranceReport->init())
    {
        insuranceReport->visibleSize = Director::getInstance()->getVisibleSize();
        insuranceReport->origin = Director::getInstance()->getVisibleOrigin();

        auto layerColor = LayerColor::create(Color4B(245, 247, 249, 255));
        insuranceReport->addChild(layerColor);

        auto mainTitle = LabelTTF::create(TITLE_INSURANCE_REPORT, MAINFONT, 30);
        mainTitle->setPosition(Vec2(insuranceReport->visibleSize.width - 20, insuranceReport->visibleSize.height - mainTitle->getContentSize().height - 50));
        mainTitle->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
        mainTitle->setColor(Color3B::BLACK);
        insuranceReport->addChild(mainTitle);

        ListOfInsurances initListOfInsurances;

        initListOfInsurances.theThirdParty.insuranceTitle = "ThirdParty";
        initListOfInsurances.theThirdParty.insuranceID = 89766578866;
        initListOfInsurances.theThirdParty.insuranceStartUtc = 6453343435;
        initListOfInsurances.theThirdParty.insuranceEndUtc = 7665765675;
        initListOfInsurances.theThirdParty.someMoreInsuranceData = "ThirdParty Data";

        initListOfInsurances.theCarBody.insuranceTitle = "CarBody";
        initListOfInsurances.theCarBody.insuranceID = 89766578866;
        initListOfInsurances.theCarBody.insuranceStartUtc = 6453343435;
        initListOfInsurances.theCarBody.insuranceEndUtc = 7665765675;
        initListOfInsurances.theCarBody.someMoreInsuranceData = "CarBody Data";

        initListOfInsurances.theLifeAndHealth.insuranceTitle = "LifeAndHealth";
        initListOfInsurances.theLifeAndHealth.insuranceID = 89766578866;
        initListOfInsurances.theLifeAndHealth.insuranceStartUtc = 6453343435;
        initListOfInsurances.theLifeAndHealth.insuranceEndUtc = 7665765675;
        initListOfInsurances.theLifeAndHealth.someMoreInsuranceData = "LifeAndHealth Data";

        auto arrTitlesInsuranceReport = initInsurances();

        std::vector<string> temp;
        int padding = 0;
        Vec2 lastPosition = Vec2::ZERO;

        for(int i = 0; i < arrTitlesInsuranceReport.size(); i++)
        {
            temp = arrTitlesInsuranceReport.at(i);

            for(int j = 0; j < temp.size(); j++)
            {
                auto titles = LabelTTF::create(temp.at(j), MAINFONT, 30);
                titles->setPosition(Vec2(mainTitle->getPositionX(), mainTitle->getPositionY() - 100 - padding - (titles->getContentSize().height / 1.5 * j)));
                titles->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
                titles->setColor(Color3B::BLACK);
                insuranceReport->addChild(titles);

                auto backField = ImageView::create("backField.png");
                backField->setContentSize(Size(200, 25));
                backField->setScale9Enabled(true);
                backField->setPosition(Vec2(backField->getContentSize().width - 80, mainTitle->getPositionY() - 100 - padding - (titles->getContentSize().height / 1.5 * j)));
                insuranceReport->addChild(backField);

                auto values = LabelTTF::create();
                values->setPosition(Vec2(backField->getPositionX(), backField->getPositionY()));
                values->setColor(Color3B::BLACK);
                values->setFontName(MAINFONT);
                values->setFontSize(20);
                insuranceReport->addChild(values);

                switch (i)
                {
                    case 0:
                    {
                        switch (j)
                        {
                            case 0: values->setString(THIRDPARTY);
                                break;
                            case 1: values->setString(StringUtils::format("%lli", initListOfInsurances.theThirdParty.insuranceID));
                                break;
                            case 2: values->setString(StringUtils::format("%lli", initListOfInsurances.theThirdParty.insuranceStartUtc));
                                break;
                            case 3: values->setString(StringUtils::format("%lli", initListOfInsurances.theThirdParty.insuranceEndUtc));
                                break;
                            case 4: values->setString(initListOfInsurances.theThirdParty.someMoreInsuranceData);
                                break;
                        }
                    }
                        break;
                    case 1:
                    {
                        switch (j)
                        {
                            case 0: values->setString(CARBODY);
                                break;
                            case 1: values->setString(StringUtils::format("%lli", initListOfInsurances.theCarBody.insuranceID));
                                break;
                            case 2: values->setString(StringUtils::format("%lli", initListOfInsurances.theCarBody.insuranceStartUtc));
                                break;
                            case 3: values->setString(StringUtils::format("%lli", initListOfInsurances.theCarBody.insuranceEndUtc));
                                break;
                            case 4: values->setString(initListOfInsurances.theCarBody.someMoreInsuranceData);
                                break;
                        }
                    }
                        break;
                    case 2:
                    {
                        switch (j)
                        {
                            case 0: values->setString(LIFE_HEALTH);
                                break;
                            case 1: values->setString(StringUtils::format("%lli", initListOfInsurances.theLifeAndHealth.insuranceID));
                                break;
                            case 2: values->setString(StringUtils::format("%lli", initListOfInsurances.theLifeAndHealth.insuranceStartUtc));
                                break;
                            case 3: values->setString(StringUtils::format("%lli", initListOfInsurances.theLifeAndHealth.insuranceEndUtc));
                                break;
                            case 4: values->setString(initListOfInsurances.theLifeAndHealth.someMoreInsuranceData);
                                break;
                        }
                    }
                        break;
                }

            }
            padding += (30 * 8 - 50);
        }

        auto pKeybackListener = EventListenerKeyboard::create();
        pKeybackListener->onKeyReleased = CC_CALLBACK_2(InsuranceReport::onKeyReleased, insuranceReport);
        insuranceReport->_eventDispatcher->addEventListenerWithSceneGraphPriority(pKeybackListener, insuranceReport);

        return insuranceReport;
    }

    CC_SAFE_DELETE(insuranceReport);
    return nullptr;
}

void InsuranceReport::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent) {
    if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
    {
        auto scene = MainMenuScene::createScene();
        Director::getInstance()->replaceScene(TransitionMoveInL::create(0.3, scene));
    }
}