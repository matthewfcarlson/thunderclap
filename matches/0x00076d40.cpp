class CInvincibleTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    int x;
    int one;
    int zero;
    int neg;
    int tail;
    void Init();
};
class TrackFactory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual CInvincibleTrack* vfunc_5();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern int cvtable;
CInvincibleTrack* TrackFactory::vfunc_5() {
    CInvincibleTrack* p = (CInvincibleTrack*)FUN_0008d690(0x18);
    CInvincibleTrack* r;
    if (p) {
        p->Init();
        *(int*)p = (int)&cvtable;
        p->zero = 0;
        p->neg = (int)0xbf800000;
        p->tail = 0;
        p->one = 1;
        r = p;
    } else
        r = 0;
    return r;
}