struct C {
    char pad[0x280];
    int count;
};
int __fastcall target(C* p) {
    return *(int*)((char*)p + 0x84 + p->count * 0x10) - 0xc;
}