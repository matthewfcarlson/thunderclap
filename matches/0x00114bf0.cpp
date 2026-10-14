extern "C" char DAT_0040dc74[];
typedef unsigned int u32_114bf0;
struct ButtonTrack {
    u32_114bf0 vft;
    u32_114bf0 q0;
    u32_114bf0 q1;
    u32_114bf0 a;
    u32_114bf0 b;
    u32_114bf0 c;
    u32_114bf0 d;
    u32_114bf0 e;
    u32_114bf0 f;
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
        p->vft = ((int)DAT_0040dc74);
        p->b = 0xbf800000;
        return p;
    }
    return 0;
}
