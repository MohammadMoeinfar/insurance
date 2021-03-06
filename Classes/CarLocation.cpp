//
// Created by Mohammad Moeinfar on 5/16/2018.
//

#include "CarLocation.h"

CarLocation::CarLocation() {

}

CarLocation::~CarLocation() {

}

Scene *CarLocation::createScene() {
    Scene* scene = Scene::create();

    CarLocation* layer = CarLocation::initCarLocation();

    scene->addChild(layer);

    return scene;
}

CarLocation *CarLocation::initCarLocation() {
    CarLocation* carLocation = new CarLocation();

    if(carLocation && carLocation->init())
    {
        carLocation->visibleSize = Director::getInstance()->getVisibleSize();
        carLocation->origin = Director::getInstance()->getVisibleOrigin();

        auto layerColor = LayerColor::create(Color4B(245, 247, 249, 255));
        carLocation->addChild(layerColor);

        auto showMap = Button::create("btn1.png", "btn.png");
        showMap->setPosition(Vec2(carLocation->visibleSize.width / 2 + carLocation->origin.x, showMap->getContentSize().height + 100 + carLocation->origin.y));
        showMap->setPressedActionEnabled(true);
        showMap->addTouchEventListener(CC_CALLBACK_2(CarLocation::mapEvent, carLocation));
        carLocation->addChild(showMap);

        carLocation->points.push_back(36.23712506649852);
        carLocation->points.push_back(46.266285292804234);

        auto pKeybackListener = EventListenerKeyboard::create();
        pKeybackListener->onKeyReleased = CC_CALLBACK_2(CarLocation::onKeyReleased, carLocation);
        carLocation->_eventDispatcher->addEventListenerWithSceneGraphPriority(pKeybackListener, carLocation);

        return carLocation;
    }

    CC_SAFE_DELETE(carLocation);
    return nullptr;
}

void CarLocation::mapEvent(Ref *pSender, Widget::TouchEventType type) {
    Button* sender = (Button*) pSender;

    switch (type){
        case Widget::TouchEventType::ENDED:
        {
            std::string jFunction = "";
            jFunction = "showMap";
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )

            cocos2d::JniMethodInfo t;
            if (cocos2d::JniHelper::getStaticMethodInfo(t, "org/cocos2dx/cpp/AppActivity", jFunction.c_str(), "([D)V"))
            {
                auto size = points.size();

                double lat [size];

                for (int i = 0; i < points.size(); i++) {
                    lat[i] = points.at(i);
                }

                jdoubleArray jdoubleArray1 = t.env->NewDoubleArray(size);
                t.env->SetDoubleArrayRegion(jdoubleArray1, 0, size, &lat[0]);

                t.env->CallStaticVoidMethod(t.classID, t.methodID, jdoubleArray1);
                t.env->DeleteLocalRef(t.classID);
            }

#endif
        }
            break;
    }
}

void CarLocation::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent) {
    if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
    {
        auto scene = MainMenuScene::createScene();
        Director::getInstance()->replaceScene(TransitionMoveInL::create(0.3, scene));
    }
}