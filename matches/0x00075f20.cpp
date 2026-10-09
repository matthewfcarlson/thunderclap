typedef unsigned int size_t;
void* operator new(size_t);
class CClearCollisionStun {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    char pad[4];
    int a1;
    int a2;
    int a3;
    void Init();
};
class TrackFactoryTemplate {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5();
};
int TrackFactoryTemplate::v5() {
    CClearCollisionStun* p = (CClearCollisionStun*)operator new(0x14);
    if (p) {
        p->Init();
        *(volatile int*)p = 0x3fc1c0;
        p->a2 = 0;
        p->a3 = 0xbf800000;
        p->a1 = 1;
        return (int)p;
    }
    return 0;
}