// Same code shape as 0x0024e6f0 (propagated; names are from that function)
typedef unsigned int u32_250ba0;
extern void* __cdecl Acquire(void*);
extern char gPool_250ba0;
extern const char gName_250ba0[];
extern int gVtable_250ba0;
class audio_SeqEventNestTrackType_250ba0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void* f3();
};
class NameObj_250ba0 {
  public:
    void set(const char*, int);
};
class NestTrack_250ba0 {
  public:
    u32_250ba0 vf;
    char pad[4];
    NameObj_250ba0 name;
    void init();
};
void* audio_SeqEventNestTrackType_250ba0::f3() {
    NestTrack_250ba0* p = (NestTrack_250ba0*)Acquire(&gPool_250ba0);
    if (p) {
        p->init();
        p->vf = (u32_250ba0)&gVtable_250ba0;
        p->name.set(gName_250ba0, 2);
        return p;
    }
    return 0;
}