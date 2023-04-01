#ifndef BASEOBJECT_H_
#define BASEOBJECT_H_

#include"library.h"
#include "Background.h"

class BaseObject
{
public:
    BaseObject();
    ~BaseObject();  // thêm destructor
    void Show(SDL_Texture* des, int x, int y);
    void Showthr(SDL_Texture* des, int x_val, int y_val);
    bool Loadimg(const char* file_path);  // sửa lại khai báo hàm Loadimg thành public
    SDL_Texture* GetP_object()
    {
        return p_object;
    }
    void SetRect(int x, int y)
    {
        rect_.x = x;
        rect_.y = y;
    }
    SDL_Rect Getrect() const { return rect_; }

protected:
    SDL_Rect rect_;
    SDL_Texture* p_object ;
};

#endif
