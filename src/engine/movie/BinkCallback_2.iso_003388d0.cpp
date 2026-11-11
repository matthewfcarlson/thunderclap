// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x003388d0 FUN_003388d0 (245 B): matches/0x003388d0.cpp [isolated: lost its match in the tree (call sequence differs)]
// sym: ??0O_3388d0@fn_f269dc74@@QAE@HH@Z
#include "gen/owners.h"
#include "decls/data/engine/movie.h"
namespace fn_f269dc74 {} using namespace fn_f269dc74;
namespace fn_f269dc74 {

struct T3 {
    char c[3];
};
void* __cdecl FUN_0008d690(hulk_uintptr n) throw();
class O_3388d0 {
  public:
    void* vptr;
    hulk_intptr m4, m8, mc, m10, m14, m18;
    char c1c;
    char pad1[0x41c - 0x1d];
    char c41c;
    char pad2[0x81c - 0x41d];
    int m81c;
    int pad3;
    int m824;
    char c828;
    char pad4[3];
    int m82c;
    char c830, c831;
    T3 s832;
    short m836;
    char pad5[2];
    char b83a[0x85a - 0x83a];
    T3 s85a;
    char pad6[5];
    T3 s862;
    char pad7[5];
    T3 s86a;
    char pad8[5];
    char c872;
    O_3388d0(hulk_intptr a, int b) throw();
    void F1_00338640(char* p, const unsigned short* w) throw();
};
O_3388d0::O_3388d0(hulk_intptr a, int b) throw() {
    m8 = b;
    vptr = ((void**)&DAT_00434630);
    m14 = (hulk_intptr)FUN_0008d690(b + 0x40);
    m18 = (m14 + 0x40) & ~0x3f;
    m4 = a;
    mc = 0;
    m10 = 0;
    s832 = *(const T3*)"\t ";
    m836 = 0xd;
    s85a = *(const T3*)"//";
    s862 = *(const T3*)"/*";
    s86a = *(const T3*)"/*";
    F1_00338640(b83a, (const unsigned short*)L"()[]{}=;");
    c872 = 0;
    c1c = 0;
    c41c = 0;
    ((owners::C_3388c0 *)this)->FUN_003388c0();
    m824 = 0;
    c828 = 0;
    m82c = 0;
    c830 = 0;
    c831 = 0;
    m81c = 0;
}
} // namespace fn_f269dc74

