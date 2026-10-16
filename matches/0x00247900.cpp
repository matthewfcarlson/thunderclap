struct Obj {
    char pad[0xb4];
    unsigned char flags;
};
void __cdecl FUN_00247900(Obj* p, volatile unsigned char v) {
    p->flags = p->flags ^ ((v << 1 ^ p->flags) & 2);
}