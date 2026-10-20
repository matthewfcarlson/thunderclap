// Same code shape as 0x000fc610 (propagated; names are from that function)
struct CCharacterAgent_fc630 {
    void* vt;
    char pad[0x54];
    void* field58;
    void target();
    void finish();
};
extern int CCharacterAgent_fc630_vftable;
struct Ref_fc630 {
    virtual void A();
    virtual void B();
};
void CCharacterAgent_fc630::target() {
    vt = &CCharacterAgent_fc630_vftable;
    ((Ref_fc630*)field58)->B();
    field58 = 0;
    finish();
}
