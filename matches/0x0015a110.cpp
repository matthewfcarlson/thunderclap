struct HitPushbackAddTrack { unsigned int vt; char pad[4]; int mTwo; int mZero; float mOne; void Init(); };
extern void* __cdecl Alloc(unsigned int);
class TrackFactoryTemplate { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual HitPushbackAddTrack* Create(); };
HitPushbackAddTrack* TrackFactoryTemplate::Create() {
    HitPushbackAddTrack* p = (HitPushbackAddTrack*)Alloc(0x14);
    if (p) {
        p->Init();
        p->vt = 0x4143f0;
        p->mZero = 0;
        p->mOne = 1.0f;
        p->mTwo = 1;
        return p;
    }
    return 0;
}