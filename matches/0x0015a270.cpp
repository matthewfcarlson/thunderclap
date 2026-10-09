class HitDamageTrack {
  public:
    virtual void f0();
    char pad[8];
    int x;
    float y;
    void init();
};
extern void* __cdecl operator new(unsigned int);
class Factory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual HitDamageTrack* f5();
};
HitDamageTrack* Factory::f5() {
    HitDamageTrack* p = (HitDamageTrack*)operator new(0x14);
    if (p) {
        p->init();
        *(int*)p = 0x414450;
        p->x = 0;
        p->y = 1.0f;
        return p;
    }
    return 0;
}