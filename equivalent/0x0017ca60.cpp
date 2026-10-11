// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 14/14)
// FUN_0017ca60 @ 0x0017ca60
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class RestPoseTrack {
public:
    void FUN_0016ea30();
    void FUN_0016ea40();
    void FUN_0016ea50();
    void FUN_0016ea70();
    void FUN_0016ea90();
    void FUN_0016eab0();
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
extern ParamRegistry DAT_004e12f8;
extern int DAT_004e12fc;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0017ca60()
{
    if (DAT_004e12fc == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<RestPoseTrack>("timeBegin", &RestPoseTrack::FUN_0016ea30);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<RestPoseTrack>("timeEnd", &RestPoseTrack::FUN_0016ea40);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamName<RestPoseTrack>("partition", &RestPoseTrack::FUN_0016ea50);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamIntConstRange<RestPoseTrack>("priority", &RestPoseTrack::FUN_0016ea70);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamFloatConstRange<RestPoseTrack>("blendInTime", &RestPoseTrack::FUN_0016ea90);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamFloatConstRange<RestPoseTrack>("blendOutTime", &RestPoseTrack::FUN_0016eab0);
        FUN_002347b0(&DAT_004e12f8, params, 6);
    }
    DAT_004e12fc++;
}
