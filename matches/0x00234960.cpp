#include "gen/fight.h"

#include "compat/ptr.h"
extern "C" char DAT_004279fc[];
extern "C" char DAT_00427a58[];
struct Member_234960 {
    void Init(const char*);
};

fight::ParamValueFloat* fight::ParamValueFloat::FUN_00234960(const char* name) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004279fc);
    ((Member_234960*)((char*)this + 8))->Init(name);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00427a58);
    return (fight::ParamValueFloat*)(this);
}
