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

        login->textFieldUsername = TextField::create("User Name",MAINFONT,25);
        login->textFieldUsername->ignoreContentAdaptWithSize(false);
        ((Label*)(login->textFieldUsername->getVirtualRenderer()))->setLineBreakWithoutSpace(true);
        login->textFieldUsername->setContentSize(Size(267, 40));
        login->textFieldUsername->setPlaceHolder("Username");
        login->textFieldUsername->setString("admin");
        login->textFieldUsername->setTextColor(Color4B::BLACK);
        login->textFieldUsername->setTextHorizontalAlignment(TextHAlignment::CENTER);
        login->textFieldUsername->setTextVerticalAlignment(TextVAlignment::CENTER);
        login->textFieldUsername->setPosition(backusername->getPosition());
        login->textFieldUsername->addEventListener(CC_CALLBACK_2(Login::textFieldEvent, login));
        login->addChild(login->textFieldUsername);

        auto backpassword = Sprite::create("backpassword.png");
        backpassword->setPosition(Vec2(backusername->getPositionX(), backusername->getPositionY() - backusername->getContentSize().height));
        login->addChild(backpassword);

        login->textFieldPassword = TextField::create("Password",MAINFONT,35);
        login->textFieldPassword->ignoreContentAdaptWithSize(false);
        ((Label*)(login->textFieldPassword->getVirtualRenderer()))->setLineBreakWithoutSpace(true);
        login->textFieldPassword->setContentSize(Size(267, 40));
        login->textFieldPassword->setPlaceHolder("*******");
        login->textFieldPassword->setString("admin");
        login->textFieldPassword->setTextColor(Color4B::BLACK);
        login->textFieldPassword->setPasswordEnabled(true);
        login->textFieldPassword->setPasswordStyleText("*");
        login->textFieldPassword->setTextHorizontalAlignment(TextHAlignment::CENTER);
        login->textFieldPassword->setTextVerticalAlignment(TextVAlignment::CENTER);
        login->textFieldPassword->setPosition(backpassword->getPosition());
        login->textFieldPassword->addEventListener(CC_CALLBACK_2(Login::textFieldEvent, login));
        login->addChild(login->textFieldPassword);

        auto loginButton = Button::create("loginButton.png", "loginButton.png");
        loginButton->setPosition(Vec2(backpassword->getPositionX(), backpassword->getPositionY() - 85));
        loginButton->setPressedActionEnabled(true);
        loginButton->addTouchEventListener(CC_CALLBACK_2(Login::buttonEvent, login));
        login->addChild(loginButton);

        auto titleLoginButton = LabelTTF::create(TITLELOGINBUTTON, MAINFONT, 25);
        titleLoginButton->setPosition(Vec2(backpassword->getPositionX(), backpassword->getPositionY() - 85));
        login->addChild(titleLoginButton);

        auto pKeybackListener = EventListenerKeyboard::create();
        pKeybackListener->onKeyReleased = CC_CALLBACK_2(Login::onKeyReleased, login);
        login->_eventDispatcher->addEventListenerWithSceneGraphPriority(pKeybackListener, login);

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
            if((textFieldUsername->getString() == "admin") && (textFieldPassword->getString() == "admin"))
            {
                auto scene = MainMenuScene::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(1.0, scene));
            }
            else{
                std::string jFunction = "";
                jFunction = "showToast";
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )

                cocos2d::JniMethodInfo t;
                string message = WRONG_USERNAME_PASSWORD;

                if (cocos2d::JniHelper::getStaticMethodInfo(t, "org/cocos2dx/cpp/AppActivity", jFunction.c_str(), "(Ljava/lang/String;)V"))
                {
                    jstring tStringArg1 = t.env->NewStringUTF(message.c_str());

                    t.env->CallStaticVoidMethod(t.classID, t.methodID, tStringArg1);
                    t.env->DeleteLocalRef(t.classID);
                }

#endif
            }
        }
            break;
    }
}

void Login::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *pEvent) {
    if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
    {
        Director::getInstance()->end();
    }
}
