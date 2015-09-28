//
//  VisibleRect.hpp
//  FHR
//
//  Created by Mengjiangtao on 9/25/15.
//
//

#ifndef VisibleRect_hpp
#define VisibleRect_hpp

#include "cocos2d.h"

class VisibleRect
{
public:
    static cocos2d::Rect GetVisibleRect();
    
    static cocos2d::Vec2 Left();
    static cocos2d::Vec2 Right();
    static cocos2d::Vec2 Top();
    static cocos2d::Vec2 Bottom();
    static cocos2d::Vec2 Center();
    static cocos2d::Vec2 LeftTop();
    static cocos2d::Vec2 RightTop();
    static cocos2d::Vec2 LeftBottom();
    static cocos2d::Vec2 RightBottom();
private:
    static void Init();
    static cocos2d::Rect s_visibleRect;
};

#endif /* VisibleRect_hpp */
