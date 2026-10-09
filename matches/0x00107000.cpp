// Same code shape as 0x000ff240 (propagated; names are from that function)
struct Thing {
    virtual void f0();
    virtual void f1();
};
extern void* handvtable;
class CHand2HandAgent {
  public:
    virtual void V0();
    virtual void V1();
    char pad[0x58];
    Thing* mThing;
    void go();
    void cleanup();
};
void CHand2HandAgent::go() {
    *(void**)this = &handvtable;
    mThing->f1();
    mThing = 0;
    cleanup();
}