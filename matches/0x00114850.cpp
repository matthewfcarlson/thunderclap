#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0040db84[];
extern void* __cdecl FUN_0008d690(unsigned int);
class TrackBase_114850 {
  public:
    void Init();
};
class TrackTail {
  public:
    void Init();
};

template <> void* fight::TrackFactoryTemplate<hulkfight::ai::SemaphoreClearTrack>::vfunc_5() {
    char* p = (char*)FUN_0008d690(0x28);
    if (p) {
        ((TrackBase_114850*)p)->Init();
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0040db84);
        *(unsigned int*)(p + 0xc) = 0;
        *(unsigned int*)(p + 0x10) = 0xbf800000;
        ((TrackTail*)(p + 0x18))->Init();
        p[0x20] = 0;
        p[0x21] = 0;
        *(unsigned int*)(p + 8) = 1;
        return (void*)(p);
    }
    return (void*)((void*)0);
}
