void* FUN_0008d690(unsigned int);
struct Obj {
    Obj* Init(int x);
};
Obj* FUN_00327f20(int x) {
    Obj* p = (Obj*)FUN_0008d690(0xc8);
    if (p)
        return p->Init(x);
    return 0;
}
