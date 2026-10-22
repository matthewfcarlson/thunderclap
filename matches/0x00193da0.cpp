extern "C" void _ReadWriteBarrier();
extern void* g_vftable_193da0[];
extern void* g_vftable2[];
class Ref_193da0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Track_193da0 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();

struct Sub_193da0 {
    char c;
};
void __fastcall SubFini(Sub_193da0*) throw();
void __fastcall SubFini2(Sub_193da0*) throw();
class FireProjectileTrack_193da0 : public Track_193da0 {
  public:
    char p[0x14];
    Sub_193da0 s18;
    char p1[0x1f];
    Sub_193da0 s38;
    char p2[0x4f];
    Sub_193da0 s88;
    char p3[0x13];
    Sub_193da0 s9c;
    char p4[0xb];
    Sub_193da0 sa8;
    ~FireProjectileTrack_193da0() throw();
};
FireProjectileTrack_193da0::~FireProjectileTrack_193da0() throw() {
    vptr = g_vftable_193da0;
    SubFini2(&sa8);
    SubFini2(&s9c);
    SubFini(&s88);
    SubFini(&s38);
    SubFini(&s18);
    Fin();
}
