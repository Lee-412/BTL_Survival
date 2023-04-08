#include "library.h"
#include "BaseObject.h"
#include "MainObject.h"
#include "Background.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
MainObject::MainObject()
{
    rect_.x=0;
    rect_.y=0;
    rect_.w=WIDTH_MAIN_OBJECT;
    rect_.h=HEIGHT_MAIN_OBJECT;
    x_val=0;
    y_val=0;
}

MainObject::~MainObject()
{
    ;
}
#define MAX_SPEED 3
#define MIN_SPEED -3

void MainObject::HandleInput(SDL_Event events)
{
    SDL_Texture* newc;
    if(events.type == SDL_KEYDOWN)
    {
    switch (events.key.keysym.sym)
        {
        case SDLK_UP:
        {
            y_val = std::max(y_val - 3, MIN_SPEED);
           // std::cout<<y_val<<std::endl;
            break;
        }
        case SDLK_DOWN:
        {
            y_val = std::min(y_val + 3, MAX_SPEED);
            //std::cout<<y_val<<std::endl;
            break;
        }
        case SDLK_RIGHT:
        {
            x_val = std::min(x_val + 3, MAX_SPEED);
            //std::cout<<x_val<<std::endl;
            break;
        }
        case SDLK_LEFT:
        {
            x_val = std::max(x_val - 3, MIN_SPEED);
            //std::cout<<y_val<<std::endl;
            break;
        }
        /*case SDLK_w:
        {
            y_val = y_val-20;
            std::cout<<y_val<<std::endl;
            break;
        }
        case SDLK_s:
        {
            y_val = y_val + 20;
            std::cout<<y_val<<std::endl;
            break;
        }
        case SDLK_d:
        {
            x_val =x_val + 20;
            std::cout<<x_val<<std::endl;
            break;
        }
        case SDLK_a:
        {
            x_val = x_val-20;
            std::cout<<x_val<<std::endl;
            break;
        }*/
        default: break;
        }

    }

    else if(events.type == SDL_KEYUP)
    {
        switch (events.key.keysym.sym)
        {
            case SDLK_UP:
            {
                y_val+=3;

                 //std::cout<<y_val<<std::endl;
                break;
            }
            case SDLK_DOWN:
            {
                y_val-=3;
                //std::cout<<y_val<<std::endl;
                break;
            }
            case SDLK_RIGHT:
            {
                x_val-=3;
                //std::cout<<x_val<<std::endl;
                break;
            }

            case SDLK_LEFT:
            {
                x_val+=3;
                std::cout<<x_val<<std::endl;
                break;
            }
            /* case SDLK_w:
            {
                y_val = y_val + 20;
                std::cout<<y_val<<std::endl;
                break;
            }
            case SDLK_s:
            {
                y_val = y_val - 20;
                std::cout<<y_val<<std::endl;
                break;
            }
            case SDLK_d:
            {
                x_val =x_val - 20;
                std::cout<<x_val<<std::endl;
                break;
            }
            case SDLK_a:
            {
                x_val = x_val + 20;
                std::cout<<x_val<<std::endl;
                break;
            }*/
            default: break;
        }


    }
    else if( events.type == SDL_MOUSEBUTTONDOWN)
    {

    }
    else if(events.type == SDL_MOUSEBUTTONUP)
    {

    }
    else
    {
        ;
    }

}
void MainObject::Handlemove(int &x, int &y){
    int new_x = rect_.x + x_val;
    if(new_x < 0){
        x_val = 0;
        new_x = 0;
    }
    else if(new_x + rect_.w > SCREEN_WIDTH){
        x_val = 0;
        new_x = SCREEN_WIDTH - rect_.w-6;
    }
    int new_y = rect_.y + y_val;
    if(new_y < 0){
        y_val = 0;
        new_y = 0;
    }
    else if(new_y + rect_.h > SCREEN_HEIGHT)
        {
        y_val = 0;
        new_y = SCREEN_HEIGHT - rect_.h-20;
    }

    rect_.x = new_x;
    rect_.y = new_y;
    x = rect_.x;
    y = rect_.y;
}

void MainObject::Show(SDL_Texture* des, int x,int y)
{

    BaseObject::Show(des, x, y);
}
