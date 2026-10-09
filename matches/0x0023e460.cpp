extern void* operator new(unsigned int);
extern void __fastcall InitTrack(void*);
extern int WaitTrackVtable;
struct WaitTrack {
    int* vptr;
    int pad4[2];
    int x, y, z;
};
class TrackFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* Create();
};
void* TrackFactoryTemplate::Create() {
    WaitTrack* p = (WaitTrack*)operator new(0x18);
    if (p) {
        InitTrack(p);
        p->vptr = (int*)&WaitTrackVtable;
        p->x = 0;
        p->y = 0;
        p->z = 0;
        return p;
    }
    return 0;
}