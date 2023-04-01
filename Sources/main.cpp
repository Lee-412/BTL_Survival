#include "library.h"
#include "Background.h"
#include "init_clean.h"
#include "MainObject.h"
#include "BaseObject.h"
#include "Asteroid.h"
#include<SDL_image.h>
#include "ThreatsObj.h"
const int number_of_asteroid = 20;
MainObject charac_object;
int x; int y;
int x_v[3]; int y_v[3];
ThreatsObj* p_threat = new ThreatsObj();
double dem;
SDL_Texture* SDLF::loadimage(const char*  file_path)
{
    SDL_Texture* load_image = NULL;
    load_image= IMG_LoadTexture(renderer, file_path);
    if(load_image==NULL)
    {
        std::cout<<"error"<<std::endl;
    }
    return load_image;
}
void SDLF::renderchar(SDL_Texture* texture, int x, int y)
{
    SDL_Rect src;
    src.x=0;
    src.y=0;
    src.w=256;
    src.h=256;

    SDL_Rect dst;
    dst.x=x;
    dst.y=y;
    dst.w=64;
    dst.h=91;
    SDL_RenderCopy(renderer,texture, &src, &dst);
    //SDL_RenderPresent(renderer);
    //SDLF::render(c_background);
}
void SDLF::renderthr(SDL_Texture* texture, int x, int y)
{
    SDL_Rect src;
    src.x=0;
    src.y=0;
    src.w=256;
    src.h=256;

    SDL_Rect dst;
    dst.x=x;
    dst.y=y;
    dst.w=64;
    dst.h=91;
    SDL_RenderCopy(renderer,texture, &src, &dst);
   // SDL_RenderPresent(renderer);
    //SDLF::render(c_background);
}

void SDLF::render(SDL_Texture* texture)
{
    SDL_Rect src;
    src.x=0;
    src.y=0;
    src.w=1200;
    src.h=600;

    SDL_Rect dst;
    dst.x=0;
    dst.y=0;
    dst.w=1230;
    dst.h=600;
    SDL_RenderCopy(renderer,texture, &src, &dst);
}
void waitUntilKeyPressed()
{
    SDL_Event e;
    dem=2;
    while (true)
    {
        SDL_RenderClear(renderer);
        SDLF::render(c_background);

        if ( SDL_PollEvent(&e) != 0 && (e.type == SDL_QUIT ) )
              return ;
        else
        {
            charac_object.HandleInput(e);
            charac_object.Show(c_character,x,y);
            charac_object.Handlemove(x,y);
        }
        p_threat->set_x_val(dem=dem+0.00005);
        p_threat->set_y_val(dem=dem+0.00005);
        for(int i=0; i<= 0; i++)
            {
                x_v[i]=p_threat->Getrect().x;
                y_v[i]=p_threat->Getrect().y;
            }
        p_threat->handlemove(SCREEN_WIDTH*0.5,SCREEN_HEIGHT*0.5);
        p_threat->Showthr(c_threat,x_v[0],y_v[0]);
        SDL_RenderPresent(renderer);
        SDLF::render(c_background);
        SDL_Delay(8);
    }

}
int main(int argc, char** argv)
{
    window = SDL_CreateWindow( WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    INIT::initSDL(window, renderer);
    SDL_RenderClear(renderer);

    c_background =SDLF::loadimage("map3.png");
    c_character=SDLF::loadimage("TANK1.png");
    c_threat=SDLF::loadimage("TANK3.png");
    charac_object.SetRect(0,600);
    bool ret = charac_object.Loadimg("TANK1.png");
    if (!ret){return 0;}
    bool ret2= p_threat->Loadimg("TANK1.png");
    if(ret2==false){return 0;}
    p_threat->SetRect(SCREEN_WIDTH,SCREEN_HEIGHT*0.8);

    waitUntilKeyPressed();
    INIT::quitSDL(window, renderer);
    return 0;
}
