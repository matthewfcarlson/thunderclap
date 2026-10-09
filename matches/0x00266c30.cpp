struct C {
    char pad[0x280];
    int idx;
};
int __fastcall FUN_00266c30(C* p) {
    return *(int*)((char*)p + ((p->idx + 8) << 4));
}