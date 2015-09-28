//
//  VisibleRect.cpp
//  FHR
//
//  Created by Mengjiangtao on 9/25/15.
//
//

#include "VisibleRect.hpp"

USING_NS_CC;

Rect VisibleRect::s_visibleRect;

void VisibleRect::Init()
{
    s_visibleRect = Director::getInstance()->getOpenGLView()->getVisibleRect();
}

Rect VisibleRect::GetVisibleRect()
{
    Init();
    return s_visibleRect;
}

Vec2 VisibleRect::Left()
{
    Init();
    return  Vec2(s_visibleRect.origin.x,s_visibleRect.origin.y + s_visibleRect.size.height/2);
}

Vec2 VisibleRect::Right()
{
    Init();
    return Vec2(s_visibleRect.origin.x + s_visibleRect.size.width,s_visibleRect.origin.y + s_visibleRect.size.height/2);
}

Vec2 VisibleRect::Top()
{
    Init();
    return Vec2(s_visibleRect.origin.x + s_visibleRect.size.width/2,s_visibleRect.origin.y + s_visibleRect.size.height);
}

Vec2 VisibleRect::Bottom()
{
    Init();
    return Vec2(s_visibleRect.origin.x + s_visibleRect.size.width/2,s_visibleRect.origin.y);
}

Vec2 VisibleRect::Center()
{
    Init();
    return Vec2(s_visibleRect.origin.x + s_visibleRect.size.width/2,s_visibleRect.origin.y + s_visibleRect.size.height/2);
}

Vec2 VisibleRect::LeftTop()
{
    Init();
    return Vec2(s_visibleRect.origin.x,s_visibleRect.origin.y + s_visibleRect.size.height);
}

Vec2 VisibleRect::LeftBottom()
{
    Init();
    return s_visibleRect.origin;
//    return Vec2(s_visibleRect.origin.x,s_visibleRect.origin.y);
}

Vec2 VisibleRect::RightTop()
{
    Init();
    return Vec2(s_visibleRect.origin.x + s_visibleRect.size.width,s_visibleRect.origin.y + s_visibleRect.size.height);
}


Vec2 VisibleRect::RightBottom()
{
    Init();
    return Vec2(s_visibleRect.origin.x + s_visibleRect.size.width,s_visibleRect.origin.y);
}