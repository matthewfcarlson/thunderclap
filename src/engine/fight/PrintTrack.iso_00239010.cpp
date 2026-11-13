// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00238850..0x002393a0 (kind game, layer engine, confidence high), dominant class fight::PrintTrack
#include "tree_prelude.h"


// 0x00239010 FUN_00239010 (213 B): matches/0x00239010.cpp [isolated: compile error C2084: function 'void *operator new(size_t,void *)' already has a body]
// sym: ?FUN_00239010@fn_f2f82934@@YAXXZ
#include "gen/owners.h"
#include "decls/data/engine/fight.h"
namespace fn_f2f82934 {} using namespace fn_f2f82934;
namespace fn_f2f82934 {

void* __cdecl FUN_0008d690(unsigned);

} // namespace fn_f2f82934
inline void* __cdecl operator new(size_t, void* memory) {
    return memory;
}
namespace fn_f2f82934 {

void __cdecl FUN_002347b0(void*, void*, int);
char SetTimeBegin_00238850(void*, int); /* (unb4) as defined; address taken only */
bool SetChannel_00238a80(void*, void*); /* (unb4) as defined; address taken only */
bool SetText_00238ae0(void*, void*); /* (unb4) as defined; address taken only */
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
        void* mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<fight::PrintTrack>));
        if (mem) {
            ((Base_239010*)mem)->FUN_00234960("timeBegin");
            fight::ParamFloatConstRange<fight::PrintTrack>* p =
                new (mem) fight::ParamFloatConstRange<fight::PrintTrack>;
            p->callback = (void (*)())SetTimeBegin_00238850;
            params[0] = p;
        } else
            params[0] = 0;
        mem = FUN_0008d690((int)sizeof(fight::ParamString<fight::PrintTrack>));
        if (mem) {
            ((Base_239010*)mem)->FUN_002349e0("channel");
            fight::ParamString<fight::PrintTrack>* p = new (mem) fight::ParamString<fight::PrintTrack>;
            p->callback = (void (*)())SetChannel_00238a80;
            params[1] = p;
        } else
            params[1] = 0;
        mem = FUN_0008d690((int)sizeof(fight::ParamString<fight::PrintTrack>));
        if (mem) {
            ((Base_239010*)mem)->FUN_002349e0("text");
            fight::ParamString<fight::PrintTrack>* p = new (mem) fight::ParamString<fight::PrintTrack>;
            p->callback = (void (*)())SetText_00238ae0;
            params[2] = p;
        } else
            params[2] = 0;
        FUN_002347b0(&DAT_004e5c28, params, 3);
    }
    ++DAT_004e5c2c;
}
} // namespace fn_f2f82934

