// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 6/6)
// FUN_00187fa0 @ 0x00187fa0
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class PropDropTrack_187fa0 {
public:
    void FUN_0017f790();
    void FUN_0017f7b0();
};
}
}

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_187fa0 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_187fa0(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange_187fa0 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_187fa0(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00187fa0()
{
    if (DAT_004e1484 == 0) {
        void* params[2];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_187fa0<hulkfight::motion::PropDropTrack_187fa0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_187fa0<hulkfight::motion::PropDropTrack_187fa0>("timeBegin", &hulkfight::motion::PropDropTrack_187fa0::FUN_0017f790);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_187fa0<hulkfight::motion::PropDropTrack_187fa0>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamIntConstRange_187fa0<hulkfight::motion::PropDropTrack_187fa0>("attachmentIndex", &hulkfight::motion::PropDropTrack_187fa0::FUN_0017f7b0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1480), params, 2);
    }
    DAT_004e1484++;
}
