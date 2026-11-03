// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 26/26)
// FUN_00065190 @ 0x00065190
#include "decls/data/game/global.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CSmartPropAttachTrack_65190 {
public:
    void FUN_00061cb0();
    void FUN_00061cc0();
    void FUN_00061cd0();
    void FUN_00012670();
    void FUN_00012680();
    void FUN_00061ce0();
    void FUN_00061cf0();
    void FUN_000622d0();
    void FUN_00061d20();
    void FUN_00061d10();
    void FUN_00061d30();
    void FUN_00012720();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
namespace fight {
template <class T>
class ParamBool_65190 : public ParamBoolBase {
public:
    ParamBool_65190(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
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
class ParamFloatConstRange_65190 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_65190(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
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
class ParamIntConstRange_65190 : public ParamIntConstRangeBase {
public:
    ParamIntConstRange_65190(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
namespace fight {
template <class T>
class ParamName_65190 : public ParamNameBase {
public:
    ParamName_65190(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
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
class ParamNameConstList_65190 : public ParamNameConstListBase {
public:
    ParamNameConstList_65190(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
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
class ParamVector_65190 : public ParamVectorBase {
public:
    ParamVector_65190(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

extern "C" void FUN_00065190()
{
    if (DAT_004dc624 == 0) {
        void* params[12];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_65190<CSmartPropAttachTrack_65190>("timeBegin", &CSmartPropAttachTrack_65190::FUN_00061cb0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_65190<CSmartPropAttachTrack_65190>("timeAttach", &CSmartPropAttachTrack_65190::FUN_00061cc0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamIntConstRange_65190<CSmartPropAttachTrack_65190>("attachmentIndex", &CSmartPropAttachTrack_65190::FUN_00061cd0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamNameConstList_65190<CSmartPropAttachTrack_65190>("joint", &CSmartPropAttachTrack_65190::FUN_00012670);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamNameConstList_65190<CSmartPropAttachTrack_65190>("channel", &CSmartPropAttachTrack_65190::FUN_00012680);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamBool_65190<CSmartPropAttachTrack_65190>("useOffset", &CSmartPropAttachTrack_65190::FUN_00061ce0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamVector_65190<CSmartPropAttachTrack_65190>("offset", &CSmartPropAttachTrack_65190::FUN_00061cf0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamVector_65190<CSmartPropAttachTrack_65190>("orientation", &CSmartPropAttachTrack_65190::FUN_000622d0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamFloatConstRange_65190<CSmartPropAttachTrack_65190>("minDistance", &CSmartPropAttachTrack_65190::FUN_00061d20);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamBool_65190<CSmartPropAttachTrack_65190>("useCharacterArray", &CSmartPropAttachTrack_65190::FUN_00061d10);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamVector_65190<CSmartPropAttachTrack_65190>("velocityOffset", &CSmartPropAttachTrack_65190::FUN_00061d30);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamName_65190<CSmartPropAttachTrack_65190>("state", &CSmartPropAttachTrack_65190::FUN_00012720);
        FUN_002347b0(((ParamRegistry*)&DAT_004dc620), params, 12);
    }
    DAT_004dc624++;
}
