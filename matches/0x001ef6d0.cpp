#include "gen/global.h"
#include "decls/data/game/unknown.h"
// data: gSingleton_1ef6d0 = DAT_004e370c

class Singleton_1ef6d0 {
  public:
    void Run();
};

void CSoundCommand_PlayCuedNISEvent::vfunc_1(int , int ) {
    (*(*(Singleton_1ef6d0***)&DAT_004e370c))->Run();
}
