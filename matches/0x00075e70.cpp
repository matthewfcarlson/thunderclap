extern void* __cdecl Alloc(unsigned int);
extern int shakeVtable;
class CCameraShakeTrack {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[4];
    int flag;
    int x;
    int y;
    int z;
    int w;
    void Init();
};
class Factory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual CCameraShakeTrack* v5();
};
CCameraShakeTrack* Factory::v5() {
    CCameraShakeTrack* p = (CCameraShakeTrack*)Alloc(0x1c);
    if (p) {
        p->Init();
        p->x = 0;
        p->y = 0;
        p->z = 0;
        p->w = 0;
        *(unsigned long*)p = (unsigned long)&shakeVtable;
        p->flag = 1;
        return p;
    }
    return 0;
}