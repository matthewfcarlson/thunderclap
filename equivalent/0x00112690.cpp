// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 12/12)
// FUN_00112690 @ 0x00112690
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class SemaphoreClearTrack {
public:
    void FUN_0010c3b0();
    void FUN_0010c3c0();
    void FUN_0010c3d0();
    void FUN_0010c3f0();
    void FUN_0010c410();
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
extern ParamRegistry DAT_004e0b60;
extern int DAT_004e0b64;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00112690()
{
    if (DAT_004e0b64 == 0) {
        void* params[5];
        void* mem;

        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<SemaphoreClearTrack>("timeBegin", &SemaphoreClearTrack::FUN_0010c3b0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<SemaphoreClearTrack>("timeEnd", &SemaphoreClearTrack::FUN_0010c3c0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamName<SemaphoreClearTrack>("semaphore", &SemaphoreClearTrack::FUN_0010c3d0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamBool<SemaphoreClearTrack>("clearEveryFrame", &SemaphoreClearTrack::FUN_0010c3f0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamBool<SemaphoreClearTrack>("clearAll", &SemaphoreClearTrack::FUN_0010c410);
        FUN_002347b0(&DAT_004e0b60, params, 5);
    }
    DAT_004e0b64++;
}
