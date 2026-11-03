#include "gen/fight.h"

#include "compat/ptr.h"
extern "C" char DAT_004279fc[];
extern "C" char DAT_00427adc[];
struct Member_234ba0 {
    void Init(const char*);
};

fight::ParamValueNameList* fight::ParamValueNameList::FUN_00234ba0(const char* name) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004279fc);
    ((Member_234ba0*)((char*)this + 8))->Init(name);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00427adc);
    return (fight::ParamValueNameList*)(this);
}
