// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 24/24)
// FUN_0017cc30 @ 0x0017cc30
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class JointRelativeTrack {
public:
    void FUN_0016ead0();
    void FUN_0016eae0();
    void FUN_0016eaf0();
    void FUN_0016eb10();
    void FUN_0016eb30();
    void FUN_0016eb60();
    void FUN_0016eb90();
    void FUN_0016ebc0();
    void FUN_0016ec10();
    void FUN_0016ec30();
    void FUN_0016ec50();
};

class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234860(const char* name);
    ParamBoolBase(const char* name) { FUN_00234860(name); }
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

class __declspec(novtable) ParamIntConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_002348e0(const char* name);
    ParamIntConstRangeBase(const char* name) { FUN_002348e0(name); }
};
namespace fight {
template <class T>
class ParamIntConstRange : public ParamIntConstRangeBase {
public:
    ParamIntConstRange(const char* name, void (T::*s)()) : ParamIntConstRangeBase(name) { setter = s; }
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
extern ParamRegistry DAT_004e1308;
extern int DAT_004e130c;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_0017cc30()
{
    if (DAT_004e130c == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange<JointRelativeTrack>("timeBegin", &JointRelativeTrack::FUN_0016ead0);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange<JointRelativeTrack>("timeEnd", &JointRelativeTrack::FUN_0016eae0);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamNameConstList<JointRelativeTrack>("joint", &JointRelativeTrack::FUN_0016eaf0);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamBool<JointRelativeTrack>("useRestPose", &JointRelativeTrack::FUN_0016eb10);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamBool<JointRelativeTrack>("hasTranslation", &JointRelativeTrack::FUN_0016eb30);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamVector<JointRelativeTrack>("translation", &JointRelativeTrack::FUN_0016eb60);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamBool<JointRelativeTrack>("hasRotation", &JointRelativeTrack::FUN_0016eb90);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamVector<JointRelativeTrack>("rotation", &JointRelativeTrack::FUN_0016ebc0);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamIntConstRange<JointRelativeTrack>("priority", &JointRelativeTrack::FUN_0016ec10);
        mem = FUN_0008d690(0x18);
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamFloatConstRange<JointRelativeTrack>("blendInTime", &JointRelativeTrack::FUN_0016ec30);
        mem = FUN_0008d690(0x18);
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange<JointRelativeTrack>("blendOutTime", &JointRelativeTrack::FUN_0016ec50);
        FUN_002347b0(&DAT_004e1308, params, 11);
    }
    DAT_004e130c++;
}
