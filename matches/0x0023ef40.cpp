typedef unsigned int uint;
struct SpawnTrack { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual uint vfunc_10(uint,uint,uint); };
struct Alloc { uint run(uint, SpawnTrack*, uint); };
extern Alloc* FUN_0008d690(uint);
uint SpawnTrack::vfunc_10(uint a, uint b, uint c) {
    Alloc* p = FUN_0008d690(0x58);
    if (p) return p->run(a, this, c);
    return 0;
}