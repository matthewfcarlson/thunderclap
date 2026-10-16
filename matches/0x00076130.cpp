#include "gen/fight.h"

extern "C" void* __cdecl FUN_0008d690(unsigned int);
class CComboTimerTrack_76130 {
  public:
    CComboTimerTrack_76130();
    int a[6];
};
extern int CComboTimerTrack_vftable;

template <> void* fight::TrackFactoryTemplate<CComboTimerTrack>::vfunc_5() {
    CComboTimerTrack_76130* p = (CComboTimerTrack_76130*)FUN_0008d690(0x18);
    if (p) {
        p->CComboTimerTrack_76130::CComboTimerTrack_76130();
        *(int**)p = &CComboTimerTrack_vftable;
        p->a[3] = 0;
        p->a[4] = (int)0xbf800000;
        p->a[5] = 0;
        p->a[2] = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
