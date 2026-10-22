extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1832a0[];
class Ref_1832a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Track_1832a0 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();
struct Sub_1832a0 {
    char c;
};
void __fastcall SubFini(Sub_1832a0*) throw();
void __fastcall SubFini2(Sub_1832a0*) throw();
class PropThrowTrack_1832a0 : public Track_1832a0 {
  public:
    char p68[100];
    Sub_1832a0 s68;
    char p78[15];
    Sub_1832a0 s78;
    PropThrowTrack_1832a0* f(unsigned char fl);
};
PropThrowTrack_1832a0* PropThrowTrack_1832a0::f(unsigned char fl) {
    vptr = g_vftable_1832a0;
    SubFini(&s78);
    SubFini2(&s68);
    Fin();
    if (fl & 1)
        Free(this);
    return this;
}
