struct C_266c40 {
    char pad[0x280];
    int count;
};
int __fastcall target(C_266c40* p) {
    return *(int*)((char*)p + 0x84 + p->count * 0x10) - 0xc;
}