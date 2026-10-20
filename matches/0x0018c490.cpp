#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_004195cc[];
void* __cdecl FUN_0008d690(unsigned int);
class Track_18c490 {
  public:
    void Init();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PropDestroyTrack>::vfunc_5() {
    Track_18c490* p = (Track_18c490*)FUN_0008d690(0x14);
    if (p) {
        p->Init();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_004195cc);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        *(int*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
