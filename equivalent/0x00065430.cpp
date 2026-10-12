// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 20/20)
// FUN_00065430 @ 0x00065430
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_0008d690(unsigned int size);

class CSmartPropUpdateAttachmentTrack {
public:
    void FUN_00061d50();
    void FUN_00061d60();
    void FUN_00061d70();
    void FUN_00012740();
    void FUN_00012750();
    void FUN_00061d80();
    void FUN_00061d90();
    void FUN_00062480();
    void FUN_00061db0();
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

class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_00234ba0(const char* name);
    ParamNameConstListBase(const char* name) { FUN_00234ba0(name); }
};
template <class T>
class ParamNameConstList : public ParamNameConstListBase {
public:
    ParamNameConstList(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
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
extern ParamRegistry DAT_004dc628;
extern int DAT_004dc62c;
void FUN_002347b0(ParamRegistry* reg, void** params, int count);

void FUN_00065430()
{
    if (DAT_004dc62c == 0) {
        void* params[9];
        void* mem;
        mem = FUN_0008d690(0x18);
        params[0] = 0;
        if (mem)
            params[0] = new (mem) ParamFloatConstRange<CSmartPropUpdateAttachmentTrack>("timeBegin", &CSmartPropUpdateAttachmentTrack::FUN_00061d50);
        mem = FUN_0008d690(0x18);
        params[1] = 0;
        if (mem)
            params[1] = new (mem) ParamFloatConstRange<CSmartPropUpdateAttachmentTrack>("timeAttach", &CSmartPropUpdateAttachmentTrack::FUN_00061d60);
        mem = FUN_0008d690(0x18);
        params[2] = 0;
        if (mem)
            params[2] = new (mem) ParamIntConstRange<CSmartPropUpdateAttachmentTrack>("attachmentIndex", &CSmartPropUpdateAttachmentTrack::FUN_00061d70);
        mem = FUN_0008d690(0x18);
        params[3] = 0;
        if (mem)
            params[3] = new (mem) ParamNameConstList<CSmartPropUpdateAttachmentTrack>("joint", &CSmartPropUpdateAttachmentTrack::FUN_00012740);
        mem = FUN_0008d690(0x18);
        params[4] = 0;
        if (mem)
            params[4] = new (mem) ParamNameConstList<CSmartPropUpdateAttachmentTrack>("channel", &CSmartPropUpdateAttachmentTrack::FUN_00012750);
        mem = FUN_0008d690(0x18);
        params[5] = 0;
        if (mem)
            params[5] = new (mem) ParamBool<CSmartPropUpdateAttachmentTrack>("useOffset", &CSmartPropUpdateAttachmentTrack::FUN_00061d80);
        mem = FUN_0008d690(0x18);
        params[6] = 0;
        if (mem)
            params[6] = new (mem) ParamVector<CSmartPropUpdateAttachmentTrack>("offset", &CSmartPropUpdateAttachmentTrack::FUN_00061d90);
        mem = FUN_0008d690(0x18);
        params[7] = 0;
        if (mem)
            params[7] = new (mem) ParamVector<CSmartPropUpdateAttachmentTrack>("orientation", &CSmartPropUpdateAttachmentTrack::FUN_00062480);
        mem = FUN_0008d690(0x18);
        params[8] = 0;
        if (mem)
            params[8] = new (mem) ParamFloatConstRange<CSmartPropUpdateAttachmentTrack>("minDistance", &CSmartPropUpdateAttachmentTrack::FUN_00061db0);
        FUN_002347b0(&DAT_004dc628, params, 9);
    }
    DAT_004dc62c++;
}
