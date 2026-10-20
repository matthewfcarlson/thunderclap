#include "compat/ptr.h"
extern "C" char DAT_004279fc[];
extern "C" char DAT_00427a18[];
struct Member_234860 {
    void Init(int);
};
struct ParamValueBool {
    char pad[8];
    ParamValueBool* Build(int);
};
ParamValueBool* ParamValueBool::Build(int value) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004279fc);
    ((Member_234860*)((char*)this + 8))->Init(value);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00427a18);
    return this;
}