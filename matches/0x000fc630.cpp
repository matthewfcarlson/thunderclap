// Same code shape as 0x000fc610 (propagated; names are from that function)
struct CActorAgent {
    void* vt;
    char pad[0x54];
    void* field58;
    void target();
    void finish();
};
extern int CActorAgent_vftable;
struct Ref {
    virtual void A();
    virtual void B();
};
void CActorAgent::target() {
    vt = &CActorAgent_vftable;
    ((Ref*)field58)->B();
    field58 = 0;
    finish();
}
