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

        //periodicReport->scheduleUpdate();

        auto layerColor = LayerGradient::create(Color4B(255, 167, 37, 255), Color4B(255, 167, 37, 0));
        periodicReport->addChild(layerColor);

        auto mainTitle = LabelTTF::create(TITLE_PERIODIC_REPORT, MAINFONT, 30);
        mainTitle->setPosition(Vec2(periodicReport->visibleSize.width - 20, periodicReport->visibleSize.height - mainTitle->getContentSize().height - 20));
        mainTitle->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
        mainTitle->setColor(Color3B(50, 50, 50));
        periodicReport->addChild(mainTitle);

		auto back = Button::create("back.png", "back.png");
		back->setPosition(Vec2(back->getContentSize().width / 2 + 10, periodicReport->visibleSize.height - back->getContentSize().height / 2 - 10));
		back->setOpacity(150);
		back->setTag(BACK_BUTTON);
		back->setCascadeColorEnabled(true);
		back->setColor(Color3B::GRAY);
		periodicReport->addChild(back, 40);
		back->addTouchEventListener(CC_CALLBACK_2(PeriodicReport::eventLayout, periodicReport));

        periodicReport->backScore = Sprite::create("backScore.png");
        periodicReport->backScore->setPosition(Vec2(periodicReport->visibleSize.width / 2 + periodicReport->origin.x,
                                                    periodicReport->visibleSize.height - periodicReport->backScore->getContentSize().height / 2 - 100));

        auto action = Sequence::create(
                CallFunc::create( std::bind( &PeriodicReport::repeatForever, periodicReport, periodicReport->backScore) ),
                nullptr);

        periodicReport->backScore->runAction(action);

        periodicReport->addChild(periodicReport->backScore);

        auto myScore = Sprite::create();
        myScore->setTexture("score.png");

        auto score = ProgressTimer::create(myScore);
        score->setPosition(periodicReport->backScore->getPosition());
        score->setType(ProgressTimer::Type::RADIAL);
        score->setPercentage(9.7);
        periodicReport->addChild(score);

        auto scoreCount = LabelTTF::create("9.7", MAINFONT, 50);
        scoreCount->setPosition(periodicReport->backScore->getPosition());
        periodicReport->addChild(scoreCount);

        auto scoreTitle = LabelTTF::create(SCORE, MAINFONT, 30);
        scoreTitle->setPosition(Vec2(periodicReport->backScore->getPositionX(),
                                     periodicReport->backScore->getPositionY() - periodicReport->backScore->getContentSize().height / 2 - 30));
        periodicReport->addChild(scoreTitle);

        string textArray [] = {MILEAGE,
                               MILEAGE_UNIT,
                               DRIVE_TIME,
                               SPEED_LIMIT,
                               HARSH_DRIVE,
                               UNSAFE_FIELD_DRIVE};

        ValuePeriodicReport initValueperiodicReport;

        initValueperiodicReport.mileage = 36;
        initValueperiodicReport.driveTime = "01:08:46";
        initValueperiodicReport.score = 9.7;
        initValueperiodicReport.speedLimit = 0;
        initValueperiodicReport.harshDrive = 0.01;
        initValueperiodicReport.unsafeFieldDrive = 0.05;

        Size scrollViewSize(layerColor->getContentSize().width, layerColor->getContentSize().height);

        periodicReport->listView = cocos2d::ui::ListView::create();
        periodicReport->listView->setDirection(ui::ScrollView::Direction::VERTICAL);
        periodicReport->listView->setBounceEnabled(true);
        periodicReport->listView->setBackGroundColorOpacity(100);
        periodicReport->listView->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
        periodicReport->listView->setContentSize(Size(scrollViewSize.width, scrollViewSize.height - 200));
        periodicReport->listView->setPosition(Vec2(periodicReport->visibleSize.width / 2 + periodicReport->origin.x, scoreTitle->getPositionY() - 355));
        periodicReport->listView->setScrollBarPositionFromCorner(Vec2(4, 4));
        periodicReport->addChild(periodicReport->listView);

        Layout* default_item = Layout::create();
        default_item->setTouchEnabled(true);
        default_item->setContentSize(Size(400, 50));
        periodicReport->listView->addChild(default_item);

        periodicReport->listView->setItemModel(default_item);
        periodicReport->listView->setGravity(ListView::Gravity::TOP);
        periodicReport->listView->setItemsMargin(1.5);
        periodicReport->listView->forceDoLayout();
        periodicReport->listView->setInnerContainerSize(Size(scrollViewSize.width, scrollViewSize.height*1.1));
        //periodicReport->listView->addEventListener((ui::ListView::ccListViewCallback)CC_CALLBACK_2(BallsList::selectedItemEvent, this));
        periodicReport->listView->jumpToTop();

        for(int i = 0; i < 6; i++)
        {
            lstLayoutOfListviwe layoutOfListviwe;

            Widget* item = default_item->clone();

            auto layout = Layout::create();
			layout->setBackGroundColorType(Layout::BackGroundColorType::GRADIENT);
			layout->setBackGroundColor(Color3B(255, 167, 37), Color3B(255, 255, 255));
            layout->setContentSize(Size(400, 50));
            layout->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
            layout->setTouchEnabled(true);
            layout->setPosition(Vec2(240, default_item->getContentSize().height + 50));
            layout->addTouchEventListener(CC_CALLBACK_2(PeriodicReport::eventLayout, periodicReport));
            layout->setTag(2001 + i);
            item->addChild(layout);

            auto titles = LabelTTF::create(textArray[i], MAINFONT, 20);
            titles->setPosition(Vec2(layout->getContentSize().width / 2, layout->getContentSize().height - titles->getContentSize().height / 2 - 5));
            titles->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
            titles->setColor(Color3B(50, 50, 50));
            layout->addChild(titles);

            auto values = LabelTTF::create();
            values->setPosition(Vec2(titles->getPositionX(), titles->getPositionY() - 10));
            values->setColor(Color3B(50, 50, 50));
            values->setFontName(MAINFONT);
            values->setFontSize(25);
            values->setOpacity(0);
            layout->addChild(values);

            switch (i)
            {
                case 0:
                {
                    values->setString(StringUtils::format("%.3f", initValueperiodicReport.mileage));
                }
                    break;
                case 1:
                {
                    values->setString("Km");
                }
                    break;
                case 2:
                {
                    values->setString(initValueperiodicReport.driveTime);
                }
                    break;
                    /*case 3:
                    {
                        values->setString(StringUtils::format("%.3f", initValueperiodicReport.score));
                    }
                        break;*/
                case 3:
                {
                    values->setString(StringUtils::format("%.3f", initValueperiodicReport.speedLimit));
                }
                    break;
                case 4:
                {
                    values->setString(StringUtils::format("%.3f", initValueperiodicReport.harshDrive));
                }
                    break;
                case 5:
                {
                    values->setString(StringUtils::format("%.3f", initValueperiodicReport.unsafeFieldDrive));
                }
                    break;
                default:
                    break;
            }

            layoutOfListviwe.layout = layout;
            layoutOfListviwe.title = titles;
            layoutOfListviwe.value = values;
            layoutOfListviwe.mainPosition = layout->getPosition();
            layoutOfListviwe.mainPositionTitle = titles->getPosition();

            periodicReport->listLayout.push_back(layoutOfListviwe);

            periodicReport->listView->pushBackCustomItem(item);
        }

        auto pKeybackListener = EventListenerKeyboard::create();
        pKeybackListener->onKeyReleased = CC_CALLBACK_2(PeriodicReport::onKeyReleased, periodicReport);
        periodicReport->_eventDispatcher->addEventListenerWithSceneGraphPriority(pKeybackListener, periodicReport);

        return periodicReport;
    }

    CC_SAFE_DELETE(periodicReport);
    return nullptr;
}

void PeriodicReport::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent) {
    if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
    {
        auto scene = MainMenuScene::createScene();
        Director::getInstance()->replaceScene(TransitionMoveInL::create(0.3, scene));
    }
}

void PeriodicReport::repeatForever(Node* sender)
{
    auto repeat = RepeatForever::create( RotateBy::create(20.0f, 360) );

    sender->runAction(repeat);
}

void PeriodicReport::eventLayout(Ref *pSender, Widget::TouchEventType type)
{
    Layout* sender = (Layout*) pSender;

    switch (type)
    {
        case Widget::TouchEventType::ENDED:
        {
			switch (sender->getTag())
			{
				case BACK_BUTTON:
				{
					auto scene = MainMenuScene::createScene();
					Director::getInstance()->replaceScene(TransitionMoveInL::create(0.3, scene));
				}
			}
		
            if(sender->getContentSize().height == 50)
            {
                sender->runAction(Spawn::create(
                        ResizeTo::create(0.5, Size(400, 100)),
                        CallFunc::create([&, this](){
                            for(auto item : listLayout)
                            {
                                if(item.layout->getTag() == sender->getTag())
                                {
                                    item.title->runAction(MoveTo::create(0.5, Vec2(item.mainPositionTitle.x, item.mainPositionTitle.y + 50)));
                                    item.value->runAction(FadeTo::create(0.5, 255));
                                }
                            }
                        }), nullptr));
            }
            else
            {
                sender->runAction(Spawn::create(
                        ResizeTo::create(0.5, Size(400, 50)),
                        CallFunc::create([&, this](){
                            for(auto item : listLayout)
                            {
                                if(item.layout->getTag() == sender->getTag())
                                {
                                    item.title->runAction(MoveTo::create(0.5, Vec2(item.mainPositionTitle.x, item.mainPositionTitle.y)));
                                    item.value->runAction(FadeTo::create(0.5, 0));
                                }
                                else
                                {
                                    item.layout->runAction(MoveTo::create(0.5, item.mainPosition));
                                }
                            }
                        }), nullptr));
            }

            for(auto item : listLayout)
            {
                if(item.layout->getTag() != sender->getTag())
                {
                    item.layout->setContentSize(Size(400, 50));
                    item.value->setOpacity(0);
                    item.title->setPosition(item.mainPositionTitle);
                }

                if(item.layout->getTag() > sender->getTag())
                {
                    item.layout->setPositionY(item.mainPosition.y);
                    item.layout->setPositionY(item.layout->getPositionY() - 50);
                    //item.title->setPosition(item.mainPositionTitle);
                }
                else
                {
                    item.layout->setPositionY(item.mainPosition.y);
                    //item.title->setPosition(item.mainPositionTitle);
                }
            }
        }
            break;
        default:
            break;
    }
}