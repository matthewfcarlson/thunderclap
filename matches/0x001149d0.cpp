extern "C" char DAT_0040dbe4[];
extern "C" void* __cdecl Alloc(unsigned int);
class AIHistoryCountTrack {
  public:
    int vptr;
    char pad[8];
    int member;
    AIHistoryCountTrack();
};
class Factory_1149d0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual AIHistoryCountTrack* Create();
};
AIHistoryCountTrack* Factory_1149d0::Create() {
    AIHistoryCountTrack* p = (AIHistoryCountTrack*)Alloc(16);
    if (p) {
        p->AIHistoryCountTrack::AIHistoryCountTrack();
        p->vptr = ((int)DAT_0040dbe4);
        p->member = 0;
        return p;
    }
    return 0;
}