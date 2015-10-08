//
//  GameScene.cpp
//  FHR
//
//  Created by Mengjiangtao on 9/28/15.
//
//

#include "GameScene.hpp"
#include "VisibleRect.hpp"
#include "math.h"

Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}


bool GameScene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    m_background = Sprite::create("image/background.png");
    m_background->setPosition(VisibleRect::Center());
    addChild(m_background);
    
    m_p1 = Player::getPlayer();
    m_p1->body->setPosition(Vec2(300,200));
    addChild(m_p1->body);
    addChild(m_p1);
    scheduleUpdate();
    return true;
}

void GameScene::onEnter()
{
    Layer::onEnter();
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void GameScene::onExit()
{
    Layer::onExit();
}

bool GameScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    CCLOG("Paddle::onTouchBegan id = %d, x = %f, y = %f", touch->getID(), touch->getLocation().x, touch->getLocation().y);
    
    targetX = touch->getLocation().x;
    targetY = touch->getLocation().y;
    int bodyX = m_p1->body->getPositionX();
    int bodyY = m_p1->body->getPositionY();
    int way = sqrt((abs((targetX - bodyX)*(targetX-bodyX))) + (abs((targetY - bodyY)*(targetY-bodyY))));
    
    m_p1->m_moveTime = way/m_p1->m_moveSpeed;
    m_p1->moveTo(Vec2(targetX,targetY));
    return true;
}

void GameScene::update(float dt)
{
    // stop player action when it's over or so.
    if(m_p1->body->getPositionX() == targetX && m_p1->body->getPositionY() == targetY)
    {
        m_p1->actionOver();
        targetY--;
    }
}