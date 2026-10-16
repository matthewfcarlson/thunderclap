// Same code shape as 0x001ef6d0 (propagated; names are from that function)
#include "gen/global.h"

class Singleton_1ef720 {
  public:
    void Run();
};
extern Singleton_1ef720** gSingleton_1ef720;

void CSoundCommand_StopNISEvent::vfunc_1(int , int ) {
    (*gSingleton_1ef720)->Run();
}
