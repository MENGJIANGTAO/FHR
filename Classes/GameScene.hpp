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
USING_NS_CC;

class GameScene : public Layer
{
public:
    bool init();
    static cocos2d::Scene* createScene();
    CREATE_FUNC(GameScene);
};

#endif /* GameScene_hpp */
