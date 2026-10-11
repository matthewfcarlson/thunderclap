extern "C" void _ReadWriteBarrier();
extern void __cdecl ReleaseThing(void*);
struct BoneMatrixList {
    void* vptr;
    char pad[4];
    void* item;
    void Destroy();
};
void BoneMatrixList::Destroy() {
    *(volatile void**)&vptr = (void*)0x42fcd4;
    _ReadWriteBarrier();
    void* p = *(void* volatile*)&item;
    if (p)
        ReleaseThing(p);
    vptr = (void*)0x3f6098;
}
