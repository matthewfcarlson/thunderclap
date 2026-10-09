class CIntangibleToActorsTrack {
  public:
    void Init();
    int* vptr;
    char pad[4];
    int one;
    int zero;
    float minus;
};
class TrackFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual CIntangibleToActorsTrack* vfunc_5();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int trackVtable;
CIntangibleToActorsTrack* TrackFactoryTemplate::vfunc_5() {
    CIntangibleToActorsTrack* p = (CIntangibleToActorsTrack*)FUN_0008d690(0x14);
    if (p) {
        p->Init();
        p->vptr = &trackVtable;
        p->zero = 0;
        p->minus = -1.0f;
        p->one = 1;
        return p;
    }
    return 0;
}