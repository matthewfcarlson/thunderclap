#include "gen/fight.h"

#include "compat/ptr.h"
typedef unsigned int u32_238a50;
extern u32_238a50 PrintTrack_vftable;
void __cdecl ReleaseThing(int);
struct PrintTrack_nv_238a50 {
    void Cleanup();
};

void fight::PrintTrack::FUN_00238a50() {
    *(hulk_uintptr*)this = (hulk_uintptr)&PrintTrack_vftable;
    ReleaseThing(this->f_10);
    ReleaseThing(this->f_14);
    ((PrintTrack_nv_238a50*)this)->Cleanup();
}
