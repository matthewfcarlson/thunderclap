extern "C" char DAT_00411be8[];
extern "C" void* __cdecl Alloc(unsigned int);
class Track {
  public:
    int vptr;
    int pad;
    int m2;
    int m3;
    float m4;
    int m5;
    void Init();
};
class GrappleHoverTrack : public Track {};
class Factory_1394f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual GrappleHoverTrack* v5();
};
GrappleHoverTrack* Factory_1394f0::v5() {
    GrappleHoverTrack* p = (GrappleHoverTrack*)Alloc(0x18);
    if (p) {
        p->Init();
        p->vptr = ((int)DAT_00411be8);
        p->m3 = 0;
        p->m4 = -1.0f;
        p->m5 = 0;
        p->m2 = 1;
        return p;
    }
    return (GrappleHoverTrack*)0;
}