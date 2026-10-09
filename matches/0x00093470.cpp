struct CUnlockable {
    virtual CUnlockable* vfunc_0(unsigned char);
    char pad[0x14];
    void* m18;
    char pad2[0x24];
};
struct CUnlockableMove : CUnlockable {
    virtual CUnlockableMove* vfunc_0(unsigned char);
};
struct Helper {
    void run();
};
extern void* vtMove;
extern void* vtBase;
void thunk_FUN_00267090(void*);
void __cdecl FreeThis(void*);
CUnlockableMove* CUnlockableMove::vfunc_0(unsigned char param_2) {
    *(void**)this = &vtMove;
    Helper* h = (Helper*)((char*)this + 0x40);
    h->run();
    h = (Helper*)((char*)this + 0x38);
    h->run();
    *(void**)this = &vtBase;
    if (m18) {
        thunk_FUN_00267090(m18);
        m18 = 0;
    }
    h = (Helper*)((char*)this + 0x10);
    h->run();
    if (param_2 & 1)
        FreeThis(this);
    return this;
}
