//
//  BloodTip.cpp
//  FHR
//
//  Created by Mengjiangtao on 9/30/15.
//
//

#include "BloodTip.hpp"

bool BloodTip::init(const char *background, const char *filename)
{
    this->initWithSpriteFrameName(background);
    ProgressTimer* fill = ProgressTimer::create(Sprite::create(filename));
    this->setFill(fill);
    addChild(_fill);
    
    _fill->setType(ProgressTimer::Type::BAR);
    _fill->setMidpoint(Point(0.5,0.5));
    _fill->setBarChangeRate(Point(1.0,0));
    _fill->setPosition(this->getContentSize()/2);
    _fill->setPercentage(100);
    return true;
}

BloodTip* BloodTip::create()
{
    BloodTip* tip = new BloodTip();
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ui.plist", "ui.pvr.ccz");
    char* framename1 = new char[100];
    sprintf(framename1, "small-enemy-progress-bg.png");
    char* framename2 = new char[100];
    sprintf(framename2, "small-enemy-progress-fill.png");
    if(tip && tip->init(framename1, framename2))
    {
        tip->autorelease();
        return tip;
    }
    else
    {
        delete tip;
        tip = nullptr;
        return nullptr;
    }
    delete [] framename1;
    delete [] framename2;
}


