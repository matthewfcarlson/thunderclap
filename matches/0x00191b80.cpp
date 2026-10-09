class SimulationTrack {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    char pad[8];
    int x;
    float y;
    SimulationTrack();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual SimulationTrack* vfunc_5();
};
SimulationTrack* Factory::vfunc_5() {
    SimulationTrack* p = (SimulationTrack*)FUN_0008d690(0x14);
    if (p) {
        p->SimulationTrack::SimulationTrack();
        *(int*)p = 0x41af08;
        p->x = 0;
        p->y = -1.0f;
        return p;
    }
    return 0;
}