struct I_2b6910 {
    virtual void A();
    virtual void B();
};
extern void* shadowVtable;
extern void* refVtable_2b6910;
struct ShadowMeshBufferLoader_2b6910 {
    void* vptr;
    char pad[16];
    I_2b6910* member;
    void F();
};
void ShadowMeshBufferLoader_2b6910::F() {
    vptr = &shadowVtable;
    member->B();
    vptr = &refVtable_2b6910;
}