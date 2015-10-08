//
//  Plaeyr.cpp
//  FHR
//
//  Created by Mengjiangtao on 9/24/15.
//
//

#include "Player.hpp"

Player* Player::m_player;

Player::Player()
{
    SetPsprite();
    m_hp = 100;
    m_mp = 100;
    m_moveSpeed = 10;
    tip = BloodTip::create();
    tip->setProgress(100);
    this->addChild(tip);
    scheduleUpdate();
}

Player::~Player()
{
    unscheduleUpdate();
}

Player* Player::getPlayer()
{
    if(!m_player)
    {
        m_player = new Player();
    }
    
    return m_player;
}

Animation* Player::getWalk()
{
//    if(m_walk==nullptr)
    {
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("role.plist", "role.pvr.ccz");
        Vector<SpriteFrame*> vectors;
        char *frameName = new char[20];
        for(int i = 1;i<5;i++)
        {
            sprintf(frameName,"player1-1-%d.png",i);
            SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName);
            vectors.pushBack(frame);
        }
        m_walk = Animation::createWithSpriteFrames(vectors,0.3f);
        m_walk->setLoops(-1);
    }
    return m_walk;
}

void Player::SetPsprite()
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("role.plist", "role.pvr.ccz");
    this->initWithSpriteFrameName("player1-1-1.png");
}

void Player::moveTo(cocos2d::Vec2 position)
{
    m_player->stopAllActions();
    MoveTo* move = MoveTo::create(m_moveTime, position);
    auto actF = Sequence::create(Animate::create(getWalk()), nullptr);
    FiniteTimeAction *start = Spawn::create(move,actF, NULL);
    m_player->runAction(start);
}

void Player::actionOver()
{
    m_player->stopAllActions();
}

void Player::update(float dt)
{
    tip->setPositionX(m_player->getPositionX());
    tip->setPositionY(m_player->getPositionY());

}