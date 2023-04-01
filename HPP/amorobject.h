#ifndef AMOROBJECT_H_
#define AMOROBJECT_H_
#include "BaseObject.h"
#include "library.h"

#define width_laser 35
#define height_laser 5

#define width_sphere 10
#define height_sphere 10


class amorobject : public BaseObject
{
public:
    enum amo_type
    {
        none = 0,
        laser =1,
        sphere=2,
    };
    amorobject();
    ~amorobject();
    void handleInputAc(SDL_Event event);
    void handlemove();
    int get_type() const {return amo_type;}
    int set_type(const int& type) {amo_type = type;}

    bool get_is_move() const {return is_move_;}
    void set_is_move(bool is_move) {is_move_ = is_move;}
    void setWidtheight( const int& widht, const int& height)
    {
        rect_.w = widht;
        rect_.h = height;
    }
private:
    int x_val;
    int y_val;
    bool is_move_;
    int amo_type;
};

#endif // AMOROBJECT_H_
