typedef unsigned int u32;
void __cdecl thunk_FUN_00267090(u32);
struct CPatrolPath {
    void* vptr;
    char pad[0x0c];
    u32 m10;
    u32 m14;
    void finish();
    void target();
};
void CPatrolPath::target() {
    vptr = (void*)0x40d564;
    u32 x = m10;
    thunk_FUN_00267090(x);
    m14 = 0;
    finish();
}