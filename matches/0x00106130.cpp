extern "C" char DAT_0040d564[];
typedef unsigned int u32_106130;
void __cdecl thunk_FUN_00267090(u32_106130);
struct CPatrolPath {
    void* vptr;
    char pad[0x0c];
    u32_106130 m10;
    u32_106130 m14;
    void finish();
    void target();
};
void CPatrolPath::target() {
    vptr = (void*)((int)DAT_0040d564);
    u32_106130 x = m10;
    thunk_FUN_00267090(x);
    m14 = 0;
    finish();
}