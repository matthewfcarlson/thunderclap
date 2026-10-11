// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// FUN_00156280 @ 0x00156280
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class HitFloatTrack {
public:
    void FUN_0014cdd0();
    void FUN_0014cde0();
    void FUN_0014ce00();
    void FUN_0014ce20();
    void FUN_0014ce50();
    void FUN_0014ce70();
    void FUN_0014ce90();
};
}
}

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

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
};
template <class T>
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
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

struct ParamRegistry {
};
extern ParamRegistry DAT_004e1110;
extern int DAT_004e1114;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00156280()
{
    if (DAT_004e1114 == 0) {
        void* params[7];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<hulkfight::motion::HitFloatTrack>("timeBegin", &hulkfight::motion::HitFloatTrack::FUN_0014cdd0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<hulkfight::motion::HitFloatTrack>("timeEnd", &hulkfight::motion::HitFloatTrack::FUN_0014cde0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamBool<hulkfight::motion::HitFloatTrack>("snapToPushback", &hulkfight::motion::HitFloatTrack::FUN_0014ce00);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<hulkfight::motion::HitFloatTrack>("orientation", &hulkfight::motion::HitFloatTrack::FUN_0014ce20);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamIntConstRange<hulkfight::motion::HitFloatTrack>("priority", &hulkfight::motion::HitFloatTrack::FUN_0014ce50);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<hulkfight::motion::HitFloatTrack>("blendInTime", &hulkfight::motion::HitFloatTrack::FUN_0014ce70);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<hulkfight::motion::HitFloatTrack>("blendOutTime", &hulkfight::motion::HitFloatTrack::FUN_0014ce90);
        FUN_002347b0(&DAT_004e1110, params, 7);
    }
    DAT_004e1114++;
}
