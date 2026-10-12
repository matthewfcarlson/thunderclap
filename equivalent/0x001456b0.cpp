// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 28/28)
// FUN_001456b0 @ 0x001456b0
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class WorldConeDamageTrack {
public:
    void FUN_00143400();
    void FUN_00143430();
    void FUN_00143470();
    void FUN_001434b0();
    void FUN_001434e0();
    void FUN_00143510();
    void FUN_00143540();
    void FUN_00143560();
    void FUN_00143580();
    void FUN_001435a0();
    void FUN_001435c0();
    void FUN_001435e0();
    void FUN_00143600();
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
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234960(const char* name);
    ParamFloatConstRangeBase(const char* name) { FUN_00234960(name); }
};
class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
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
template <class T>
class ParamFloatConstRange : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
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
extern ParamRegistry DAT_004e0f98;
extern int DAT_004e0f9c;

extern const char* DAT_004ad788[7];

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_001456b0()
{
    if (DAT_004e0f9c == 0) {
        void* params[13];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WorldConeDamageTrack>("timeBegin", &hulkfight::motion::WorldConeDamageTrack::FUN_00143400);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamVector<hulkfight::motion::WorldConeDamageTrack>("position", &hulkfight::motion::WorldConeDamageTrack::FUN_00143430);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamVector<hulkfight::motion::WorldConeDamageTrack>("direction", &hulkfight::motion::WorldConeDamageTrack::FUN_00143470);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamVector<hulkfight::motion::WorldConeDamageTrack>("up", &hulkfight::motion::WorldConeDamageTrack::FUN_001434b0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WorldConeDamageTrack>("minAngle", &hulkfight::motion::WorldConeDamageTrack::FUN_001434e0);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WorldConeDamageTrack>("maxAngle", &hulkfight::motion::WorldConeDamageTrack::FUN_00143510);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WorldConeDamageTrack>("startDistance", &hulkfight::motion::WorldConeDamageTrack::FUN_00143540);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WorldConeDamageTrack>("length", &hulkfight::motion::WorldConeDamageTrack::FUN_00143560);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamIntConstRange<hulkfight::motion::WorldConeDamageTrack>("minDecals", &hulkfight::motion::WorldConeDamageTrack::FUN_00143580);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamIntConstRange<hulkfight::motion::WorldConeDamageTrack>("maxDecals", &hulkfight::motion::WorldConeDamageTrack::FUN_001435a0);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WorldConeDamageTrack>("minDecalScale", &hulkfight::motion::WorldConeDamageTrack::FUN_001435c0);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange<hulkfight::motion::WorldConeDamageTrack>("maxDecalScale", &hulkfight::motion::WorldConeDamageTrack::FUN_001435e0);
        mem = FUN_0008d690(0x20);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamEnumConstList<hulkfight::motion::WorldConeDamageTrack>("damageType", DAT_004ad788, 7, &hulkfight::motion::WorldConeDamageTrack::FUN_00143600);
        FUN_002347b0(&DAT_004e0f98, params, 13);
    }
    DAT_004e0f9c++;
}
