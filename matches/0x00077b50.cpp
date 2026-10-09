typedef unsigned int u32;
extern "C" void* __cdecl alloc(unsigned int);
extern u32 track_vftable;
struct CGrappleKeyPoseTrack { u32 vf; void init(); };
struct Factory { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual CGrappleKeyPoseTrack* create(); };
CGrappleKeyPoseTrack* Factory::create() {
    CGrappleKeyPoseTrack* p = (CGrappleKeyPoseTrack*)alloc(0x78);
    if (p) {
        p->init();
        p->vf = (u32)&track_vftable;
        return p;
    }
    return 0;
}
