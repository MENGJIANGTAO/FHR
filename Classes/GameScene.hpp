//
//  GameScene.hpp
//  FHR
//
//  Created by Mengjiangtao on 9/28/15.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include <cocos2d.h>
#include "Player.hpp"
USING_NS_CC;

class GameScene : public Layer
{
public:
    bool init();
    static cocos2d::Scene* createScene();
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    virtual void onEnter() override;
    virtual void onExit() override;
    CREATE_FUNC(GameScene);
private:
    Sprite *m_background;
    Player *m_p1;
};

#endif /* GameScene_hpp */
