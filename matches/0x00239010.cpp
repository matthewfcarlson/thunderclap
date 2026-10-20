#include "compat/ptr.h"
#include "decls/data/engine/fight.h"

void* __cdecl FUN_0008d690(hulk_uintptr);
inline void* __cdecl operator new(unsigned, void* memory) {
    return memory;
}
void __cdecl FUN_002347b0(void*, void*, int);
void FUN_00238850();
void FUN_00238a80();
void FUN_00238ae0();
struct Base_239010 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    char data[12];
    void (*callback)();
    unsigned tail;
    void FUN_00234960(const char*);
    void FUN_002349e0(const char*);
};
namespace fight {
class PrintTrack;
template <class T> struct ParamFloatConstRange : Base_239010 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
};
template <class T> struct ParamString : Base_239010 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
};
} // namespace fight
void FUN_00239010() {
    if (!DAT_004e5c2c) {
        Base_239010* params[3];
        void* mem = FUN_0008d690(24);
        if (mem) {
            ((Base_239010*)mem)->FUN_00234960("timeBegin");
            fight::ParamFloatConstRange<fight::PrintTrack>* p =
                new (mem) fight::ParamFloatConstRange<fight::PrintTrack>;
            p->callback = FUN_00238850;
            params[0] = p;
        } else
            params[0] = 0;
        mem = FUN_0008d690(24);
        if (mem) {
            ((Base_239010*)mem)->FUN_002349e0("channel");
            fight::ParamString<fight::PrintTrack>* p = new (mem) fight::ParamString<fight::PrintTrack>;
            p->callback = FUN_00238a80;
            params[1] = p;
        } else
            params[1] = 0;
        mem = FUN_0008d690(24);
        if (mem) {
            ((Base_239010*)mem)->FUN_002349e0("text");
            fight::ParamString<fight::PrintTrack>* p = new (mem) fight::ParamString<fight::PrintTrack>;
            p->callback = FUN_00238ae0;
            params[2] = p;
        } else
            params[2] = 0;
        FUN_002347b0(&DAT_004e5c28, params, 3);
    }
    ++DAT_004e5c2c;
}