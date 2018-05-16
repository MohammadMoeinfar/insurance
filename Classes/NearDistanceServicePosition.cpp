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
            jFunction = "showStr";
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )

            cocos2d::JniMethodInfo t;
            if (cocos2d::JniHelper::getStaticMethodInfo(t, "org/cocos2dx/cpp/AppActivity", jFunction.c_str(), "([D)V"))
            {
                double lat [] = {23.32, 43.21};
                double lot [] = {12.32, 36.21};

                jdoubleArray jdoubleArray1 = t.env->NewDoubleArray(2);
                t.env->SetDoubleArrayRegion(jdoubleArray1, 0, 2, &lat[0]);

                t.env->CallStaticVoidMethod(t.classID, t.methodID, jdoubleArray1);
                t.env->DeleteLocalRef(t.classID);
            }

#endif
        }
            break;
    }
}