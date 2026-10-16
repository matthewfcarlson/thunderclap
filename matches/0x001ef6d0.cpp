#include "gen/global.h"

class Singleton_1ef6d0 {
  public:
    void Run();
};
extern Singleton_1ef6d0** gSingleton_1ef6d0;

void CSoundCommand_PlayCuedNISEvent::vfunc_1(int , int ) {
    (*gSingleton_1ef6d0)->Run();
}
