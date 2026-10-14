struct CActorAgent {
    void* vt;
    char pad[0x54];
    void* field58;
    void target();
    void finish();
};
extern int CActorAgent_vftable;
struct Ref_fc610 {
    virtual void A();
    virtual void B();
};
void CActorAgent::target() {
    vt = &CActorAgent_vftable;
    ((Ref_fc610*)field58)->B();
    field58 = 0;
    finish();
}
