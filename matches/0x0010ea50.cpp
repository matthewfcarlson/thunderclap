extern "C" void _ReadWriteBarrier();
extern void* g_vftable_10ea50[];
class Ref_10ea50 {
  public:
    virtual void F0();
    virtual void Release();
};
class Track_10ea50 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();
struct Sub_10ea50 {
    char c;
};
void __fastcall SubFini(Sub_10ea50*) throw();
void __fastcall SubFini2(Sub_10ea50*) throw();
void __fastcall SubFini3(Sub_10ea50*) throw();
class SemaphoreClearTrack_10ea50 : public Track_10ea50 {
  public:
    char p18[20];
    Sub_10ea50 s18;
    SemaphoreClearTrack_10ea50* f(unsigned char fl);
};
SemaphoreClearTrack_10ea50* SemaphoreClearTrack_10ea50::f(unsigned char fl) {
    vptr = g_vftable_10ea50;
    SubFini(&s18);
    Fin();
    if (fl & 1)
        Free(this);
    return this;
}
