// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 4/4)
// hulkfight::ai::TokenSupressAction::vfunc_3 @ 0x0010de70
#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct Stats_10de70 {
    char pad0[0x18];
    float value;
};
struct Singleton_10de70 {
    char pad0[0x368];
    int f368;
    void FUN_000661f0();
};
void* __fastcall FUN_000592a0(void* p);
void* __fastcall FUN_00059a30(void* p);
Singleton_10de70* FUN_000678d0();
namespace hulkfight { namespace ai {

}}
bool hulkfight::ai::TokenSupressAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    if ((*(void * *)&this->f_20) == 0)
        return false;
    FUN_00059a30(FUN_000592a0((*(void * *)&this->f_20)));
    this->f_24 = FUN_000678d0()->f368;
    if ((*(Stats_10de70 * *)&this->f_1c)->value >= 0.0f) {
        int bits = *(int*)&(*(Stats_10de70 * *)&this->f_1c)->value;
        FUN_000678d0()->f368 = bits;
    }
    FUN_000678d0()->FUN_000661f0();
    return true;
}
