void* __cdecl alloc(unsigned int);
struct Obj_14c420 {
    void* init();
};
void* f() {
    Obj_14c420* p = (Obj_14c420*)alloc(0x30);
    if (p)
        return p->init();
    return 0;
}