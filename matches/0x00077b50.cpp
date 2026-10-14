typedef unsigned int u32_77b50;
extern "C" void* __cdecl alloc(unsigned int);
extern u32_77b50 track_vftable;
struct CGrappleKeyPoseTrack {
    u32_77b50 vf;
    void init();
};
struct Factory_77b50 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual CGrappleKeyPoseTrack* create();
};
CGrappleKeyPoseTrack* Factory_77b50::create() {
    CGrappleKeyPoseTrack* p = (CGrappleKeyPoseTrack*)alloc(0x78);
    if (p) {
        p->init();
        p->vf = (u32_77b50)&track_vftable;
        return p;
    }
    return 0;
}
