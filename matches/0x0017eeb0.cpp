class Sub { public: void Init(); };
class RestPoseTrack { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); int a; int b; int c; float d; char pad[4]; Sub sub; int x; int y; int z; int q; void Init(); };
class Factory { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void* Make(); };
extern void* __cdecl Alloc(unsigned int);
void* Factory::Make() {
    RestPoseTrack* p = (RestPoseTrack*)Alloc(0x30);
    if (p) {
        p->Init(); *(int*)p = 0x4178f8; p->c = 0; p->d = -1.0f;
        p->sub.Init(); p->y = -5; p->z = 0; p->q = 0;
        return p;
    }
    return 0;
}