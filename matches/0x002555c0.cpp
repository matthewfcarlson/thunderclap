#include "gen/owners.h"
typedef unsigned __int64 U64;
extern "C" U64 __cdecl FUN_002672f0(const char*, int, int) throw();
struct Tmp {
    int a, b, c;
    ~Tmp() throw();
};
struct SeqEventType_2555c0 {
    SeqEventType_2555c0(Tmp*, const U64*, int, int) throw();
    virtual void f();
};
struct SeqEventCrossFadeType_2555c0 : SeqEventType_2555c0 {
    SeqEventCrossFadeType_2555c0() throw();
    virtual void f();
};
SeqEventCrossFadeType_2555c0::SeqEventCrossFadeType_2555c0() throw() : SeqEventType_2555c0(((Tmp *)((owners::String_23fc40 *)&(Tmp()))->FUN_0023fc40("X-Fade", (hulk_intptr)0)), &(U64 const&)(FUN_002672f0("SeqEventCrossFade", 0, 0)), 0x34, 4) {}