// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_0014b340 @ 0x0014b340
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
extern "C" void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class GrappleAttachJointCondition_14b340 {
public:
    void FUN_00146900();
    void FUN_00146910();
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
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
namespace fight {
template <class T>
class ParamEnumConstList_14b340 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_14b340(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
template <class T>
class ParamNameConstList_14b340 : public ParamNameConstListBase {
public:
    ParamNameConstList_14b340(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};



extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0014b340()
{
    if (DAT_004e0fc0 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690(0x20);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamEnumConstList_14b340<hulkfight::motion::GrappleAttachJointCondition_14b340>("compare", ((const char**)&DAT_00427758), (*(int*)&DAT_00427760), &hulkfight::motion::GrappleAttachJointCondition_14b340::FUN_00146900);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamNameConstList_14b340<hulkfight::motion::GrappleAttachJointCondition_14b340>("joint", &hulkfight::motion::GrappleAttachJointCondition_14b340::FUN_00146910);
        FUN_002347b0(((ParamRegistry*)&DAT_004e0fbc), params, 2);
    }
    DAT_004e0fc0++;
}
