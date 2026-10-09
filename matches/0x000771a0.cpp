struct CMoveAddTrack { unsigned int vf; unsigned int x4; unsigned int x8; unsigned int xc; float x10; float x14; unsigned int x18; void Init(); };
extern void* Alloc(unsigned int);
class TrackFactoryTemplate { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual CMoveAddTrack* v5(); };
CMoveAddTrack* TrackFactoryTemplate::v5() {
  CMoveAddTrack* p = (CMoveAddTrack*)Alloc(0x1c);
  if (p != 0) {
    p->Init();
    p->x10 = 1.0f;
    p->x14 = 1.0f;
    *(unsigned int*)p = 0x3fbc24;
    p->xc = 0;
    p->x18 = 0;
    p->x8 = 1;
    return p;
  }
  return 0;
}