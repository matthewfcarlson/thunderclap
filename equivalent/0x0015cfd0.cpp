// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 12/12)
// FUN_0015cfd0 @ 0x0015cfd0
struct Entry { char pad[8]; unsigned lo, hi; char rest[24]; }; // 40 bytes
struct Source { char pad[0x44]; Entry* begin; Entry* end; };
struct Pair { unsigned lo,hi; };
struct Packet { Pair first, second; unsigned zero1,zero2; };
struct Receiver {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void send(Packet*);
};
extern unsigned DAT_004e11a8, DAT_004e11ac, DAT_004e11b0;
extern unsigned __int64 __cdecl FUN_002672f0(const char*,int,int);
void __cdecl FUN_0015cfd0(Source* source, Receiver* receiver) {
 if (!source || !receiver) return;
 if (source->end-source->begin != 2) return;
 Packet p;
 p.first.lo=source->begin[0].lo; p.first.hi=source->begin[0].hi;
 p.second.lo=source->begin[1].lo; p.second.hi=source->begin[1].hi;
 p.zero1=0; p.zero2=0;
 unsigned lo,hi;
 if (!(DAT_004e11b0 & 1)) {
 DAT_004e11b0 |= 1;
 unsigned __int64 key=FUN_002672f0("right_leg",0,0);
 lo=(unsigned)key; hi=(unsigned)(key>>32);
 DAT_004e11a8=lo; DAT_004e11ac=hi;
 } else {lo=DAT_004e11a8; hi=DAT_004e11ac;}
 if(p.second.lo==lo && p.second.hi==hi) {p.second=p.first; p.first.lo=lo;p.first.hi=hi;}
 receiver->send(&p);
}
