#ifndef MAINOBJECT_H_
#define MAINOBJECT_H_

#include "Background.h"
#include "library.h"
#include "BaseObject.h"
#include <vector>
#include "amorobject.h"

#define WIDTH_MAIN_OBJECT 64;
#define HEIGHT_MAIN_OBJECT 91;


class MainObject : public BaseObject
{
public:
    MainObject();
    ~MainObject();

    void HandleInput (SDL_Event event);
    void Handlemove(int &x, int &y);
    void Show(SDL_Texture* des, int x, int y);
    void setAmorlist(std::vector<amorobject*> amo_list) {p_amor_list = amo_list;}
    std::vector<amorobject*> getamolist() const {return p_amor_list ;}


protected:

    int x_val;
    int y_val;

    std::vector<amorobject*> p_amor_list;

};


#endif // MAINOBJECT_H_
