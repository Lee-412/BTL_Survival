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
 ThreatsObj* p_threats= new ThreatsObj[NUM_Threat];

bool SDLF::CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2)
{
  int left_a = object1.x;
  int right_a = object1.x + object1.w;
  int top_a = object1.y;
  int bottom_a = object1.y + object1.h;

  int left_b = object2.x;
  int right_b = object2.x + object2.w;
  int top_b = object2.y;
  int bottom_b = object2.y + object2.h;

  // Case 1: size object 1 < size object 2
  if (left_a > left_b && left_a < right_b)
  {
    if (top_a > top_b && top_a < bottom_b)
    {
      return true;
    }
  }

  if (left_a > left_b && left_a < right_b)
  {
    if (bottom_a > top_b && bottom_a < bottom_b)
    {
      return true;
    }
  }

  if (right_a > left_b && right_a < right_b)
  {
    if (top_a > top_b && top_a < bottom_b)
    {
      return true;
    }
  }

  if (right_a > left_b && right_a < right_b)
  {
    if (bottom_a > top_b && bottom_a < bottom_b)
    {
      return true;
    }
  }

  // Case 2: size object 1 < size object 2
  if (left_b > left_a && left_b < right_a)
  {
    if (top_b > top_a && top_b < bottom_a)
    {
      return true;
    }
  }

  if (left_b > left_a && left_b < right_a)
  {
    if (bottom_b > top_a && bottom_b < bottom_a)
    {
      return true;
    }
  }

  if (right_b > left_a && right_b < right_a)
  {
    if (top_b > top_a && top_b < bottom_a)
    {
      return true;
    }
  }

  if (right_b > left_a && right_b < right_a)
  {
    if (bottom_b > top_a && bottom_b < bottom_a)
    {
      return true;
    }
  }

   // Case 3: size object 1 = size object 2
  if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
  {
    return true;
  }

  return false;
}

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
            charac_object.Handlemove(x,y);
            charac_object.Show(c_character,x,y);
        }
        for(int tt=0; tt<NUM_Threat; tt++)
        {
            ThreatsObj* p_threat=(p_threats+tt);
            p_threat->set_x_val(dem=dem+0.00005);
            p_threat->set_y_val(dem=dem+0.00005);
            for(int i=0; i<=0 ; i++)
                {
                    x_v[i]=p_threat->Getrect().x;
                    y_v[i]=p_threat->Getrect().y;
                }
            if (x_v[0]==x && y_v[0]==y) return;
            else
            {
                p_threat->handlemove(SCREEN_WIDTH*0.5,SCREEN_HEIGHT*0.5);
                p_threat->Showthr(c_threat,x_v[0],y_v[0]);
                //checkcollision
                bool is_col = SDLF::CheckCollision(charac_object.Getrect(),p_threat->Getrect());
                if(is_col)
                {
                    if(MessageBox(NULL, "Gameover", "info", MB_OK)==IDOK)
                    {
                        //delete[] p_threats;
                        //SDL_Quit();
                        return ;
                    }
                }
            }
        }
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

    c_background =SDLF::loadimage("background.png");
    c_character=SDLF::loadimage("charac.png");

    charac_object.SetRect(0,600);
     bool ret = charac_object.Loadimg("charac.png");
    if (!ret){return 0;}


    for(int t=0; t<NUM_Threat; t++)
    {
        ThreatsObj* p_threat= (p_threats+t);
        c_threat=SDLF::loadimage("threat.png");
        bool ret2= p_threat->Loadimg("threat.png");
        if(ret2==false){return 0;}
        p_threat->SetRect(SCREEN_WIDTH+t*400,SCREEN_HEIGHT*0.8);


    } waitUntilKeyPressed();

    INIT::quitSDL(window, renderer);
    return 0;
}
