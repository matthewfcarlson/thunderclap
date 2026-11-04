// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 24/24)
// FUN_0017cc30 @ 0x0017cc30
#include "decls/data/game/hulkfight/motion.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class JointRelativeTrack {
public:
    void FUN_0016ead0();
    void FUN_0016eae0();
    void FUN_0016eaf0();
    void FUN_0016eb10();
    void FUN_0016eb30();
    void FUN_0016eb60();
    void FUN_0016eb90();
    void FUN_0016ebc0();
    void FUN_0016ec10();
    void FUN_0016ec30();
    void FUN_0016ec50();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
namespace fight {
template <class T>
class ParamBool_17cc30 : public ParamBoolBase {
public:
    ParamBool_17cc30(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange_17cc30 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_17cc30(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
namespace fight {
template <class T>
class ParamIntConstRange_17cc30 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_17cc30(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
namespace fight {
template <class T>
class ParamNameConstList_17cc30 : public ParamNameConstListBase {
public:
    ParamNameConstList_17cc30(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
namespace fight {
template <class T>
class ParamVector_17cc30 : public ParamVectorBase {
public:
    ParamVector_17cc30(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_0017cc30()
{
    if (DAT_004e130c == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17cc30<JointRelativeTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_17cc30<JointRelativeTrack>("timeBegin", &JointRelativeTrack::FUN_0016ead0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17cc30<JointRelativeTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_17cc30<JointRelativeTrack>("timeEnd", &JointRelativeTrack::FUN_0016eae0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_17cc30<JointRelativeTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamNameConstList_17cc30<JointRelativeTrack>("joint", &JointRelativeTrack::FUN_0016eaf0);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_17cc30<JointRelativeTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamBool_17cc30<JointRelativeTrack>("useRestPose", &JointRelativeTrack::FUN_0016eb10);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_17cc30<JointRelativeTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamBool_17cc30<JointRelativeTrack>("hasTranslation", &JointRelativeTrack::FUN_0016eb30);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_17cc30<JointRelativeTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamVector_17cc30<JointRelativeTrack>("translation", &JointRelativeTrack::FUN_0016eb60);
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_17cc30<JointRelativeTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamBool_17cc30<JointRelativeTrack>("hasRotation", &JointRelativeTrack::FUN_0016eb90);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_17cc30<JointRelativeTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamVector_17cc30<JointRelativeTrack>("rotation", &JointRelativeTrack::FUN_0016ebc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamIntConstRange_17cc30<JointRelativeTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamIntConstRange_17cc30<JointRelativeTrack>("priority", &JointRelativeTrack::FUN_0016ec10);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17cc30<JointRelativeTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange_17cc30<JointRelativeTrack>("blendInTime", &JointRelativeTrack::FUN_0016ec30);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_17cc30<JointRelativeTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_17cc30<JointRelativeTrack>("blendOutTime", &JointRelativeTrack::FUN_0016ec50);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1308), params, 11);
    }
    DAT_004e130c++;
}
