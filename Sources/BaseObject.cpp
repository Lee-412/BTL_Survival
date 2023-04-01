#include "BaseObject.h"
#include "library.h"
#include "Background.h"
#include "init_clean.h"

BaseObject::BaseObject()
{
    rect_.x=0;
    rect_.y=0;
    p_object =NULL;
}
BaseObject::~BaseObject()
{
    if(p_object!=NULL)
    {
        SDL_DestroyTexture(p_object);
    }
}

bool BaseObject::Loadimg(const char* file_path)
{
    p_object = SDLF::loadimage(file_path);
    if (p_object == NULL)
    {
        return false;
    }
    else
    {
        return true; // chuyển return false thành return true
    }
}

void BaseObject::Show(SDL_Texture* des, int x, int y)
{
    if(p_object!=NULL)
    {
        SDLF::renderchar(des,x ,y);
    }
    else std::cout<<"e";
}
void BaseObject::Showthr(SDL_Texture* des, int x_val, int y_val)
{
    if(p_object!=NULL)
    {
        SDLF::renderthr(des,x_val ,y_val);
    }
    else std::cout<<"e";
}
