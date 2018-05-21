//
// Created by Mohammad Moeinfar on 5/13/2018.
//

#include "MainMenuScene.h"

MainMenuScene::MainMenuScene() {

}

MainMenuScene::~MainMenuScene() {

}

Scene *MainMenuScene::createScene() {
    Scene* scene = Scene::create();

    MainMenuScene* layer = MainMenuScene::initMainMenuScene();

    scene->addChild(layer);

    return scene;
}

MainMenuScene *MainMenuScene::initMainMenuScene() {
    MainMenuScene* mainMenuScene = new MainMenuScene();

    if(mainMenuScene && mainMenuScene->init())
    {
        mainMenuScene->visibleSize = Director::getInstance()->getVisibleSize();
        mainMenuScene->origin = Director::getInstance()->getVisibleOrigin();

        auto layerColor = LayerColor::create(Color4B(79, 107, 172, 255));
        mainMenuScene->addChild(layerColor);

        auto column = Sprite::create("column.png");
        column->setPosition(Vec2(mainMenuScene->visibleSize.width / 2 + mainMenuScene->origin.x,
                                 mainMenuScene->visibleSize.height / 2 + mainMenuScene->origin.y));
        mainMenuScene->addChild(column, 3);

        for (int i = 0; i < 6; i++)
        {
            SpecificationOptions specificationOptions;

            auto options = Button::create("option" + StringUtils::format("%i", i + 1) + ".png", "option" + StringUtils::format("%i", i + 1) + ".png");
            options->setPosition(Vec2(mainMenuScene->visibleSize.width / 2 +  + mainMenuScene->origin.x,
                                   mainMenuScene->visibleSize.height - (((options->getContentSize().height + 25) * i) + 140) + mainMenuScene->origin.y));
            options->setTag(1001 + i);
            options->addTouchEventListener(CC_CALLBACK_2(MainMenuScene::buttonEvent, mainMenuScene));
            mainMenuScene->addChild(options, 4);

            auto line = Sprite::create("line.png");
            line->setPosition(Vec2(options->getPositionX(), options->getPositionY()));
            mainMenuScene->addChild(line, 2);

            auto title = Sprite::create("toption" + StringUtils::format("%i", i + 1) + ".png");
            title->setOpacity(0);
            mainMenuScene->addChild(title, 2);

            specificationOptions.option = options;
            specificationOptions.line = line;
            specificationOptions.isPressed = false;
            specificationOptions.mainPosition = options->getPosition();
            specificationOptions.title = title;
            if((1001 + i) % 2 == 0)
            {
                specificationOptions.side = "right";
                line->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
                title->setPosition(Vec2(options->getPositionX() - 85, options->getPositionY()));
            }
            else
            {
                specificationOptions.side = "left";
                line->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
                title->setPosition(Vec2(options->getPositionX() + 85, options->getPositionY()));
            }


            mainMenuScene->listOptions.push_back(specificationOptions);

        }



        /*auto buttons = Button::create("option.png", "option.png");
        buttons->setPosition(Vec2(mainMenuScene->visibleSize.width / 2, mainMenuScene->visibleSize.height / 2 - ((buttons->getContentSize().height + 5) * 0)));
        //buttons->setTitleText(titleButtons[i]);
        //buttons->setTitleFontSize(20);
        buttons->setTag(1001 + 0);
        buttons->setPressedActionEnabled(true);
        buttons->addTouchEventListener(CC_CALLBACK_2(MainMenuScene::buttonEvent, mainMenuScene));
        mainMenuScene->addChild(buttons);*/

        /*auto logo = Sprite::create("logo.png");
        logo->setPosition(Vec2(mainMenuScene->visibleSize.width / 2 + mainMenuScene->origin.x, mainMenuScene->visibleSize.height - logo->getContentSize().height - 15 + mainMenuScene->origin.y));
        mainMenuScene->addChild(logo);

        auto title = LabelTTF::create("Car Insurance", MAINFONT, 25);
        title->setPosition(Vec2(logo->getPositionX(), logo->getPositionY() - logo->getContentSize().height / 2 - 15));
        mainMenuScene->addChild(title);

        string titleButtonArray [] = {TITLE_DAILY_OPERATION,
                                      TITLE_PERIODIC_REPORT,
                                      TITLE_INSURANCE_REPORT,
                                      TITLE_CAR_HEALTH_REPORT,
                                      TITLE_CAR_POSITION,
                                      TITLE_NEAR_DISTANCE_SERVICE_POSITION};

        for(int i = 0; i < 6; i++)
        {
            auto buttons = Button::create("loginButton.png", "loginButton.png");
            buttons->setPosition(Vec2(mainMenuScene->visibleSize.width / 2, mainMenuScene->visibleSize.height / 2 - ((buttons->getContentSize().height + 5) * i)));
            //buttons->setTitleText(titleButtons[i]);
            //buttons->setTitleFontSize(20);
            buttons->setTag(1001 + i);
            buttons->setPressedActionEnabled(true);
            buttons->addTouchEventListener(CC_CALLBACK_2(MainMenuScene::buttonEvent, mainMenuScene));
            mainMenuScene->addChild(buttons);

            auto titleButtons = LabelTTF::create(titleButtonArray[i], MAINFONT, 20);
            titleButtons->setPosition(Vec2(mainMenuScene->visibleSize.width / 2, mainMenuScene->visibleSize.height / 2 - ((buttons->getContentSize().height + 5) * i)));
            mainMenuScene->addChild(titleButtons);
        }*/

        auto pKeybackListener = EventListenerKeyboard::create();
        pKeybackListener->onKeyReleased = CC_CALLBACK_2(MainMenuScene::onKeyReleased, mainMenuScene);
        mainMenuScene->_eventDispatcher->addEventListenerWithSceneGraphPriority(pKeybackListener, mainMenuScene);

        return mainMenuScene;
    }

    CC_SAFE_DELETE(mainMenuScene);
    return nullptr;
}

void MainMenuScene::textFieldEvent(Ref *pSender, TextField::EventType type)
{
    switch (type)
    {
        case TextField::EventType::ATTACH_WITH_IME:
        {
            /*TextField* textField = dynamic_cast<TextField*>(pSender);
            Size widgetSize = visibleSize;
            textField->runAction(MoveTo::create(0.225f,
                                                Vec2(widgetSize.width / 2.0f, widgetSize.height / 2.0f + 30)));*/
            //_displayValueLabel->setString(StringUtils::format("attach with IME"));
        }
            break;

        case TextField::EventType::DETACH_WITH_IME:
        {
            TextField* textField = dynamic_cast<TextField*>(pSender);
            //Size screenSize = Director::getInstance()->getWinSize();
            //textField->runAction(MoveTo::create(0.175f, Vec2(screenSize.width / 2.0f, screenSize.height / 2.0f)));
            textField->setTextHorizontalAlignment(TextHAlignment::CENTER);
            textField->setTextVerticalAlignment(TextVAlignment::CENTER);

            //_displayValueLabel->setString(StringUtils::format("detach with IME"));
        }
            break;

        case TextField::EventType::INSERT_TEXT:
            //_displayValueLabel->setString(StringUtils::format("insert words"));
            break;

        case TextField::EventType::DELETE_BACKWARD:
            //_displayValueLabel->setString(StringUtils::format("delete word"));
            break;
    }
}

void MainMenuScene::buttonEvent(Ref *pSender, Widget::TouchEventType type)
{
    Button* sender = (Button*) pSender;

    switch (type)
    {
        case Widget::TouchEventType ::BEGAN:
        {
            for (int i = 0; i < listOptions.size(); i++)
            {
                if((listOptions.at(i).option->getTag() == sender->getTag()) && listOptions.at(i).isPressed)
                {
                    switch (sender->getTag())
                    {
                        case DAILY_OPERATION:
                        {
                            auto scene = DailyOperation::createScene();
                            Director::getInstance()->replaceScene(TransitionMoveInR::create(0.3, scene));
                        }
                            break;
                        case PERIODIC_REPORT:
                        {
                            auto scene = PeriodicReport::createScene();
                            Director::getInstance()->replaceScene(TransitionMoveInR::create(0.3, scene));
                        }
                            break;
                        case INSURANCE_REPORT:
                        {
                            auto scene = InsuranceReport::createScene();
                            Director::getInstance()->replaceScene(TransitionMoveInR::create(0.3, scene));
                        }
                            break;
                        case CAR_HEALTH_REPORT:
                        {
                            auto scene = CarHealthReport::createScene();
                            Director::getInstance()->replaceScene(TransitionMoveInR::create(0.3, scene));
                        }
                            break;
                        case CAR_POSITION:
                        {
                            auto scene = CarLocation::createScene();
                            Director::getInstance()->replaceScene(TransitionMoveInR::create(0.3, scene));
                        }
                            break;
                        case NEAR_DISTANCE_SERVICE_POSITION:
                        {
                            auto scene = NearDistanceServicePosition::createScene();
                            Director::getInstance()->replaceScene(TransitionMoveInR::create(0.3, scene));
                        }
                            break;
                        default:break;
                    }
                }
            }
        }
            break;
        case Widget::TouchEventType::ENDED:
        {

            for (int i = 0; i < listOptions.size(); i++)
            {
                if((listOptions.at(i).option->getTag() == sender->getTag()))
                {
                    if(!listOptions.at(i).isPressed)
                    {
                        if(listOptions.at(i).side == "left")
                        {
                            sender->runAction(Sequence::create(
                                    ScaleTo::create(0.05, 1.1),
                                    ScaleTo::create(0.05, 1.0),
                                    ScaleTo::create(0.05, 1.1),
                                    ScaleTo::create(0.05, 1.0),
                                    MoveTo::create(0.1, Vec2(sender->getPositionX() + 180, sender->getPositionY())), nullptr));

                            listOptions.at(i).line->runAction(
                                    Sequence::create(DelayTime::create(0.2),
                                            ScaleTo::create(0.07, listOptions.at(i).line->getScaleX() + 10, listOptions.at(i).line->getScaleY()), nullptr));

                            listOptions.at(i).title->runAction(
                                    Sequence::create(DelayTime::create(0.2),
                                                     FadeTo::create(0.1, 255), nullptr));
                        }
                        else
                        {
                            sender->runAction(Sequence::create(
                                    ScaleTo::create(0.05, 1.1),
                                    ScaleTo::create(0.05, 1.0),
                                    ScaleTo::create(0.05, 1.1),
                                    ScaleTo::create(0.05, 1.0),
                                    MoveTo::create(0.1, Vec2(sender->getPositionX() - 180, sender->getPositionY())), nullptr));

                            listOptions.at(i).line->runAction(
                                    Sequence::create(DelayTime::create(0.2),
                                                     ScaleTo::create(0.07, listOptions.at(i).line->getScaleX() + 10, listOptions.at(i).line->getScaleY()), nullptr));

                            listOptions.at(i).title->runAction(
                                    Sequence::create(DelayTime::create(0.2),
                                                     FadeTo::create(0.1, 255), nullptr));
                        }

                        listOptions.at(i).isPressed = true;
                    }
                }
                else
                {
                    listOptions.at(i).option->runAction(MoveTo::create(0.1, listOptions.at(i).mainPosition));

                    listOptions.at(i).line->runAction(
                            ScaleTo::create(0.1, 0, listOptions.at(i).line->getScaleY()));

                    listOptions.at(i).title->runAction(FadeTo::create(0.1, 0));

                    listOptions.at(i).isPressed = false;
                }
            }

            /*switch (sender->getTag())
            {
                case DAILY_OPERATION:
                {
                    auto scene = DailyOperation::createScene();
                    Director::getInstance()->replaceScene(TransitionMoveInR::create(0.3, scene));
                }
                    break;
                case PERIODIC_REPORT:
                {
                    auto scene = PeriodicReport::createScene();
                    Director::getInstance()->replaceScene(TransitionMoveInR::create(0.3, scene));
                }
                    break;
                case INSURANCE_REPORT:
                {
                    auto scene = InsuranceReport::createScene();
                    Director::getInstance()->replaceScene(TransitionMoveInR::create(0.3, scene));
                }
                    break;
                case CAR_HEALTH_REPORT:
                {
                    auto scene = CarHealthReport::createScene();
                    Director::getInstance()->replaceScene(TransitionMoveInR::create(0.3, scene));
                }
                    break;
                case CAR_POSITION:
                {
                    auto scene = CarLocation::createScene();
                    Director::getInstance()->replaceScene(TransitionMoveInR::create(0.3, scene));
                }
                    break;
                case NEAR_DISTANCE_SERVICE_POSITION:
                {
                    auto scene = NearDistanceServicePosition::createScene();
                    Director::getInstance()->replaceScene(TransitionMoveInR::create(0.3, scene));
                }
                    break;
            }*/
        }
            break;
        case Widget::TouchEventType::MOVED:break;
        case Widget::TouchEventType::CANCELED:break;
    }
}

void MainMenuScene::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent) {
    if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
    {
        auto scene = Login::createScene();
        Director::getInstance()->replaceScene(TransitionMoveInL::create(0.3, scene));
    }
}

void MainMenuScene::readData() {

    /*long filesize = 0;
    string content;
    string fullPath = "MockData.json";

    auto fileData = FileUtils::getInstance()->getFileData(fullPath.c_str(), "r", (ssize_t *) &filesize);
    content.append((char*)fileData);

    if (strcmp(content.c_str(), ""))
        if (strcmp(content.c_str(), "[]"))
        {
            Document document;
            document.Parse(content.c_str());

            for (int ind = 0; ind <= document.Size() - 1; ind++)
            {
                auto str = document[ind]["Login"].GetString();
                int x=0;
            }
        }

    int x=0;*/

}

