#include "gen/fight.h"

#include "compat/ptr.h"
extern "C" char DAT_004279fc[];
extern "C" char DAT_00427a98[];
struct Member_234a90 {
    void Init(const char*);
};

fight::ParamValueName* fight::ParamValueName::FUN_00234a90(const char* name) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004279fc);
    ((Member_234a90*)((char*)this + 8))->Init(name);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00427a98);
    return (fight::ParamValueName*)(this);
}
