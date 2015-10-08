//
//  Player.hpp
//  FHR
//
//  Created by Mengjiangtao on 9/24/15.
//
//

#ifndef Life_hpp
#define Life_hpp

#include <cocos2d.h>
#include "BloodTip.hpp"

USING_NS_CC;


class Player : public Sprite
{
public:
    Player();
    ~Player();
    static Player* getPlayer();
    Animation* getWalk();
    void SetPsprite();
    void moveTo(Vec2 position);
    void actionOver();
    void update(float dt) override;
    
    Point m_position;
    BloodTip* tip;
    int m_hp;
    int m_mp;
    int m_moveSpeed;
    int m_moveTime;
private:
    static Player *m_player;
    Animation* m_walk;
    Animation* m_attact;
    Animation* m_dead;
};

#endif /* Life_hpp */
