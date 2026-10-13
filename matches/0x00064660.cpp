void* __cdecl FUN_0008d690(unsigned);
inline void* __cdecl operator new(unsigned, void* p) {
    return p;
}
void __cdecl FUN_00061f70();
void __cdecl FUN_00061f80();
void __cdecl FUN_00061f90();
extern unsigned DAT_004dc664;
extern void* DAT_004dc660;
extern unsigned DAT_00496168[];
void __cdecl FUN_002347b0(void*, void**, int);
class CSmartPropEventTrack;
namespace fight {
template <class T> struct ParamIntConstRange {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    char pad[12];
    void(__cdecl* callback)();
    unsigned tail;
    void FUN_002348e0(const char*);
};
template <class T> struct ParamEnumConstList {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    char pad[12];
    unsigned* list;
    unsigned count;
    void(__cdecl* callback)();
    unsigned tail;
    void FUN_00234cc0(const char*);
};
template <class T> struct ParamFloatConstRange {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    char pad[12];
    void(__cdecl* callback)();
    unsigned tail;
    void FUN_00234960(const char*);
};
} // namespace fight
void __cdecl FUN_00064660() {
    if (!DAT_004dc664) {
        void* params[3];
        void* mem = FUN_0008d690(24);
        if (mem) {
            fight::ParamIntConstRange<CSmartPropEventTrack>* p =
                (fight::ParamIntConstRange<CSmartPropEventTrack>*)mem;
            p->FUN_002348e0("attachmentIndex");
            p = new (mem) fight::ParamIntConstRange<CSmartPropEventTrack>;
            p->callback = FUN_00061f80;
            params[0] = p;
        } else
            params[0] = 0;
        mem = FUN_0008d690(32);
        if (mem) {
            fight::ParamEnumConstList<CSmartPropEventTrack>* p =
                (fight::ParamEnumConstList<CSmartPropEventTrack>*)mem;
            p->FUN_00234cc0("event");
            p = new (mem) fight::ParamEnumConstList<CSmartPropEventTrack>;
            p->list = DAT_00496168;
            p->count = 14;
            p->callback = FUN_00061f90;
            params[1] = p;
        } else
            params[1] = 0;
        mem = FUN_0008d690(24);
        if (mem) {
            fight::ParamFloatConstRange<CSmartPropEventTrack>* p =
                (fight::ParamFloatConstRange<CSmartPropEventTrack>*)mem;
            p->FUN_00234960("timeBegin");
            p = new (mem) fight::ParamFloatConstRange<CSmartPropEventTrack>;
            p->callback = FUN_00061f70;
            params[2] = p;
        } else
            params[2] = 0;
        FUN_002347b0(&DAT_004dc660, params, 3);
    }
    ++DAT_004dc664;
}