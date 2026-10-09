extern void* __cdecl Alloc(unsigned int);
class Track {
  public:
    Track();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual Track* Make();
};
class CWallSlideTrack : public Track {
  public:
    char pad[8];
    int x0c;
    float x10;
    float x14;
    int x18;
    float x1c;
    float x20;
    int x24;
    int x28;
    int x2c;
};
Track* Factory::Make() {
    CWallSlideTrack* p = (CWallSlideTrack*)Alloc(0x30);
    if (p) {
        p->Track::Track();
        p->x0c = 0;
        p->x18 = 0;
        p->x24 = 0;
        p->x28 = 0;
        p->x2c = 0;
        p->x14 = 20.0f;
        p->x1c = 20.0f;
        *(unsigned int*)p = 0x3fc238;
        p->x10 = -1.0f;
        p->x20 = 1.0f;
        return p;
    }
    return 0;
}
