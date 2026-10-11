extern "C" char DAT_003f6098[];
extern "C" char DAT_0042fcd4[];
extern "C" void _ReadWriteBarrier();
extern void __cdecl ReleaseThing(void*);
struct BoneMatrixList {
    void* vptr;
    char pad[4];
    void* item;
    void Destroy();
};
void BoneMatrixList::Destroy() {
    *(volatile void**)&vptr = (void*)((int)DAT_0042fcd4);
    _ReadWriteBarrier();
    void* p = *(void* volatile*)&item;
    if (p)
        ReleaseThing(p);
    vptr = (void*)((int)DAT_003f6098);
}
