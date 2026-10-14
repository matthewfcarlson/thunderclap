extern "C" char DAT_00414390[];
struct HitFloatTrack {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    int x;
};
struct Initializer_159fa0 {
    void Init();
};
extern void* __cdecl Allocate(unsigned int);
class Factory_159fa0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual HitFloatTrack* Make();
};
HitFloatTrack* Factory_159fa0::Make() {
    HitFloatTrack* p = (HitFloatTrack*)Allocate(0x28);
    if (p) {
        ((Initializer_159fa0*)p)->Init();
        *(int*)((char*)p + 12) = 0;
        *((char*)p + 20) = 0;
        *(int*)((char*)p + 24) = 0;
        *(int*)((char*)p + 32) = 0;
        *(int*)((char*)p + 36) = 0;
        *(void**)p = (void*)((int)DAT_00414390);
        *(unsigned int*)((char*)p + 16) = 0xbf800000;
        *(int*)((char*)p + 28) = -5;
        return p;
    }
    return (HitFloatTrack*)0;
}