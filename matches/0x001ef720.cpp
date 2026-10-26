// Same code shape as 0x001ef6d0 (propagated; names are from that function)
#include "gen/global.h"
#include "decls/data/game/unknown.h"
// data: gSingleton_1ef720 = DAT_004e370c

class Singleton_1ef720 {
  public:
    void Run();
};

void CSoundCommand_StopNISEvent::vfunc_1(int , int ) {
    (*(*(Singleton_1ef720***)&DAT_004e370c))->Run();
}
