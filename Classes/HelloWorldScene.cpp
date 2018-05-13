#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto showMap = Button::create("button.png", "button.png");
    showMap->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    showMap->setTitleText("SHOW MAP");
    showMap->setTitleFontSize(10);
    showMap->addTouchEventListener(CC_CALLBACK_2(HelloWorld::mapEvent, this));
    addChild(showMap);

    return true;
}

void HelloWorld::mapEvent(Ref *pSender, Widget::TouchEventType type) {
    Button* sender = (Button*) pSender;

    switch (type){
        case Widget::TouchEventType::ENDED:
        {
            std::string jFunction = "";
            jFunction = "showMap";
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
            cocos2d::JniMethodInfo t;
            if (cocos2d::JniHelper::getStaticMethodInfo(t, "org/cocos2dx/cpp/AppActivity", jFunction.c_str(), "()V"))
            {
                t.env->CallStaticVoidMethod(t.classID, t.methodID);
                t.env->DeleteLocalRef(t.classID);
            }
#endif
        }
            break;
    }
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
