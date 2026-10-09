typedef unsigned char u8;
extern int spawn_vftable;
struct A { void init(); }; struct B { void init(); }; struct C { void init(); };
namespace fight {
struct Track { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); };
struct SpawnTrack : Track { char pad[0x20-sizeof(Track)]; SpawnTrack* vfunc_5(u8); };
}
fight::SpawnTrack* fight::SpawnTrack::vfunc_5(u8 flag) {
 *(int*)this = (int)&spawn_vftable;
 ((A*)((char*)this+0x20))->init();
 ((B*)((char*)this+0x14))->init();
 ((C*)this)->init();
 if (flag & 1) { extern void del(fight::SpawnTrack*); del(this); }
 return this;
}