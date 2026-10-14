inline void* __cdecl operator new(unsigned int, void* p) {
    return p;
}
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void __cdecl FUN_000480e0();
extern "C" void __cdecl FUN_000480f0();
extern int DAT_00427760, DAT_0040d0e4, DAT_004dc538, DAT_004dc53c;
extern char DAT_00427758, DAT_004a1ab4;
struct Base_54240 {
    virtual void slot0();
    char padding[12];
    void FUN_00234cc0(const char*);
};
class CAlertStatusCondition;
namespace fight {
template <class T> struct ParamEnumConstList : Base_54240 {
    virtual void slot0();
    void* list;
    int count;
    void(__cdecl* callback)();
    int extra;
};
} // namespace fight
typedef fight::ParamEnumConstList<CAlertStatusCondition> Param;
extern "C" void __cdecl FUN_002347b0(void*, Base_54240**, int);
void target() {
    if (DAT_004dc53c == 0) {
        Base_54240* entries[2];
        void* mem = FUN_0008d690(32);
        if (mem) {
            int count = DAT_00427760;
            ((Base_54240*)mem)->FUN_00234cc0("compare");
            Param* p = new (mem) Param;
            p->list = &DAT_00427758;
            p->count = count;
            p->callback = FUN_000480e0;
            entries[0] = p;
        } else
            entries[0] = 0;
        mem = FUN_0008d690(32);
        if (mem) {
            int count = DAT_0040d0e4;
            ((Base_54240*)mem)->FUN_00234cc0("status");
            Param* p = new (mem) Param;
            p->list = &DAT_004a1ab4;
            p->count = count;
            p->callback = FUN_000480f0;
            entries[1] = p;
        } else
            entries[1] = 0;
        FUN_002347b0(&DAT_004dc538, entries, 2);
    }
    ++DAT_004dc53c;
}
