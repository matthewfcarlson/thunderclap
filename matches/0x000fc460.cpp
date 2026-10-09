struct IRefCount {
    virtual void f0();
    virtual void Release();
};
extern int g_CAgentVtbl;
extern int g_IRefCountVtbl;
struct CAgent {
    void* vptr;
    char pad[0x10];
    IRefCount* refs[16];
};
void __fastcall FUN_000fc460(CAgent* self) {
    self->vptr = &g_CAgentVtbl;
    for (int i = 0; i < 16; ++i) {
        IRefCount* p = self->refs[i];
        if (p) {
            p->Release();
            self->refs[i] = 0;
        }
    }
    self->vptr = &g_IRefCountVtbl;
}
