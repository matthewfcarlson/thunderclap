// Same code shape as 0x0024e6f0 (propagated; names are from that function)
typedef unsigned int u32_250310;
extern void* __cdecl Acquire(void*);
extern char gPool_250310;
extern const char gName_250310[];
extern int gVtable_250310;
class audio_SeqEventNestTrackType_250310 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void* f3();
};
class NameObj_250310 {
  public:
    void set(const char*, int);
};
class NestTrack_250310 {
  public:
    u32_250310 vf;
    char pad[4];
    NameObj_250310 name;
    void init();
};
void* audio_SeqEventNestTrackType_250310::f3() {
    NestTrack_250310* p = (NestTrack_250310*)Acquire(&gPool_250310);
    if (p) {
        p->init();
        p->vf = (u32_250310)&gVtable_250310;
        p->name.set(gName_250310, 2);
        return p;
    }
    return 0;
}