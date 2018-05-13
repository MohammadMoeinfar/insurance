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

        auto logo = Sprite::create("logo.png");
        logo->setPosition(Vec2(mainMenuScene->visibleSize.width / 2 + mainMenuScene->origin.x, mainMenuScene->visibleSize.height - logo->getContentSize().height - 15 + mainMenuScene->origin.y));
        mainMenuScene->addChild(logo);

        auto title = LabelTTF::create("Car Insurance", MAINFONT, 25);
        title->setPosition(Vec2(logo->getPositionX(), logo->getPositionY() - logo->getContentSize().height / 2 - 15));
        mainMenuScene->addChild(title);

        mainMenuScene->readData();

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

        default:
            break;
    }
}

void MainMenuScene::buttonEvent(Ref *pSender, Widget::TouchEventType type)
{
    Button* sender = (Button*) pSender;

    switch (type)
    {
        case Widget::TouchEventType::ENDED:
        {
            // comment
        }
            break;
    }
}

void MainMenuScene::readData() {

    long filesize = 0;
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

    int x=0;

}

