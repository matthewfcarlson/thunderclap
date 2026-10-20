// Same code shape as 0x000ff240 (propagated; names are from that function)
struct Thing_107000 {
    virtual void f0();
    virtual void f1();
};
extern void* handvtable;
class CRangedAgent_107000 {
  public:
    virtual void V0();
    virtual void V1();
    char pad[0x58];
    Thing_107000* mThing;
    void go();
    void cleanup();
};
void CRangedAgent_107000::go() {
    *(void**)this = &handvtable;
    mThing->f1();
    mThing = 0;
    cleanup();
}