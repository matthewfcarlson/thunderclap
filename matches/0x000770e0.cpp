#include "gen/fight.h"

extern "C" char DAT_003fbbe8[];
class CMoveTrack_770e0 {
  public:
    void Init();
};
extern void* __cdecl Allocate(unsigned int);

template <> void* fight::TrackFactoryTemplate<CMoveTrack>::vfunc_5() {
    CMoveTrack_770e0* p = (CMoveTrack_770e0*)Allocate(0x28);
    if (p) {
        p->Init();
        *(int*)((char*)p + 0x0c) = 0;
        *(int*)((char*)p + 0x18) = 0;
        *(int*)((char*)p + 0x20) = 0;
        *(int*)((char*)p + 0x24) = 0;
        *(float*)((char*)p + 0x10) = 1.0f;
        *(float*)((char*)p + 0x14) = 1.0f;
        *(int*)((char*)p) = ((int)DAT_003fbbe8);
        *(int*)((char*)p + 0x1c) = -1;
        *(int*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
