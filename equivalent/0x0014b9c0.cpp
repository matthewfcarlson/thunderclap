// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 16/16)
// FUN_0014b9c0 @ 0x0014b9c0
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

namespace hulkfight {
namespace motion {
class CivilianAnimationTrack {
public:
    void FUN_00147090();
    void FUN_001470b0();
    void FUN_001470c0();
    void FUN_001470e0();
    void FUN_00147100();
    void FUN_00147120();
    void FUN_00147140();
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

struct ParamRegistry {
};
extern ParamRegistry DAT_004e101c;
extern int DAT_004e1020;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0014b9c0()
{
    if (DAT_004e1020 == 0) {
        void* params[7];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack>("timeBegin", &hulkfight::motion::CivilianAnimationTrack::FUN_00147090);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack>("timeEnd", &hulkfight::motion::CivilianAnimationTrack::FUN_001470b0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamName<hulkfight::motion::CivilianAnimationTrack>("animation", &hulkfight::motion::CivilianAnimationTrack::FUN_001470c0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack>("speed", &hulkfight::motion::CivilianAnimationTrack::FUN_001470e0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack>("startFrame", &hulkfight::motion::CivilianAnimationTrack::FUN_00147100);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamBool<hulkfight::motion::CivilianAnimationTrack>("cyclic", &hulkfight::motion::CivilianAnimationTrack::FUN_00147120);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamFloatConstRange<hulkfight::motion::CivilianAnimationTrack>("blendTime", &hulkfight::motion::CivilianAnimationTrack::FUN_00147140);
        FUN_002347b0(&DAT_004e101c, params, 7);
    }
    DAT_004e1020++;
}
