struct Thing_ff240 {
    virtual void f0();
    virtual void f1();
};
extern void* handvtable;
class CHand2HandAgent {
  public:
    virtual void V0();
    virtual void V1();
    char pad[0x58];
    Thing_ff240* mThing;
    void go();
    void cleanup();
};
void CHand2HandAgent::go() {
    *(void**)this = &handvtable;
    mThing->f1();
    mThing = 0;
    cleanup();
}