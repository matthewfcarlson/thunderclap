// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/18)
// FUN_0018a100 @ 0x0018a100
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(hulk_uintptr size);

class PropAnimationTrack {
public:
    void FUN_0017f7c0();
    void FUN_0017f7d0();
    void FUN_0017f7f0();
    void FUN_0017f800();
    void FUN_0017f820();
    void FUN_0017f840();
    void FUN_0017f860();
    void FUN_0017f880();
};

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamEnumBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumBase(const char* name) { FUN_00234cc0(name); }
};
template <class T>
class ParamEnumConstList : public ParamEnumBase {
public:
    ParamEnumConstList(const char* name, char** t, int n, void (T::*s)()) : ParamEnumBase(name) { table = t; count = n; setter = s; }
    virtual void v0();
    char** table;
    int count;
    void (T::*setter)();
    int unused1c;
};

class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
};
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

struct ParamRegistry {
};
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0018a100()
{
    if (DAT_004e148c == 0) {
        void* params[8];
        void* mem;

        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<PropAnimationTrack>("timeBegin", &PropAnimationTrack::FUN_0017f7c0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<PropAnimationTrack>("timeEnd", &PropAnimationTrack::FUN_0017f7d0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamIntConstRange<PropAnimationTrack>("attachmentIndex", &PropAnimationTrack::FUN_0017f7f0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamName<PropAnimationTrack>("animation", &PropAnimationTrack::FUN_0017f800);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<PropAnimationTrack>("speed", &PropAnimationTrack::FUN_0017f820);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<PropAnimationTrack>("startFrame", &PropAnimationTrack::FUN_0017f840);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<PropAnimationTrack>("endFrame", &PropAnimationTrack::FUN_0017f860);
        mem = FUN_0008d690(0x20);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamEnumConstList<PropAnimationTrack>("cyclic", ((char**)&DAT_004abf70), (*(int*)&DAT_004123d4), &PropAnimationTrack::FUN_0017f880);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1488), params, 8);
    }
    DAT_004e148c++;
}
