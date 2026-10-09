typedef unsigned int u32;
extern void* Alloc(unsigned int);
class Builder { public: u32 Run(u32,u32,u32,u32,void*,u32,u32); };
class Track { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); };
class SequenceTrack : public Track {
public:
  char pad[8];
  u32 field0c;
  char pad10[8];
  u32 field18;
  char pad1c[4];
  u32 vfunc_10(u32, u32, u32);
};
u32 SequenceTrack::vfunc_10(u32 a, u32 b, u32 c) {
  Builder* p = (Builder*)Alloc(0x3c);
  if (p) {
    u32 x = field0c;
    return p->Run(a, (u32)this, x, field18, &pad1c, b, c);
  }
  return 0;
}
