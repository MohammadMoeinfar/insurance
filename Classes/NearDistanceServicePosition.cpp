//
// Created by Mohammad Moeinfar on 5/16/2018.
//

#include "NearDistanceServicePosition.h"

NearDistanceServicePosition::NearDistanceServicePosition() {

}

NearDistanceServicePosition::~NearDistanceServicePosition() {

}

Scene *NearDistanceServicePosition::createScene() {
    Scene* scene = Scene::create();

    NearDistanceServicePosition* layer = NearDistanceServicePosition::initNearDistanceServicePosition();

    scene->addChild(layer);

    return scene;
}

NearDistanceServicePosition *NearDistanceServicePosition::initNearDistanceServicePosition() {
    NearDistanceServicePosition* nearDistanceServicePosition = new NearDistanceServicePosition();

    if(nearDistanceServicePosition && nearDistanceServicePosition->init())
    {
        nearDistanceServicePosition->visibleSize = Director::getInstance()->getVisibleSize();
        nearDistanceServicePosition->origin = Director::getInstance()->getVisibleOrigin();

        auto layerColor = LayerColor::create(Color4B(245, 247, 249, 255));
        nearDistanceServicePosition->addChild(layerColor);

        auto showMap = Button::create("button.png", "button.png");
        showMap->setPosition(Vec2(nearDistanceServicePosition->visibleSize.width / 2 + nearDistanceServicePosition->origin.x, nearDistanceServicePosition->visibleSize.height / 2 + nearDistanceServicePosition->origin.y));
        showMap->setTitleText("SHOW MAP");
        showMap->setTitleFontSize(10);
        showMap->addTouchEventListener(CC_CALLBACK_2(NearDistanceServicePosition::mapEvent, nearDistanceServicePosition));
        nearDistanceServicePosition->addChild(showMap);

        nearDistanceServicePosition->points.push_back(36.23712506649852);
        nearDistanceServicePosition->points.push_back(46.266285292804234);
        nearDistanceServicePosition->points.push_back(36.237609668685714);
        nearDistanceServicePosition->points.push_back(46.27323791384697);

        auto pKeybackListener = EventListenerKeyboard::create();
        pKeybackListener->onKeyReleased = CC_CALLBACK_2(NearDistanceServicePosition::onKeyReleased, nearDistanceServicePosition);
        nearDistanceServicePosition->_eventDispatcher->addEventListenerWithSceneGraphPriority(pKeybackListener, nearDistanceServicePosition);

        return nearDistanceServicePosition;
    }

    CC_SAFE_DELETE(nearDistanceServicePosition);
    return nullptr;
}

void NearDistanceServicePosition::mapEvent(Ref *pSender, Widget::TouchEventType type) {
    Button* sender = (Button*) pSender;

    switch (type){
        case Widget::TouchEventType::ENDED:
        {
            std::string jFunction = "";
            jFunction = "showCalculateDistance";
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

void NearDistanceServicePosition::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent) {
    if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
    {
        auto scene = MainMenuScene::createScene();
        Director::getInstance()->replaceScene(TransitionMoveInL::create(0.3, scene));
    }
}