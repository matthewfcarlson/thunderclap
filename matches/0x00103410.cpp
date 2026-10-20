// Same code shape as 0x000ff240 (propagated; names are from that function)
struct Thing_103410 {
    virtual void f0();
    virtual void f1();
};
extern void* handvtable;
class COccupationAgent_103410 {
  public:
    virtual void V0();
    virtual void V1();
    char pad[0x58];
    Thing_103410* mThing;
    void go();
    void cleanup();
};
void COccupationAgent_103410::go() {
    *(void**)this = &handvtable;
    mThing->f1();
    mThing = 0;
    cleanup();
}