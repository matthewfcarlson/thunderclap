struct Obj {
    char pad[0xb4];
    unsigned char flag : 1;
};
extern "C" unsigned char __cdecl FUN_002478f0(Obj* p) {
    return p->flag;
}
