//
// Created by Mohammad Moeinfar on 5/13/2018.
//

#include "Login.h"

Login::Login() {

}

Login::~Login() {

}

Scene *Login::createScene() {
    Scene* scene = Scene::create();

    Login* layer = Login::initLogin();

    scene->addChild(layer);

    return scene;
}

Login *Login::initLogin() {
    Login* login = new Login();

    if(login && login->init())
    {
        login->visibleSize = Director::getInstance()->getVisibleSize();
        login->origin = Director::getInstance()->getVisibleOrigin();

        auto layerColor = LayerColor::create(Color4B(21, 101, 174, 255));
        login->addChild(layerColor);

        auto logo = Sprite::create("logo.png");
        logo->setPosition(Vec2(login->visibleSize.width / 2 + login->origin.x, login->visibleSize.height - logo->getContentSize().height - 15 + login->origin.y));
        login->addChild(logo);

        auto title = LabelTTF::create("Car Insurance", MAINFONT, 20);
        title->setPosition(Vec2(logo->getPositionX(), logo->getPositionY() - logo->getContentSize().height / 2 - 10));
        login->addChild(title);

        auto backusername = Sprite::create("backusername.png");
        backusername->setPosition(Vec2(login->visibleSize.width / 2 + login->origin.x, login->visibleSize.height / 2 + login->origin.y));
        login->addChild(backusername);

        TextField* textFieldUsername = TextField::create("User Name",MAINFONT,20);
        textFieldUsername->ignoreContentAdaptWithSize(false);
        ((Label*)(textFieldUsername->getVirtualRenderer()))->setLineBreakWithoutSpace(true);
        textFieldUsername->setContentSize(Size(267, 40));
        textFieldUsername->setString("User Name");
        textFieldUsername->setTextHorizontalAlignment(TextHAlignment::CENTER);
        textFieldUsername->setTextVerticalAlignment(TextVAlignment::CENTER);
        textFieldUsername->setPosition(backusername->getPosition());
        textFieldUsername->addEventListener(CC_CALLBACK_2(Login::textFieldEvent, login));
        login->addChild(textFieldUsername);

        auto backpassword = Sprite::create("backpassword.png");
        backpassword->setPosition(Vec2(backusername->getPositionX(), backusername->getPositionY() - backusername->getContentSize().height));
        login->addChild(backpassword);

        TextField* textFieldPassword = TextField::create("Password",MAINFONT,20);
        textFieldPassword->ignoreContentAdaptWithSize(false);
        ((Label*)(textFieldPassword->getVirtualRenderer()))->setLineBreakWithoutSpace(true);
        textFieldPassword->setContentSize(Size(267, 40));
        textFieldPassword->setString("Password");
        textFieldPassword->setPasswordEnabled(true);
        textFieldPassword->setPasswordStyleText("*");
        textFieldPassword->setTextHorizontalAlignment(TextHAlignment::CENTER);
        textFieldPassword->setTextVerticalAlignment(TextVAlignment::CENTER);
        textFieldPassword->setPosition(backpassword->getPosition());
        textFieldPassword->addEventListener(CC_CALLBACK_2(Login::textFieldEvent, login));
        login->addChild(textFieldPassword);

        auto loginButton = Button::create("loginButton.png", "loginButton.png");
        loginButton->setPosition(Vec2(backpassword->getPositionX(), backpassword->getPositionY() - 85));
        loginButton->setTitleText("LOG IN");
        loginButton->setTitleFontSize(20);
        loginButton->addTouchEventListener(CC_CALLBACK_2(Login::buttonEvent, login));
        login->addChild(loginButton);

        return login;
    }

    CC_SAFE_DELETE(login);
    return nullptr;
}

void Login::textFieldEvent(Ref *pSender, TextField::EventType type)
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

void Login::buttonEvent(Ref *pSender, Widget::TouchEventType type)
{
    Button* sender = (Button*) pSender;

    switch (type)
    {
        case Widget::TouchEventType::ENDED:
        {
            auto scene = MainMenuScene::createScene();
            Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene));
        }
            break;
    }
}
