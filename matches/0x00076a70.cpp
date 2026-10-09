typedef unsigned int u32;
void* operator_new(unsigned int);
struct Track { void Init(); };
class TrackFactoryTemplate { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual Track* Create(); };
Track* TrackFactoryTemplate::Create() {
    Track* p = (Track*)operator_new(0x54);
    if (p != 0) {
        p->Init();
        *(u32*)p = 0x3fe8d8;
        return p;
    }
    return 0;
}