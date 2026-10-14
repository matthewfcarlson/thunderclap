extern "C" char DAT_003fc184[];
struct Sub_779d0 {
    void subinit();
};
struct CAIHintTrack {
    char pad[32];
    void init();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class TrackFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* vfunc_5();
};
void* TrackFactoryTemplate::vfunc_5() {
    CAIHintTrack* p = (CAIHintTrack*)FUN_0008d690(0x20);
    if (p) {
        p->init();
        *(unsigned int*)p = ((int)DAT_003fc184);
        *(unsigned int*)((char*)p + 0xc) = 0;
        *(unsigned int*)((char*)p + 0x10) = 0xbf800000;
        ((Sub_779d0*)((char*)p + 0x18))->subinit();
        *(unsigned int*)((char*)p + 8) = 1;
        return p;
    }
    return 0;
}
