#include "ThreatsObj.h"

ThreatsObj::ThreatsObj()
{
    rect_.x=SCREEN_WIDTH;
    rect_.y=SCREEN_HEIGHT*0.5;
    rect_.w=WIDTH_THREAT;
    rect_.h=HEIGHT_THREAT;

    x_val=5;
    y_val=0;
}
ThreatsObj::~ThreatsObj()
{
}
void ThreatsObj::handlemove(const int& x_bordr, const int& y_bordr)
{
    //x_val=rand()%(2*5+1)-5;
    //y_val=rand()%(2*5+1)-5;
    rect_.x=rect_.x-x_val;
    rect_.y=rect_.y+y_val;

    if(rect_.x<0 ||rect_.y > SCREEN_HEIGHT || rect_.y < 0||rect_.x > SCREEN_WIDTH)
    {
       rect_.x=rand()%1200;
       rect_.y=0;
    }
}


void ThreatsObj::handleIpAc(SDL_Event events)
{

}
