// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 24/24)
// FUN_001a9800 @ 0x001a9800
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class EffectTrack {
public:
    void FUN_001a1f80();
    void FUN_001a1fa0();
    void FUN_001a1fb0();
    void FUN_001a1fc0();
    void FUN_001a1fe0();
    void FUN_001a1ff0();
    void FUN_001a2020();
    void FUN_001a2060();
    void FUN_001a20b0();
    void FUN_001a20c0();
    void FUN_001a20e0();
};

class __declspec(novtable) ParamEnumConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234cc0(const char* name);
    ParamEnumConstListBase(const char* name) { FUN_00234cc0(name); }
};
namespace fight {
template <class T>
class ParamEnumConstList : public ParamEnumConstListBase {
public:
    ParamEnumConstList(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}

class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
namespace fight {
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
};
namespace fight {
template <class T>
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234ba0(const char* name);
    ParamNameConstListBase(const char* name) { FUN_00234ba0(name); }
};
namespace fight {
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
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
class ParamVector : public ParamVectorBase {
public:
    ParamVector(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

struct ParamRegistry {
};
extern ParamRegistry DAT_004e1750;
extern int DAT_004e1754;
extern const char* DAT_00495d60[1];
extern const char* DAT_00495d50[1];
extern int DAT_003fa9e8;
extern int DAT_003fa9e4;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_001a9800()
{
    if (DAT_004e1754 == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<EffectTrack>("timeBegin", &EffectTrack::FUN_001a1f80);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<EffectTrack>("timeEnd", &EffectTrack::FUN_001a1fa0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName<EffectTrack>("characterName", &EffectTrack::FUN_001a1fb0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamName<EffectTrack>("effectName", &EffectTrack::FUN_001a1fc0);
        mem = FUN_0008d690(0x20);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamEnumConstList<EffectTrack>("emitSpace", DAT_00495d60, DAT_003fa9e8, &EffectTrack::FUN_001a1fe0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamNameConstList<EffectTrack>("emitJoint", &EffectTrack::FUN_001a1ff0);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamVector<EffectTrack>("offset", &EffectTrack::FUN_001a2020);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamVector<EffectTrack>("orientation", &EffectTrack::FUN_001a2060);
        mem = FUN_0008d690(0x20);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamEnumConstList<EffectTrack>("attachSpace", DAT_00495d50, DAT_003fa9e4, &EffectTrack::FUN_001a20b0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamNameConstList<EffectTrack>("attachJoint", &EffectTrack::FUN_001a20c0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<EffectTrack>("scale", &EffectTrack::FUN_001a20e0);
        FUN_002347b0(&DAT_004e1750, params, 11);
    }
    DAT_004e1754++;
}
