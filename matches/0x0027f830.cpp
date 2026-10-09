typedef unsigned int u32;
struct CMotionTrailQueue {
    u32 vtable;
    char pad[0x58];
    u32 field5c;
    void Run();
    void Finish();
};
extern void __cdecl thunk_FUN_00267090(u32);
void CMotionTrailQueue::Finish() {
    u32 x = field5c;
    vtable = 0x42c48c;
    thunk_FUN_00267090(x);
    Run();
}