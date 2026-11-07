#include "gen/owners.h"
typedef unsigned __int64 U64;
extern "C" U64 __cdecl FUN_002672f0(const char*, int, int) throw();
struct FUN_00240060 {
    int a, b, c;
    ~FUN_00240060() throw();
};
struct FUN_002605e0 {
    FUN_002605e0(FUN_00240060*, const U64*, int, int) throw();
    virtual void f();
};
struct SeqEventCrossFadeType_2555c0 : FUN_002605e0 {
    SeqEventCrossFadeType_2555c0() throw();
    virtual void f();
};
SeqEventCrossFadeType_2555c0::SeqEventCrossFadeType_2555c0() throw() : FUN_002605e0(((FUN_00240060 *)((owners::String_23fc40 *)&(FUN_00240060()))->FUN_0023fc40("X-Fade", (hulk_intptr)0)), &(U64 const&)(FUN_002672f0("SeqEventCrossFade", 0, 0)), 0x34, 4) {}