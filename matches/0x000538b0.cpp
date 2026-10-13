__forceinline void* __cdecl operator new(unsigned, void* p) {
    return p;
}
extern "C" void* __cdecl FUN_0008d690(unsigned);
extern "C" void FUN_00047e00();
extern "C" void FUN_00047e10();
extern "C" void FUN_00047e20();
extern int DAT_004dc4a4;
extern int DAT_004dc4a0;
extern char DAT_003f6b40[];
struct FUN_00234860 {
    FUN_00234860(const char* = "matchType");
    virtual void slot0();
    char pad[12];
    void (*callback)();
    int tail;
};
struct FUN_00234cc0 {
    FUN_00234cc0(const char* = "type");
    virtual void slot0();
    char pad[12];
    const char* list;
    int count;
    void (*callback)();
    int tail;
};
struct FUN_002348e0 {
    FUN_002348e0(const char* = "attachmentIndex");
    virtual void slot0();
    char pad[12];
    void (*callback)();
    int tail;
};
class CSmartPropAttachedCondition;
namespace fight {
template <class T> struct ParamBool : FUN_00234860 {
    virtual void slot0();
};
template <class T> struct ParamEnumConstList : FUN_00234cc0 {
    virtual void slot0();
};
template <class T> struct ParamIntConstRange : FUN_002348e0 {
    virtual void slot0();
};
} // namespace fight
extern "C" void __cdecl FUN_002347b0(void*, void**, int);
void __cdecl FUN_000538b0() {
    if (!DAT_004dc4a4) {
        void* params[3];
        void* mem = FUN_0008d690(24);
        if (mem) {
            fight::ParamBool<CSmartPropAttachedCondition>* p =
                new (mem) fight::ParamBool<CSmartPropAttachedCondition>;
            p->callback = FUN_00047e00;
            params[0] = p;
        } else
            params[0] = 0;
        mem = FUN_0008d690(32);
        if (mem) {
            fight::ParamEnumConstList<CSmartPropAttachedCondition>* p =
                new (mem) fight::ParamEnumConstList<CSmartPropAttachedCondition>;
            p->list = DAT_003f6b40;
            p->count = 23;
            p->callback = FUN_00047e10;
            params[1] = p;
        } else
            params[1] = 0;
        mem = FUN_0008d690(24);
        if (mem) {
            fight::ParamIntConstRange<CSmartPropAttachedCondition>* p =
                new (mem) fight::ParamIntConstRange<CSmartPropAttachedCondition>;
            p->callback = FUN_00047e20;
            params[2] = p;
        } else
            params[2] = 0;
        FUN_002347b0(&DAT_004dc4a0, params, 3);
    }
    ++DAT_004dc4a4;
}
