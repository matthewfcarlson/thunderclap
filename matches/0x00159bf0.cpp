extern "C" char DAT_00414240[];
void* __cdecl Alloc(unsigned int);
struct HitThrowTrack {
    int vt;
    char p04[8];
    int f0c;
    float f10;
    unsigned char f14;
    char p15[3];
    int f18;
    float f1c;
    int f20;
    int f24;
    int f28;
    void InitTrack();
};
class Factory_159bf0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* vfunc_5();
};
void* Factory_159bf0::vfunc_5() {
    HitThrowTrack* p = (HitThrowTrack*)Alloc(0x2c);
    if (p) {
        p->InitTrack();
        p->f0c = 0;
        p->f18 = 0;
        p->f24 = 0;
        p->f28 = 0;
        p->vt = ((int)DAT_00414240);
        p->f10 = -1.0f;
        p->f14 = 1;
        p->f1c = 30.0f;
        p->f20 = -5;
        return p;
    }
    return 0;
}
