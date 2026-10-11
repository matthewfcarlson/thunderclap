// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 14/14)
// FUN_00129310 @ 0x00129310
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class AcquireTargetTrack {
public:
    void FUN_00123990();
    void FUN_001239a0();
    void FUN_001239c0();
    void FUN_001239f0();
    void FUN_00123a10();
    void FUN_00123a40();
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

class __declspec(novtable) ParamVectorBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234e50(const char* name);
    ParamVectorBase(const char* name) { FUN_00234e50(name); }
};
template <class T>
class ParamVector : public ParamVectorBase {
public:
    ParamVector(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};

struct ParamRegistry {
};
extern ParamRegistry DAT_004e0e04;
extern int DAT_004e0e08;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00129310()
{
    if (DAT_004e0e08 == 0) {
        void* params[6];
        void* mem;

        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<AcquireTargetTrack>("timeBegin", &AcquireTargetTrack::FUN_00123990);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<AcquireTargetTrack>("timeEnd", &AcquireTargetTrack::FUN_001239a0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamFloatConstRange<AcquireTargetTrack>("targetArc", &AcquireTargetTrack::FUN_001239c0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamFloatConstRange<AcquireTargetTrack>("targetDistance", &AcquireTargetTrack::FUN_001239f0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<AcquireTargetTrack>("useDirection", &AcquireTargetTrack::FUN_00123a10);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamVector<AcquireTargetTrack>("direction", &AcquireTargetTrack::FUN_00123a40);
        FUN_002347b0(&DAT_004e0e04, params, 6);
    }
    DAT_004e0e08++;
}
