typedef unsigned int u32;
struct ButtonTrack {
    u32 vft;
    u32 q0;
    u32 q1;
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u32 e;
    u32 f;
    void Init();
};
extern void* operator_new(unsigned int);
class TrackFactory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual ButtonTrack* f5();
};
ButtonTrack* TrackFactory::f5() {
    ButtonTrack* p = (ButtonTrack*)operator_new(0x24);
    if (p != 0) {
        p->Init();
        p->a = 0;
        p->c = 0;
        p->d = 0;
        p->e = 0;
        p->f = 0;
        p->vft = 0x40dc74;
        p->b = 0xbf800000;
        return p;
    }
    return 0;
}
