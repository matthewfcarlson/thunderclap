struct C_266c30 {
    char pad[0x280];
    int idx;
};
int __fastcall FUN_00266c30(C_266c30* p) {
    return *(int*)((char*)p + ((p->idx + 8) << 4));
}