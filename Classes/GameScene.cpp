//
//  GameScene.cpp
//  FHR
//
//  Created by Mengjiangtao on 9/28/15.
//
//

#include "GameScene.hpp"

Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}


bool GameScene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    return true;
}