extern "C" void* __cdecl FUN_0008d690(unsigned int);
class BaseTrack {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    BaseTrack();
};
class StatTrack : public BaseTrack {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual StatTrack* Create();
    StatTrack();
    char pad[8];
    int a;
    int b;
};
StatTrack::StatTrack() : BaseTrack(), a(0), b(0) {}
StatTrack* StatTrack::Create() {
    StatTrack* p = (StatTrack*)FUN_0008d690(0x14);
    if (p) {
        p->StatTrack::StatTrack();
        return p;
    }
    return 0;
}
