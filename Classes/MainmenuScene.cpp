//
//  MainmenuScene.cpp
//  FHR
//
//  Created by Mengjiangtao on 9/25/15.
//
//

#include "MainmenuScene.hpp"
#include "VisibleRect.hpp"
#include "GameScene.hpp"
USING_NS_CC;

Scene* MainmenuScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainmenuScene::create();
    scene->addChild(layer);
    return scene;
}

bool MainmenuScene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("image/role.plist", "image/role.pvr.ccz");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("image/ui.plist", "image/ui.pvr.ccz");
    auto background = Sprite::create("image/start-bg.jpg");
    background->setPosition(VisibleRect::Center());
    this->addChild(background);
    
    auto normal = SpriteFrameCache::getInstance()->getSpriteFrameByName("start1.png");
    auto select = SpriteFrameCache::getInstance()->getSpriteFrameByName("start2.png");
    auto item = MenuItemImage::create();
    item->setNormalSpriteFrame(normal);
    item->setSelectedSpriteFrame(select);
    item->setCallback(CC_CALLBACK_1(MainmenuScene::onStart, this));
    auto menu = Menu::createWithItem(item);
    this->addChild(menu);

    return true;
}


void MainmenuScene::onStart(cocos2d::Ref *obj)
{
    Director::getInstance()->replaceScene(GameScene::createScene());
}