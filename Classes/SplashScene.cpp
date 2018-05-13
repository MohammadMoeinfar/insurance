//
// Created by Mohammad Moienfar on 5/13/2018.
//

#include "SplashScene.h"

SplashScene::SplashScene() {

}

SplashScene::~SplashScene() {

}

Scene *SplashScene::createScene() {

    Scene* scene = Scene::create();

    SplashScene* layer = SplashScene::initSplashScene();

    scene->addChild(layer);

    return scene;
}

SplashScene *SplashScene::initSplashScene() {

    SplashScene* splashScene = new SplashScene();

    if(splashScene && splashScene->init())
    {
        auto visibleSize = Director::getInstance()->getVisibleSize();
        auto origin = Director::getInstance()->getVisibleOrigin();

        auto layerColor = LayerColor::create(Color4B(21, 101, 174, 255));
        splashScene->addChild(layerColor);

        auto logo = Sprite::create("logo.png");
        logo->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        splashScene->addChild(logo);

        splashScene->runAction(Sequence::create(
                DelayTime::create(3.0),
                CallFunc::create([&, splashScene](){
                    auto scene = Login::createScene();
                    Director::getInstance()->replaceScene(TransitionFade::create(3.0, scene));
                }),
                nullptr));

        return splashScene;
    }

    CC_SAFE_DELETE(splashScene);
    return nullptr;
}
