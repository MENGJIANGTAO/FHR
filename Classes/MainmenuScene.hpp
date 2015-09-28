//
//  MainmenuScene.hpp
//  FHR
//
//  Created by Mengjiangtao on 9/25/15.
//
//

#ifndef MainmenuScene_hpp
#define MainmenuScene_hpp

#include <cocos2d.h>

class MainmenuScene : public cocos2d::Layer
{
public:
    bool init();
    static cocos2d::Scene* createScene();
    void onStart(cocos2d::Ref *obj);
    CREATE_FUNC(MainmenuScene);
};
#endif /* MainmenuScene_hpp */