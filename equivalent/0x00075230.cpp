// STATUS: equivalent (tools/equiv.py level 3: 1835 inputs, branch coverage 56/56)
// FUN_00075230 @ 0x00075230
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CCameraDramaticTrack {
public:
    void FUN_00068630();
    void FUN_00068640();
    void FUN_00068650();
    void FUN_000686f0();
    void FUN_00012080();
    void FUN_00068670();
    void FUN_000120a0();
    void FUN_00068680();
    void FUN_000120c0();
    void FUN_00068690();
    void FUN_000120e0();
    void FUN_000686a0();
    void FUN_00012100();
    void FUN_000686b0();
    void FUN_00012120();
    void FUN_000686c0();
    void FUN_00012140();
    void FUN_000686d0();
    void FUN_00012160();
    void FUN_000686e0();
    void FUN_00068700();
    void FUN_00068710();
    void FUN_00068720();
    void FUN_00068730();
    void FUN_00068740();
    void FUN_00068750();
    void FUN_00068760();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
};
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
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234a90(const char* name);
    ParamNameBase(const char* name) { FUN_00234a90(name); }
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
class ParamBool : public ParamBoolBase {
public:
    ParamBool(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
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
class ParamName : public ParamNameBase {
public:
    ParamName(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
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
extern ParamRegistry DAT_004dcfa8;
extern int DAT_004dcfac;

extern const char* DAT_00496f9c[2];
extern const char* DAT_00496fa4[4];

void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00075230()
{
    if (DAT_004dcfac == 0) {
        void* params[27];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<::CCameraDramaticTrack>("timeBegin", &::CCameraDramaticTrack::FUN_00068630);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<::CCameraDramaticTrack>("timeEnd", &::CCameraDramaticTrack::FUN_00068640);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamVector<::CCameraDramaticTrack>("targetOffset", &::CCameraDramaticTrack::FUN_00068650);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamFloatConstRange<::CCameraDramaticTrack>("noCamWeight", &::CCameraDramaticTrack::FUN_000686f0);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamName<::CCameraDramaticTrack>("animation0", &::CCameraDramaticTrack::FUN_00012080);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamFloatConstRange<::CCameraDramaticTrack>("weight0", &::CCameraDramaticTrack::FUN_00068670);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamName<::CCameraDramaticTrack>("animation1", &::CCameraDramaticTrack::FUN_000120a0);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamFloatConstRange<::CCameraDramaticTrack>("weight1", &::CCameraDramaticTrack::FUN_00068680);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamName<::CCameraDramaticTrack>("animation2", &::CCameraDramaticTrack::FUN_000120c0);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<::CCameraDramaticTrack>("weight2", &::CCameraDramaticTrack::FUN_00068690);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamName<::CCameraDramaticTrack>("animation3", &::CCameraDramaticTrack::FUN_000120e0);
        mem = FUN_0008d690(0x18);
        params[11] = 0;
        if (mem)
            params[11] = new (mem) fight::ParamFloatConstRange<::CCameraDramaticTrack>("weight3", &::CCameraDramaticTrack::FUN_000686a0);
        mem = FUN_0008d690(0x18);
        params[12] = 0;
        if (mem)
            params[12] = new (mem) fight::ParamName<::CCameraDramaticTrack>("animation4", &::CCameraDramaticTrack::FUN_00012100);
        mem = FUN_0008d690(0x18);
        params[13] = 0;
        if (mem)
            params[13] = new (mem) fight::ParamFloatConstRange<::CCameraDramaticTrack>("weight4", &::CCameraDramaticTrack::FUN_000686b0);
        mem = FUN_0008d690(0x18);
        params[14] = 0;
        if (mem)
            params[14] = new (mem) fight::ParamName<::CCameraDramaticTrack>("animation5", &::CCameraDramaticTrack::FUN_00012120);
        mem = FUN_0008d690(0x18);
        params[15] = 0;
        if (mem)
            params[15] = new (mem) fight::ParamFloatConstRange<::CCameraDramaticTrack>("weight5", &::CCameraDramaticTrack::FUN_000686c0);
        mem = FUN_0008d690(0x18);
        params[16] = 0;
        if (mem)
            params[16] = new (mem) fight::ParamName<::CCameraDramaticTrack>("animation6", &::CCameraDramaticTrack::FUN_00012140);
        mem = FUN_0008d690(0x18);
        params[17] = 0;
        if (mem)
            params[17] = new (mem) fight::ParamFloatConstRange<::CCameraDramaticTrack>("weight6", &::CCameraDramaticTrack::FUN_000686d0);
        mem = FUN_0008d690(0x18);
        params[18] = 0;
        if (mem)
            params[18] = new (mem) fight::ParamName<::CCameraDramaticTrack>("animation7", &::CCameraDramaticTrack::FUN_00012160);
        mem = FUN_0008d690(0x18);
        params[19] = 0;
        if (mem)
            params[19] = new (mem) fight::ParamFloatConstRange<::CCameraDramaticTrack>("weight7", &::CCameraDramaticTrack::FUN_000686e0);
        mem = FUN_0008d690(0x18);
        params[20] = 0;
        if (mem)
            params[20] = new (mem) fight::ParamBool<::CCameraDramaticTrack>("abortWhenInterrupted", &::CCameraDramaticTrack::FUN_00068700);
        mem = FUN_0008d690(0x20);
        params[21] = 0;
        if (mem)
            params[21] = new (mem) fight::ParamEnumConstList<::CCameraDramaticTrack>("blendInTransition", DAT_00496f9c, 2, &::CCameraDramaticTrack::FUN_00068710);
        mem = FUN_0008d690(0x20);
        params[22] = 0;
        if (mem)
            params[22] = new (mem) fight::ParamEnumConstList<::CCameraDramaticTrack>("blendInBlend", DAT_00496fa4, 4, &::CCameraDramaticTrack::FUN_00068720);
        mem = FUN_0008d690(0x18);
        params[23] = 0;
        if (mem)
            params[23] = new (mem) fight::ParamFloatConstRange<::CCameraDramaticTrack>("blendInDuration", &::CCameraDramaticTrack::FUN_00068730);
        mem = FUN_0008d690(0x20);
        params[24] = 0;
        if (mem)
            params[24] = new (mem) fight::ParamEnumConstList<::CCameraDramaticTrack>("blendOutTransition", DAT_00496f9c, 2, &::CCameraDramaticTrack::FUN_00068740);
        mem = FUN_0008d690(0x20);
        params[25] = 0;
        if (mem)
            params[25] = new (mem) fight::ParamEnumConstList<::CCameraDramaticTrack>("blendOutBlend", DAT_00496fa4, 4, &::CCameraDramaticTrack::FUN_00068750);
        mem = FUN_0008d690(0x18);
        params[26] = 0;
        if (mem)
            params[26] = new (mem) fight::ParamFloatConstRange<::CCameraDramaticTrack>("blendOutDuration", &::CCameraDramaticTrack::FUN_00068760);
        FUN_002347b0(&DAT_004dcfa8, params, 27);
    }
    DAT_004dcfac++;
}
