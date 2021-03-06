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

        //dailyOperation->scheduleUpdate();

        auto layerColor = LayerGradient::create(Color4B(186, 104, 200, 150), Color4B(186, 104, 200, 0));
        dailyOperation->addChild(layerColor);

        auto mainTitle = LabelTTF::create(TITLE_DAILY_OPERATION, MAINFONT, 30);
        mainTitle->setPosition(Vec2(dailyOperation->visibleSize.width - 20, dailyOperation->visibleSize.height - mainTitle->getContentSize().height - 20));
        mainTitle->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
        mainTitle->setColor(Color3B(50, 50, 50));
        dailyOperation->addChild(mainTitle);

		auto back = Button::create("back.png", "back.png");
		back->setPosition(Vec2(back->getContentSize().width / 2 + 10, dailyOperation->visibleSize.height - back->getContentSize().height / 2 - 10));
		back->setOpacity(150);
		back->setTag(BACK_BUTTON);
		back->setCascadeColorEnabled(true);
		back->setColor(Color3B::GRAY);
		dailyOperation->addChild(back, 40);
		back->addTouchEventListener(CC_CALLBACK_2(DailyOperation::eventLayout, dailyOperation));

        dailyOperation->backScore = Sprite::create("backScore.png");
        dailyOperation->backScore->setPosition(Vec2(dailyOperation->visibleSize.width / 2 + dailyOperation->origin.x,
                                    dailyOperation->visibleSize.height - dailyOperation->backScore->getContentSize().height / 2 - 100));

        auto action = Sequence::create(
                CallFunc::create( std::bind( &DailyOperation::repeatForever, dailyOperation, dailyOperation->backScore) ),
                nullptr);

        dailyOperation->backScore->runAction(action);

        dailyOperation->addChild(dailyOperation->backScore);

        auto myScore = Sprite::create();
        myScore->setTexture("score.png");

        auto score = ProgressTimer::create(myScore);
        score->setPosition(dailyOperation->backScore->getPosition());
        score->setType(ProgressTimer::Type::RADIAL);
        score->setPercentage(9.7);
        dailyOperation->addChild(score);

        auto scoreCount = LabelTTF::create("9.7", MAINFONT, 50);
        scoreCount->setPosition(dailyOperation->backScore->getPosition());
        dailyOperation->addChild(scoreCount);

        auto scoreTitle = LabelTTF::create(SCORE, MAINFONT, 30);
        scoreTitle->setPosition(Vec2(dailyOperation->backScore->getPositionX(),
                                     dailyOperation->backScore->getPositionY() - dailyOperation->backScore->getContentSize().height / 2 - 30));
        dailyOperation->addChild(scoreTitle);

        string textArray [] = {MILEAGE,
                               MILEAGE_UNIT,
                               DRIVE_TIME,
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

        Size scrollViewSize(layerColor->getContentSize().width, layerColor->getContentSize().height);

        dailyOperation->listView = cocos2d::ui::ListView::create();
        dailyOperation->listView->setDirection(ui::ScrollView::Direction::VERTICAL);
        dailyOperation->listView->setBounceEnabled(true);
        dailyOperation->listView->setBackGroundColorOpacity(100);
        dailyOperation->listView->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
        dailyOperation->listView->setContentSize(Size(scrollViewSize.width, scrollViewSize.height - 200));
        dailyOperation->listView->setPosition(Vec2(dailyOperation->visibleSize.width / 2 + dailyOperation->origin.x, scoreTitle->getPositionY() - 355));
        dailyOperation->listView->setScrollBarPositionFromCorner(Vec2(4, 4));
        dailyOperation->addChild(dailyOperation->listView);

        Layout* default_item = Layout::create();
        default_item->setTouchEnabled(true);
        default_item->setContentSize(Size(400, 50));
        dailyOperation->listView->addChild(default_item);

        dailyOperation->listView->setItemModel(default_item);
        dailyOperation->listView->setGravity(ListView::Gravity::TOP);
        dailyOperation->listView->setItemsMargin(1.5);
        dailyOperation->listView->forceDoLayout();
        dailyOperation->listView->setInnerContainerSize(Size(scrollViewSize.width, scrollViewSize.height*1.1));
        //dailyOperation->listView->addEventListener((ui::ListView::ccListViewCallback)CC_CALLBACK_2(BallsList::selectedItemEvent, this));
        dailyOperation->listView->jumpToTop();

        for(int i = 0; i < 6; i++)
        {
            lstLayoutOfListviwe layoutOfListviwe;

            Widget* item = default_item->clone();

            auto layout = Layout::create();
			layout->setBackGroundColorType(Layout::BackGroundColorType::GRADIENT);
			layout->setBackGroundColor(Color3B(186, 104, 200), Color3B(255, 255, 255));
            layout->setContentSize(Size(400, 50));
            layout->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
            layout->setTouchEnabled(true);
            layout->setPosition(Vec2(240, default_item->getContentSize().height + 50));
            layout->addTouchEventListener(CC_CALLBACK_2(DailyOperation::eventLayout, dailyOperation));
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
                /*case 3:
                {
                    values->setString(StringUtils::format("%.3f", initValueDailyOperation.score));
                }
                    break;*/
                case 3:
                {
                    values->setString(StringUtils::format("%.3f", initValueDailyOperation.speedLimit));
                }
                    break;
                case 4:
                {
                    values->setString(StringUtils::format("%.3f", initValueDailyOperation.harshDrive));
                }
                    break;
                case 5:
                {
                    values->setString(StringUtils::format("%.3f", initValueDailyOperation.unsafeFieldDrive));
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

            dailyOperation->listLayout.push_back(layoutOfListviwe);

            dailyOperation->listView->pushBackCustomItem(item);
        }

        auto pKeybackListener = EventListenerKeyboard::create();
        pKeybackListener->onKeyReleased = CC_CALLBACK_2(DailyOperation::onKeyReleased, dailyOperation);
        dailyOperation->_eventDispatcher->addEventListenerWithSceneGraphPriority(pKeybackListener, dailyOperation);

        return dailyOperation;
    }

    CC_SAFE_DELETE(dailyOperation);
    return nullptr;
}

void DailyOperation::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent) {
    if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
    {
        auto scene = MainMenuScene::createScene();
        Director::getInstance()->replaceScene(TransitionMoveInL::create(0.3, scene));
    }
}

void DailyOperation::update(float dt)
{
    backScore->runAction(RepeatForever::create(RotateTo::create(0.5, 10)));
}

void DailyOperation::repeatForever(Node* sender)
{
    auto repeat = RepeatForever::create( RotateBy::create(20.0f, 360) );

    sender->runAction(repeat);
}

void DailyOperation::eventLayout(Ref *pSender, Widget::TouchEventType type)
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