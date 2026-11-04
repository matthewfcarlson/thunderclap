// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_001ac5b0 @ 0x001ac5b0
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/scenario.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace scenario {
class Event_PathNameCondition_1ac5b0 {
public:
    void FUN_001aada0();
    void FUN_001aadb0();
};
}
}

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
namespace fight {
template <class T>
class ParamEnumConstList_1ac5b0 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_1ac5b0(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamName_1ac5b0 : public ParamNameBase {
public:
    ParamName_1ac5b0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};



extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_001ac5b0()
{
    if ((*(int*)&DAT_004e17b4) == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_1ac5b0<hulkfight::scenario::Event_PathNameCondition_1ac5b0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_1ac5b0<hulkfight::scenario::Event_PathNameCondition_1ac5b0>("compare", ((const char**)&DAT_00427758), (*(int*)&DAT_00427760), &hulkfight::scenario::Event_PathNameCondition_1ac5b0::FUN_001aada0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1ac5b0<hulkfight::scenario::Event_PathNameCondition_1ac5b0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamName_1ac5b0<hulkfight::scenario::Event_PathNameCondition_1ac5b0>("pathName", &hulkfight::scenario::Event_PathNameCondition_1ac5b0::FUN_001aadb0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e17b0), params, 2);
    }
    (*(int*)&DAT_004e17b4)++;
}
