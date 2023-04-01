#include "amorobject.h"

#include "library.h"
amorobject::amorobject()
{
        rect_.x=0;
        rect_.y=0;
        x_val=0;
        y_val=0;
        is_move_=false;
        amo_type=none;
}
amorobject::~amorobject()
{

}
void amorobject::handlemove()
{

}
void amorobject::handleInputAc(SDL_Event event)
{

}
