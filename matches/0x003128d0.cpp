extern "C" char DAT_0043223c[];
void __cdecl thunk(void*);
struct Base {
    void Dtor();
};
struct SkeletonInfo {
    void* vf;
    char pad[12];
    void* member;
    void Free();
};
void SkeletonInfo::Free() {
    vf = (void*)((int)DAT_0043223c);
    if (member)
        thunk((char*)member - 4);
    ((Base*)this)->Dtor();
}
