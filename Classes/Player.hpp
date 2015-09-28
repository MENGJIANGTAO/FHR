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
USING_NS_CC;


class Player : Sprite
{
public:
    Player();
    ~Player();
    static Player* getPlayer();
    Animation *getWalk();
    
    void moveTo(Vec2 position);
private:
    int m_hp;
    int m_mp;
    int m_moveSpeed;
    int m_moveTime;
    
    static Player *m_player;
    Animation* m_walk;
    Animation* m_attact;
    Animation* m_dead;
};

#endif /* Life_hpp */
