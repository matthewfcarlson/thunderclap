// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 12/12)
// FUN_0015cfd0 @ 0x0015cfd0
#include "decls/address.h"
#include "decls/data/game/hulkfight/motion.h"
struct Entry_15cfd0 { char pad[8]; unsigned lo, hi; char rest[24]; }; // 40 bytes
struct Source_15cfd0 { char pad[0x44]; Entry_15cfd0* begin; Entry_15cfd0* end; };
struct Pair_15cfd0 { unsigned lo,hi; };
struct Packet_15cfd0 { Pair_15cfd0 first, second; unsigned zero1,zero2; };
struct Receiver_15cfd0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void send(Packet_15cfd0*);
};
void __cdecl FUN_0015cfd0(Source_15cfd0* source, Receiver_15cfd0* receiver) {
 if (!source || !receiver) return;
 if (source->end-source->begin != 2) return;
 Packet_15cfd0 p;
 p.first.lo=source->begin[0].lo; p.first.hi=source->begin[0].hi;
 p.second.lo=source->begin[1].lo; p.second.hi=source->begin[1].hi;
 p.zero1=0; p.zero2=0;
 unsigned lo,hi;
 if (!((*(unsigned*)&DAT_004e11b0) & 1)) {
 (*(unsigned*)&DAT_004e11b0) |= 1;
 unsigned __int64 key=FUN_002672f0("right_leg",0,0);
 lo=(unsigned)key; hi=(unsigned)(key>>32);
 DAT_004e11a8=lo; (*(unsigned*)&DAT_004e11ac)=hi;
 } else {lo=DAT_004e11a8; hi=(*(unsigned*)&DAT_004e11ac);}
 if(p.second.lo==lo && p.second.hi==hi) {p.second=p.first; p.first.lo=lo;p.first.hi=hi;}
 receiver->send(&p);
}
