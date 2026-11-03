#include "gen/fight.h"

#include "compat/ptr.h"
extern "C" char DAT_004279fc[];
extern "C" char DAT_00427c68[];
struct Member_235170 {
    void Init(const char*);
};

fight::ParamValueBranch* fight::ParamValueBranch::FUN_00235170(const char* name) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004279fc);
    ((Member_235170*)((char*)this + 8))->Init(name);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00427c68);
    return (fight::ParamValueBranch*)(this);
}
