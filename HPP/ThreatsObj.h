#ifndef THREATSOBJ_H_
#define THREATSOBJ_H_
#include "library.h"
#include "BaseObject.h"
#include "ctime"
#include <unistd.h>
//#include <bits/stdc++.h>
#define WIDTH_THREAT 20;
#define HEIGHT_THREAT 20;

class ThreatsObj: public BaseObject
{
public:
    ThreatsObj();
    ~ThreatsObj();
    void handlemove(const int& x_bordr, const& y_bordr);
    void handleIpAc(SDL_Event events);

    void set_x_val(const int &val ) {x_val = val;}
    void set_y_val (const int &val) {y_val = val;}
    int get_x_val() const
    {
       // usleep(0.005);
        return rand() % 1200;
    }
    int get_y_val() const
    {
           usleep(5000);
    //   std::this_thread::sleep_for(std::chrono::microseconds(500000));
        return rand() % 600;
    }
public :
    int x_val;
    int y_val;
};

#endif // THREATSOBG_H_
