struct CStaticAllocator {
    void* vf;
    char pad[0xC];
    int m10;
    int m14;
    void Reset();
};
void thunk_FUN_00267090(int);
void CStaticAllocator::Reset() {
    vf = (void*)0x400c1c;
    thunk_FUN_00267090(m14);
    thunk_FUN_00267090(m10);
}