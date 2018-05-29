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

		auto layerColor = LayerGradient::create(Color4B(101, 186, 106, 255), Color4B(101, 186, 106, 0));
		carHealthReport->addChild(layerColor);

		auto mainTitle = LabelTTF::create(TITLE_CAR_HEALTH_REPORT, MAINFONT, 30);
		mainTitle->setPosition(Vec2(carHealthReport->visibleSize.width - 20, carHealthReport->visibleSize.height - mainTitle->getContentSize().height - 50));
		mainTitle->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
		mainTitle->setColor(Color3B(50, 50, 50));
		carHealthReport->addChild(mainTitle);

		auto back = Button::create("back.png", "back.png");
		back->setPosition(Vec2(back->getContentSize().width / 2 + 10, carHealthReport->visibleSize.height - back->getContentSize().height / 2 - 10));
		back->setOpacity(150);
		back->setTag(BACK_BUTTON);
		back->setCascadeColorEnabled(true);
		back->setColor(Color3B::GRAY);
		carHealthReport->addChild(back, 40);
		back->addTouchEventListener(CC_CALLBACK_2(CarHealthReport::eventLayout, carHealthReport));

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

		for (int i = 0; i < arrTitlesCarHealth.size(); i++)
		{
			lstLayoutOfCarHealthReport layouts;

			auto layout = Layout::create();
			layout->setBackGroundColorType(Layout::BackGroundColorType::GRADIENT);
			layout->setBackGroundColor(Color3B(101, 186, 106), Color3B(255, 255, 255));
			layout->setContentSize(Size(160, 50));
			layout->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
			layout->setTouchEnabled(true);
			layout->setPosition(Vec2((layout->getContentSize().width - 80 + (i * 160)), mainTitle->getPositionY() - mainTitle->getContentSize().height - 20));
			layout->addTouchEventListener(CC_CALLBACK_2(CarHealthReport::eventLayout, carHealthReport));
			layout->setTag(1007 + i);
			carHealthReport->addChild(layout);

			auto titles = LabelTTF::create(arrTitlesCarHealth.at(i).at(0), MAINFONT, 17);
			titles->setPosition(Vec2(layout->getContentSize().width / 2, layout->getContentSize().height - titles->getContentSize().height / 2 - 5));
			titles->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
			titles->setColor(Color3B(50, 50, 50));
			layout->addChild(titles);

			temp = arrTitlesCarHealth.at(i);

			auto tempLayout = Layout::create();
			tempLayout->setPosition(Vec2(10, 100));
			tempLayout->setContentSize(Size(450, 300));
			layout->addChild(tempLayout);

			for (int j = 1; j < temp.size(); j++)
			{
				auto titles = LabelTTF::create(temp.at(j), MAINFONT, 20);
				titles->setPosition(Vec2(tempLayout->getContentSize().width - 10, tempLayout->getContentSize().height - 50 - (50 * (j - 1))));
				titles->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
				titles->setColor(Color3B(50, 50, 50));
				titles->setOpacity(0);
				tempLayout->addChild(titles);

				auto backField = ImageView::create("backField.png");
				backField->setContentSize(Size(220, 25));
				backField->setScale9Enabled(true);
				backField->setPosition(Vec2(120, tempLayout->getContentSize().height - 50 - (50 * (j - 1))));
				backField->setOpacity(0);
				tempLayout->addChild(backField);

				auto values = LabelTTF::create();
				values->setPosition(Vec2(backField->getPositionX(), backField->getPositionY()));
				values->setColor(Color3B(50, 50, 50));
				values->setFontName(MAINFONT);
				values->setFontSize(20);
				values->setOpacity(0);
				tempLayout->addChild(values);

				switch (i)
				{
				case 0:
				{
					switch (j)
					{
					case 1: values->setString(StringUtils::format("%i", initListOfCarHealth.theUnitEngine.EcuName));
						break;
					case 2: values->setString(StringUtils::format("%i", initListOfCarHealth.theUnitEngine.p001));
						break;
					case 3: values->setString(StringUtils::format("%i", initListOfCarHealth.theUnitEngine.u034));
						break;
					}
				}
				break;
				case 1:
				{
					switch (j)
					{
					case 1: values->setString(StringUtils::format("%i", initListOfCarHealth.theUnitEngine.EcuName));
						break;
					case 2: values->setString(StringUtils::format("%i", initListOfCarHealth.theUnitEngine.p001));
						break;
					case 3: values->setString(StringUtils::format("%i", initListOfCarHealth.theUnitEngine.u034));
						break;
					}
				}
				break;
				case 2:
				{
					switch (j)
					{
					case 1: values->setString(StringUtils::format("%i", initListOfCarHealth.theUnitEngine.EcuName));
						break;
					case 2: values->setString(StringUtils::format("%i", initListOfCarHealth.theUnitEngine.p001));
						break;
					case 3: values->setString(StringUtils::format("%i", initListOfCarHealth.theUnitEngine.u034));
						break;
					}
				}
				break;
				}

			}
			padding += (30 * 8 - 50);

			layouts.layout = layout;
			layouts.tempLayout = tempLayout;
			layouts.isActive = false;
			layouts.title = titles;
			layouts.mainPositionTitle = titles->getPosition();

			carHealthReport->listLayout.push_back(layouts);
		}

        auto pKeybackListener = EventListenerKeyboard::create();
        pKeybackListener->onKeyReleased = CC_CALLBACK_2(CarHealthReport::onKeyReleased, carHealthReport);
        carHealthReport->_eventDispatcher->addEventListenerWithSceneGraphPriority(pKeybackListener, carHealthReport);

        return carHealthReport;
    }

    CC_SAFE_DELETE(carHealthReport);
    return nullptr;
}

void CarHealthReport::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent) {
    if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
    {
        auto scene = MainMenuScene::createScene();
        Director::getInstance()->replaceScene(TransitionMoveInL::create(0.3, scene));
    }
}

void CarHealthReport::eventLayout(Ref *pSender, Widget::TouchEventType type)
{
	Layout* sender = (Layout*)pSender;

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
		break;
		case THIRDPARTY_TAG:
		{
			if (listLayout.at(0).isActive == false)
			{
				_eventDispatcher->setEnabled(false);

				sender->runAction(Sequence::create(
					MoveTo::create(0.1, Vec2(sender->getPositionX(), sender->getPositionY() + 5)),
					MoveTo::create(0.1, Vec2(sender->getPositionX(), sender->getPositionY() - 5)),
					MoveTo::create(0.1, Vec2(sender->getPositionX(), sender->getPositionY() + 5)),
					MoveTo::create(0.1, Vec2(sender->getPositionX(), sender->getPositionY() - 5)),
					MoveTo::create(0.1, Vec2(sender->getPositionX(), sender->getPositionY() + 5)),
					MoveTo::create(0.1, Vec2(sender->getPositionX(), sender->getPositionY() - 50)),
					Spawn::create(
						MoveTo::create(0.5, Vec2(visibleSize.width / 2, sender->getPositionY() - 50)),
						ResizeTo::create(0.5, Size(480, 500)),
						nullptr),
					CallFunc::create([&, this]() {
					listLayout.at(0).isActive = true;
					_eventDispatcher->setEnabled(true);
					setOpacityTempLayout(listLayout.at(0), true);
				}),
					nullptr));

				listLayout.at(0).title->runAction(Sequence::create(
					DelayTime::create(0.6),
					MoveTo::create(0.5, Vec2(listLayout.at(0).mainPositionTitle.x + 160, listLayout.at(0).mainPositionTitle.y + 450)),
					nullptr));
			}
			else
			{
				_eventDispatcher->setEnabled(false);

				setOpacityTempLayout(listLayout.at(0), false);

				sender->runAction(Sequence::create(
					Spawn::create(
						MoveTo::create(0.5, Vec2(visibleSize.width / 2, sender->getPositionY())),
						ResizeTo::create(0.5, Size(160, 50)),
						nullptr),
					MoveTo::create(0.1, Vec2(sender->getPositionX() - 160, sender->getPositionY())),
					MoveTo::create(0.1, Vec2(sender->getPositionX() - 160, sender->getPositionY() + 50)),
					CallFunc::create([&, this]() {
					listLayout.at(0).isActive = false;
					_eventDispatcher->setEnabled(true);
				}),
					nullptr));

				listLayout.at(0).title->runAction(Sequence::create(
					MoveTo::create(0.5, Vec2(listLayout.at(0).mainPositionTitle.x, listLayout.at(0).mainPositionTitle.y)),
					nullptr));
			}


			if (listLayout.at(1).isActive)
			{
				setOpacityTempLayout(listLayout.at(1), false);

				listLayout.at(1).layout->runAction(Sequence::create(
					Spawn::create(
						MoveTo::create(0.5, Vec2(visibleSize.width / 2, listLayout.at(1).layout->getPositionY())),
						ResizeTo::create(0.5, Size(160, 50)),
						nullptr),
					MoveTo::create(0.1, Vec2(listLayout.at(1).layout->getPositionX(), listLayout.at(1).layout->getPositionY() + 50)),
					CallFunc::create([&, this]() {
					listLayout.at(1).isActive = false;
				}),
					nullptr));

				listLayout.at(1).title->runAction(Sequence::create(
					MoveTo::create(0.5, Vec2(listLayout.at(1).mainPositionTitle.x, listLayout.at(1).mainPositionTitle.y)),
					nullptr));
			}

			if (listLayout.at(2).isActive)
			{
				setOpacityTempLayout(listLayout.at(2), false);

				listLayout.at(2).layout->runAction(Sequence::create(
					Spawn::create(
						MoveTo::create(0.5, Vec2(visibleSize.width / 2, listLayout.at(2).layout->getPositionY())),
						ResizeTo::create(0.5, Size(160, 50)),
						nullptr),
					MoveTo::create(0.1, Vec2(listLayout.at(2).layout->getPositionX() + 160, listLayout.at(2).layout->getPositionY())),
					MoveTo::create(0.1, Vec2(listLayout.at(2).layout->getPositionX() + 160, listLayout.at(2).layout->getPositionY() + 50)),
					CallFunc::create([&, this]() {
					listLayout.at(2).isActive = false;
				}),
					nullptr));

				listLayout.at(2).title->runAction(Sequence::create(
					MoveTo::create(0.5, Vec2(listLayout.at(2).mainPositionTitle.x, listLayout.at(2).mainPositionTitle.y)),
					nullptr));
			}


		}
		break;
		case CARBODY_TAG:
		{
			if (listLayout.at(1).isActive == false)
			{
				_eventDispatcher->setEnabled(false);

				sender->runAction(Sequence::create(
					MoveTo::create(0.1, Vec2(sender->getPositionX(), sender->getPositionY() + 5)),
					MoveTo::create(0.1, Vec2(sender->getPositionX(), sender->getPositionY() - 5)),
					MoveTo::create(0.1, Vec2(sender->getPositionX(), sender->getPositionY() + 5)),
					MoveTo::create(0.1, Vec2(sender->getPositionX(), sender->getPositionY() - 5)),
					MoveTo::create(0.1, Vec2(sender->getPositionX(), sender->getPositionY() + 5)),
					MoveTo::create(0.1, Vec2(sender->getPositionX(), sender->getPositionY() - 50)),
					Spawn::create(
						MoveTo::create(0.5, Vec2(visibleSize.width / 2, sender->getPositionY() - 50)),
						ResizeTo::create(0.5, Size(480, 500)),
						nullptr),
					CallFunc::create([&, this]() {
					listLayout.at(1).isActive = true;
					_eventDispatcher->setEnabled(true);
					setOpacityTempLayout(listLayout.at(1), true);
				}),
					nullptr));

				listLayout.at(1).title->runAction(Sequence::create(
					DelayTime::create(0.6),
					MoveTo::create(0.5, Vec2(listLayout.at(1).mainPositionTitle.x + 160, listLayout.at(1).mainPositionTitle.y + 450)),
					nullptr));
			}
			else
			{
				_eventDispatcher->setEnabled(false);

				setOpacityTempLayout(listLayout.at(1), false);

				sender->runAction(Sequence::create(
					Spawn::create(
						MoveTo::create(0.5, Vec2(visibleSize.width / 2, sender->getPositionY())),
						ResizeTo::create(0.5, Size(160, 50)),
						nullptr),
					MoveTo::create(0.1, Vec2(sender->getPositionX(), sender->getPositionY())),
					MoveTo::create(0.1, Vec2(sender->getPositionX(), sender->getPositionY() + 50)),
					CallFunc::create([&, this]() {
					listLayout.at(1).isActive = false;
					_eventDispatcher->setEnabled(true);
				}),
					nullptr));

				listLayout.at(1).title->runAction(Sequence::create(
					MoveTo::create(0.5, Vec2(listLayout.at(1).mainPositionTitle.x, listLayout.at(1).mainPositionTitle.y)),
					nullptr));
			}

			if (listLayout.at(0).isActive)
			{
				setOpacityTempLayout(listLayout.at(0), false);

				listLayout.at(0).layout->runAction(Sequence::create(
					Spawn::create(
						MoveTo::create(0.5, Vec2(visibleSize.width / 2, listLayout.at(0).layout->getPositionY())),
						ResizeTo::create(0.5, Size(160, 50)),
						nullptr),
					MoveTo::create(0.1, Vec2(listLayout.at(0).layout->getPositionX() - 160, listLayout.at(0).layout->getPositionY())),
					MoveTo::create(0.1, Vec2(listLayout.at(0).layout->getPositionX() - 160, listLayout.at(0).layout->getPositionY() + 50)),
					CallFunc::create([&, this]() {
					listLayout.at(0).isActive = false;
				}),
					nullptr));

				listLayout.at(0).title->runAction(Sequence::create(
					MoveTo::create(0.5, Vec2(listLayout.at(0).mainPositionTitle.x, listLayout.at(0).mainPositionTitle.y)),
					nullptr));
			}

			if (listLayout.at(2).isActive)
			{
				setOpacityTempLayout(listLayout.at(2), false);

				listLayout.at(2).layout->runAction(Sequence::create(
					Spawn::create(
						MoveTo::create(0.5, Vec2(visibleSize.width / 2, listLayout.at(2).layout->getPositionY())),
						ResizeTo::create(0.5, Size(160, 50)),
						nullptr),
					MoveTo::create(0.1, Vec2(listLayout.at(2).layout->getPositionX() + 160, listLayout.at(2).layout->getPositionY())),
					MoveTo::create(0.1, Vec2(listLayout.at(2).layout->getPositionX() + 160, listLayout.at(2).layout->getPositionY() + 50)),
					CallFunc::create([&, this]() {
					listLayout.at(2).isActive = false;
				}),
					nullptr));

				listLayout.at(2).title->runAction(Sequence::create(
					MoveTo::create(0.5, Vec2(listLayout.at(2).mainPositionTitle.x, listLayout.at(2).mainPositionTitle.y)),
					nullptr));
			}
		}
		break;
		case LIFE_HEALTH_TAG:
		{
			if (listLayout.at(2).isActive == false)
			{
				_eventDispatcher->setEnabled(false);

				sender->runAction(Sequence::create(
					MoveTo::create(0.1, Vec2(sender->getPositionX(), sender->getPositionY() + 5)),
					MoveTo::create(0.1, Vec2(sender->getPositionX(), sender->getPositionY() - 5)),
					MoveTo::create(0.1, Vec2(sender->getPositionX(), sender->getPositionY() + 5)),
					MoveTo::create(0.1, Vec2(sender->getPositionX(), sender->getPositionY() - 5)),
					MoveTo::create(0.1, Vec2(sender->getPositionX(), sender->getPositionY() + 5)),
					MoveTo::create(0.1, Vec2(sender->getPositionX(), sender->getPositionY() - 50)),
					Spawn::create(
						MoveTo::create(0.5, Vec2(visibleSize.width / 2, sender->getPositionY() - 50)),
						ResizeTo::create(0.5, Size(480, 500)),
						nullptr),
					CallFunc::create([&, this]() {
					listLayout.at(2).isActive = true;
					_eventDispatcher->setEnabled(true);
					setOpacityTempLayout(listLayout.at(2), true);
				}),
					nullptr));

				listLayout.at(2).title->runAction(Sequence::create(
					DelayTime::create(0.6),
					MoveTo::create(0.5, Vec2(listLayout.at(2).mainPositionTitle.x + 160, listLayout.at(2).mainPositionTitle.y + 450)),
					nullptr));
			}
			else
			{
				_eventDispatcher->setEnabled(false);

				setOpacityTempLayout(listLayout.at(2), false);

				sender->runAction(Sequence::create(
					Spawn::create(
						MoveTo::create(0.5, Vec2(visibleSize.width / 2, sender->getPositionY())),
						ResizeTo::create(0.5, Size(160, 50)),
						nullptr),
					MoveTo::create(0.1, Vec2(sender->getPositionX() + 160, sender->getPositionY())),
					MoveTo::create(0.1, Vec2(sender->getPositionX() + 160, sender->getPositionY() + 50)),
					CallFunc::create([&, this]() {
					listLayout.at(2).isActive = false;
					_eventDispatcher->setEnabled(true);
				}),
					nullptr));

				listLayout.at(2).title->runAction(Sequence::create(
					MoveTo::create(0.5, Vec2(listLayout.at(2).mainPositionTitle.x, listLayout.at(2).mainPositionTitle.y)),
					nullptr));
			}

			if (listLayout.at(0).isActive)
			{
				setOpacityTempLayout(listLayout.at(0), false);

				listLayout.at(0).layout->runAction(Sequence::create(
					Spawn::create(
						MoveTo::create(0.5, Vec2(visibleSize.width / 2, listLayout.at(0).layout->getPositionY())),
						ResizeTo::create(0.5, Size(160, 50)),
						nullptr),
					MoveTo::create(0.1, Vec2(listLayout.at(0).layout->getPositionX() - 160, listLayout.at(0).layout->getPositionY())),
					MoveTo::create(0.1, Vec2(listLayout.at(0).layout->getPositionX() - 160, listLayout.at(0).layout->getPositionY() + 50)),
					CallFunc::create([&, this]() {
					listLayout.at(0).isActive = false;
				}),
					nullptr));

				listLayout.at(0).title->runAction(Sequence::create(
					MoveTo::create(0.5, Vec2(listLayout.at(0).mainPositionTitle.x, listLayout.at(0).mainPositionTitle.y)),
					nullptr));
			}

			if (listLayout.at(1).isActive)
			{
				setOpacityTempLayout(listLayout.at(1), false);

				listLayout.at(1).layout->runAction(Sequence::create(
					Spawn::create(
						MoveTo::create(0.5, Vec2(visibleSize.width / 2, listLayout.at(1).layout->getPositionY())),
						ResizeTo::create(0.5, Size(160, 50)),
						nullptr),
					MoveTo::create(0.1, Vec2(listLayout.at(1).layout->getPositionX(), listLayout.at(1).layout->getPositionY() + 50)),
					CallFunc::create([&, this]() {
					listLayout.at(1).isActive = false;
				}),
					nullptr));

				listLayout.at(1).title->runAction(Sequence::create(
					MoveTo::create(0.5, Vec2(listLayout.at(1).mainPositionTitle.x, listLayout.at(1).mainPositionTitle.y)),
					nullptr));
			}
		}
		break;
		default:
			break;
		}
	}
	break;
	default:
		break;
	}
}

void CarHealthReport::setOpacityTempLayout(lstLayoutOfCarHealthReport listLayout, bool isActive)
{
	if (isActive)
	{
		for (auto tempLayout : listLayout.tempLayout->getChildren())
		{
			tempLayout->runAction(FadeTo::create(0.2, 255));
		}
	}
	else
	{
		for (auto tempLayout : listLayout.tempLayout->getChildren())
		{
			tempLayout->runAction(FadeTo::create(0.05, 0));
		}
	}
}