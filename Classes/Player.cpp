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
    m_hp = 100;
    m_mp = 100;
    m_moveSpeed = 10;
}

Player::~Player()
{
    
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
    if(m_walk==nullptr)
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