#include "gen/hulkfight.h"
#include "decls/data/game/hulkfight/ai.h"

struct Pair_10f3a0 {
    unsigned int first, second;
};
struct Settings_10f3a0 {
    char pad[24];
    Pair_10f3a0 pair;
    float value;
};
struct ActorState_10f3a0 {
    void FUN_00059a30();
};
struct Actor_10f3a0 {
    ActorState_10f3a0* FUN_000592a0();
};
struct Manager_10f3a0 {
    void FUN_00067730();
    float FUN_000670e0(Pair_10f3a0*);
    void FUN_000670a0(Pair_10f3a0*, int);
};
Manager_10f3a0* __cdecl FUN_000678d0();
struct StaticObject {
    char data[8];
    void FUN_0027af00();
};
void __cdecl FUN_00363ec0();
int __cdecl _atexit(void(__cdecl*)());
namespace hulkfight {
namespace ai {

} // namespace ai
} // namespace hulkfight
void hulkfight::ai::HulkAction::vfunc_4() {
    if (!(*(Actor_10f3a0 * *)&this->f_20))
        return;
    if (!((*(unsigned int*)&DAT_004e0bf8) & 1)) {
        (*(unsigned int*)&DAT_004e0bf8) |= 1;
        (*(StaticObject*)&DAT_004e0bf0).FUN_0027af00();
        _atexit(FUN_00363ec0);
    }
    (*(Actor_10f3a0 * *)&this->f_20)->FUN_000592a0()->FUN_00059a30();
    FUN_000678d0()->FUN_00067730();
    float value;
    Pair_10f3a0 pair;
    if ((*(Settings_10f3a0 * *)&this->f_1c)->value == 0.0f)
        value = 1.0f;
    else if ((*(Settings_10f3a0 * *)&this->f_1c)->value < 0.0f) {
        pair = (*(Settings_10f3a0 * *)&this->f_1c)->pair;
        value = -FUN_000678d0()->FUN_000670e0(&pair);
    } else
        value = (*(Settings_10f3a0 * *)&this->f_1c)->value;
    pair = (*(Settings_10f3a0 * *)&this->f_1c)->pair;
    int result = (int)value;
    FUN_000678d0()->FUN_000670a0(&pair, result);
}
