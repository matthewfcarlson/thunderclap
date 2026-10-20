#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int u32_76080;
extern void* __cdecl Alloc(hulk_uintptr);
extern int ComboVtable;
class CComboMessageTrack_76080 {
  public:
    void Init();
};

template <> void* fight::TrackFactoryTemplate<CComboMessageTrack>::vfunc_5() {
    CComboMessageTrack_76080* p = (CComboMessageTrack_76080*)Alloc(0x54);
    if (p) {
        p->Init();
        *(hulk_uintptr*)p = (hulk_uintptr)&ComboVtable;
        *(u32_76080*)((char*)p + 0xc) = 0;
        *(u32_76080*)((char*)p + 0x50) = 0;
        *((char*)p + 0x10) = 0;
        *(u32_76080*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
