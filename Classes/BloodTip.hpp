//
//  BloodTip.hpp
//  FHR
//
//  Created by Mengjiangtao on 9/30/15.
//
//

#ifndef BloodTip_hpp
#define BloodTip_hpp

#include "cocos2d.h"
USING_NS_CC;

class BloodTip : public Sprite
{
public:
    bool init(const char* background,const char*filename);
    static BloodTip* create();
    void setFill(ProgressTimer* fill){_fill = fill;}
    void setProgress(float percentage){_fill->setPercentage(percentage);}
private:
    ProgressTimer* _fill;
};

#endif /* BloodTip_hpp */
