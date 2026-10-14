// Same code shape as 0x0014c420 (propagated; names are from that function)
void* __cdecl alloc(unsigned int);
struct Obj_18c820 {
    void* init();
};
void* f() {
    Obj_18c820* p = (Obj_18c820*)alloc(0x30);
    if (p)
        return p->init();
    return 0;
}