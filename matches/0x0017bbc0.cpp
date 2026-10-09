// Same code shape as 0x001571a0 (propagated; names are from that function)
typedef unsigned int u32;
extern int RTTI1, RTTI2;
struct HitPushbackTrack { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual u32 v10(u32,u32,u32); };
struct Result { u32 setup(HitPushbackTrack*, u32); };
extern int check(void*, int, int*, int*, int);
extern Result* alloc(int);
u32 HitPushbackTrack::v10(u32 a,u32 b,u32 c) { if (check((void*)c,0,&RTTI1,&RTTI2,0)) { Result* p=alloc(0x44); if(p) return p->setup(this,c); } return 0; }