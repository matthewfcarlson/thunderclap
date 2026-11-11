// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000d6f00..0x000d7010 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff8b4e88 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff8b4e88 {} using namespace fn_ff8b4e88;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_ff8b4e88 {
struct B_d6f10 {
};
struct C_d6f10 {
    void Fny_000cb870(int);
};
struct A_d6f10 {
    int pad;
    B_d6f10* b;
    C_d6f10* c;
    void run(int);
};
class Thing_d6f30 {
  public:
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void act(void*);
};
class Owner_d6f30 {
  public:
    char pad[4];
    Thing_d6f30* first;
    Thing_d6f30* second;
    void Run(int a, void* b);
};
typedef unsigned int uint_d6f50;
struct Obj_d6f50 {
    char pad[4];
    void* p4;
    void* p8;
    void* pc;
};
struct Helper_d6f50 {
    uint_d6f50 Get_000cae50();
};
class A_d6f80 {
  public:
    char pad[8];
    char* p;
    void Set(unsigned char b);
};
struct Inner_d6f90 {
    char pad[4];
    char value;
};
struct Owner_d6f90 {
    char pad[4];
    Inner_d6f90* p;

    void Set(char c);
};
struct Entry_d6fb0 {
    char pad[4];
    unsigned char value;
};
struct Holder_d6fb0 {
    char pad[4];
    Entry_d6fb0* a;
    Entry_d6fb0* b;
    Entry_d6fb0* c;
    void set(unsigned char x);
};

} // namespace fn_ff8b4e88

// 0x000d6f00 FUN_000d6f00 (10 B): matches/0x000d6f00.cpp
// sym: ?FUN_000d6f00@A_d6f00@owners@@QAEXH@Z
// Same code shape as 0x00098e20 (propagated; names are from that function)
void owners::A_d6f00::FUN_000d6f00(int x) {
    value = x;
}

namespace fn_ff8b4e88 {

// 0x000d6f10 FUN_000d6f10 (31 B): matches/0x000d6f10.cpp
// sym: ?run@A_d6f10@fn_ff8b4e88@@QAEXH@Z
void A_d6f10::run(int v) {
    ((owners::Obj_d4370 *)b)->FUN_000d4370((hulk_intptr)v);
    c->Fny_000cb870(v);
}


// 0x000d6f30 FUN_000d6f30 (31 B): matches/0x000d6f30.cpp
// sym: ?Run@Owner_d6f30@fn_ff8b4e88@@QAEXHPAX@Z
void Owner_d6f30::Run(int a, void* b) {
    second->act(b);
    first->act(b);
}


// 0x000d6f50 FUN_000d6f50 (42 B): matches/0x000d6f50.cpp
// sym: @FUN_000d6f50@4
extern "C" uint_d6f50 __fastcall FUN_000d6f50(Obj_d6f50* self) {
    uint_d6f50 v = ((Helper_d6f50*)self->p8)->Get_000cae50();
    v &= 0xffffff7f;
    if (self->p4)
        v |= 0x80;
    if (self->pc)
        v |= 0x100;
    return v;
}


// 0x000d6f80 FUN_000d6f80 (13 B): matches/0x000d6f80.cpp
// sym: ?Set@A_d6f80@fn_ff8b4e88@@QAEXE@Z
void A_d6f80::Set(unsigned char b) {
    p[4] = (char)b;
}


// 0x000d6f90 FUN_000d6f90 (13 B): matches/0x000d6f90.cpp
// sym: ?Set@Owner_d6f90@fn_ff8b4e88@@QAEXD@Z
void Owner_d6f90::Set(char c) {
    Inner_d6f90* q = p;
    q->value = c;
}


// 0x000d6fb0 FUN_000d6fb0 (25 B): matches/0x000d6fb0.cpp
// sym: ?set@Holder_d6fb0@fn_ff8b4e88@@QAEXE@Z
void Holder_d6fb0::set(unsigned char x) {
    b->value = x;
    a->value = x;
    c->value = x;
}

} // namespace fn_ff8b4e88

// 0x000d6fd0 FUN_000d6fd0 (7 B): matches/0x000d6fd0.cpp
// sym: ?FUN_000d6fd0@Thing_d6fd0@owners@@QAEDXZ
char owners::Thing_d6fd0::FUN_000d6fd0() {
    return p[4];
}

