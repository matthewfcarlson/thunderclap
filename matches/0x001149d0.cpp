extern "C" void* __cdecl Alloc(unsigned int);
class AIHistoryCountTrack {
  public:
    int vptr;
    char pad[8];
    int member;
    AIHistoryCountTrack();
};
class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual AIHistoryCountTrack* Create();
};
AIHistoryCountTrack* Factory::Create() {
    AIHistoryCountTrack* p = (AIHistoryCountTrack*)Alloc(16);
    if (p) {
        p->AIHistoryCountTrack::AIHistoryCountTrack();
        p->vptr = 0x40dbe4;
        p->member = 0;
        return p;
    }
    return 0;
}